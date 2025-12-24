#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <type_traits>

#include "Person.h"
#include "Utilities.h"
#include "Timer.h"

template <typename Container>
void runBenchForContainer(const std::string& containerName,
                          const std::string& inputFile,
                          bool useAverage,
                          bool writeOutputs) {
    Container students;
    Timer t;

    // READ
    t.reset();
    readStudentsFromFile(inputFile, students, useAverage);
    long long readMs = t.elapsed_ms();

    // SORT
    t.reset();
    sortStudents(students);
    long long sortMs = t.elapsed_ms();

    // STRATEGY 1
    Container passed1, failed1;
    t.reset();
    splitStrategy1_copyTwo(students, passed1, failed1);
    long long s1Ms = t.elapsed_ms();

    // STRATEGY 2 (use a copy so both strategies are comparable)
    Container students2 = students;
    Container failed2;
    t.reset();
    splitStrategy2_moveErase(students2, failed2);
    long long s2Ms = t.elapsed_ms();

    std::cout
        << containerName
        << " | Read: " << readMs << " ms"
        << " | Sort: " << sortMs << " ms"
        << " | S1 split: " << s1Ms << " ms"
        << " | S2 split: " << s2Ms << " ms"
        << " | total: " << students.size()
        << " | passed(S1): " << passed1.size()
        << " | failed(S1): " << failed1.size()
        << " | failed(S2): " << failed2.size()
        << "\n";

    if (writeOutputs) {
        // output filenames (small datasets recommended for GitHub)
        std::string base = inputFile;
        // remove path for nicer file names:
        auto pos = base.find_last_of("/\\");
        if (pos != std::string::npos) base = base.substr(pos + 1);

        writeStudents("passed_" + containerName + "_" + base, passed1);
        writeStudents("failed_" + containerName + "_" + base, failed1);
    }
}

int main(int argc, char** argv) {
    // Usage:
    // ./student_grading_system data/students10000.txt avg 0
    // avg|med, writeOutputs 0|1

    std::string inputFile = "data/students10000.txt";
    std::string method = "avg";
    int writeOut = 0;

    if (argc >= 2) inputFile = argv[1];
    if (argc >= 3) method = argv[2];
    if (argc >= 4) writeOut = std::stoi(argv[3]);

    bool useAverage = (method != "med");

    std::cout << "Input: " << inputFile
              << " | Method: " << (useAverage ? "Average" : "Median")
              << " | Write outputs: " << (writeOut ? "YES" : "NO")
              << "\n\n";

    runBenchForContainer<std::vector<Person>>("vector", inputFile, useAverage, writeOut != 0);
    runBenchForContainer<std::deque<Person>> ("deque",  inputFile, useAverage, writeOut != 0);
    runBenchForContainer<std::list<Person>>  ("list",   inputFile, useAverage, writeOut != 0);

    return 0;
}
