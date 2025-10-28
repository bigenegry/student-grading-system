#include "Person.h"
#include <algorithm>
#include <numeric>

// Constructors
Person::Person() : firstName(""), lastName(""), exam(0), finalGrade(0.0) {}

Person::Person(const std::string& first, const std::string& last) 
    : firstName(first), lastName(last), exam(0), finalGrade(0.0) {}

// Copy constructor
Person::Person(const Person& other) {
    firstName = other.firstName;
    lastName = other.lastName;
    homework = other.homework;
    exam = other.exam;
    finalGrade = other.finalGrade;
}

// Copy assignment operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    return *this;
}

// Destructor
Person::~Person() {
    // Vector will automatically clean up
}

// Input method
std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Enter first name: ";
    is >> person.firstName;
    std::cout << "Enter last name: ";
    is >> person.lastName;
    
    person.homework.clear();
    std::cout << "Enter homework scores (enter -1 to finish): ";
    int score;
    while (is >> score && score != -1) {
        if (score >= 0 && score <= 10) {
            person.homework.push_back(score);
        }
    }
    
    std::cout << "Enter exam score: ";
    is >> person.exam;
    
    return is;
}

// Output method
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.firstName << " " << person.lastName << " " << person.finalGrade;
    return os;
}

// Calculate final grade
void Person::calculateFinalGrade(bool useAverage) {
    if (homework.empty()) {
        finalGrade = exam * 0.6;
        return;
    }
    
    double homeworkGrade;
    if (useAverage) {
        homeworkGrade = calculateAverage();
    } else {
        homeworkGrade = calculateMedian();
    }
    
    finalGrade = 0.4 * homeworkGrade + 0.6 * exam;
}

// Calculate average of homework
double Person::calculateAverage() const {
    if (homework.empty()) return 0.0;
    double sum = std::accumulate(homework.begin(), homework.end(), 0.0);
    return sum / homework.size();
}

// Calculate median of homework
double Person::calculateMedian() const {
    if (homework.empty()) return 0.0;
    
    std::vector<int> sortedHomework = homework;
    std::sort(sortedHomework.begin(), sortedHomework.end());
    
    size_t size = sortedHomework.size();
    if (size % 2 == 0) {
        return (sortedHomework[size/2 - 1] + sortedHomework[size/2]) / 2.0;
    } else {
        return sortedHomework[size/2];
    }
}

void Person::addHomework(int score) {
    homework.push_back(score);
}

void Person::setExam(int score) {
    exam = score;
}