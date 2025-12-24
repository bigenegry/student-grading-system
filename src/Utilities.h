#ifndef UTILITIES_H
#define UTILITIES_H

#include "Person.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <list>

// Sorting comparator (Surname then Name)
inline bool bySurnameThenName(const Person& a, const Person& b) {
    if (a.getLastName() != b.getLastName()) return a.getLastName() < b.getLastName();
    return a.getFirstName() < b.getFirstName();
}

// Parse one line: Name Surname HW... Exam
inline bool parseStudentLine(const std::string& line, Person& outPerson, bool useAverage) {
    std::istringstream iss(line);
    std::string first, last;
    if (!(iss >> first >> last)) return false;

    // Read remaining ints: HWs + exam (last int = exam)
    std::vector<int> nums;
    int x;
    while (iss >> x) nums.push_back(x);
    if (nums.size() < 1) return false;

    int exam = nums.back();
    nums.pop_back(); // rest are HW

    outPerson.setFirstName(first);
    outPerson.setLastName(last);
    outPerson.setHomework(nums);
    outPerson.setExam(exam);
    outPerson.calculateFinalGrade(useAverage);
    return true;
}

// Read students into any container (vector/list/deque)
template <typename Container>
void readStudentsFromFile(const std::string& filename, Container& students, bool useAverage) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Could not open file: " + filename);

    students.clear();

    std::string line;

    // Optional: skip header if it contains letters like "Name Surname ..."
    // We'll detect it: if a line starts with "Name" or contains non-student pattern, skip once.
    if (std::getline(in, line)) {
        if (line.find("Name") != std::string::npos && line.find("Surname") != std::string::npos) {
            // header skipped
        } else {
            // first line is data
            Person p;
            if (parseStudentLine(line, p, useAverage)) students.push_back(p);
        }
    }

    while (std::getline(in, line)) {
        if (line.empty()) continue;
        Person p;
        if (parseStudentLine(line, p, useAverage)) {
            students.push_back(p);
        }
    }
}

// Sort container
template <typename Container>
void sortStudents(Container& students) {
    if constexpr (std::is_same_v<Container, std::list<Person>>) {
        students.sort(bySurnameThenName);
    } else {
        std::sort(students.begin(), students.end(), bySurnameThenName);
    }
}

// =======================
// STRATEGY 1 (COPY -> 2 containers)
// =======================
template <typename Container>
void splitStrategy1_copyTwo(const Container& students, Container& passed, Container& failed) {
    passed.clear();
    failed.clear();

    std::copy_if(students.begin(), students.end(), std::back_inserter(passed),
                 [](const Person& s){ return s.getFinalGrade() >= 5.0; });

    std::copy_if(students.begin(), students.end(), std::back_inserter(failed),
                 [](const Person& s){ return s.getFinalGrade() < 5.0; });
}

// =======================
// STRATEGY 2 (MOVE failed out, ERASE from base)
// vector/deque version using stable_partition
// =======================
template <typename SeqContainer>
void splitStrategy2_moveErase(SeqContainer& students, SeqContainer& failed) {
    failed.clear();

    auto it = std::stable_partition(students.begin(), students.end(),
                                    [](const Person& s){ return s.getFinalGrade() >= 5.0; });

    std::move(it, students.end(), std::back_inserter(failed));
    students.erase(it, students.end()); // base now contains only passed
}

// list specialization using splice (fast erase/move)
inline void splitStrategy2_moveErase(std::list<Person>& students, std::list<Person>& failed) {
    failed.clear();
    for (auto it = students.begin(); it != students.end(); ) {
        if (it->getFinalGrade() < 5.0) {
            auto toMove = it++;
            failed.splice(failed.end(), students, toMove); // moves node O(1)
        } else {
            ++it;
        }
    }
}

// Write output (optional)
template <typename Container>
void writeStudents(const std::string& filename, const Container& students) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Could not write file: " + filename);

    out << "FirstName Surname Final\n";
    out << "-----------------------------\n";
    for (const auto& s : students) out << s << "\n";
}

#endif
