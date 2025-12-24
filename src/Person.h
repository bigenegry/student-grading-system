#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person {
private:
    std::string firstName_;
    std::string lastName_;
    std::vector<int> homework_;
    int exam_{0};
    double finalGrade_{0.0};

public:
    // Constructors
    Person();
    Person(const std::string& first, const std::string& last);

    // Rule of Three
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    // Read one student from a text LINE like:
    // Name Surname HW1 HW2 ... HWn Exam
    // We parse in Utilities (recommended), but keep operator<< for output.
    friend std::ostream& operator<<(std::ostream& os, const Person& p);

    // Grade calculation (avg or median)
    void calculateFinalGrade(bool useAverage);

    // Setters used by parser
    void setFirstName(const std::string& s) { firstName_ = s; }
    void setLastName(const std::string& s)  { lastName_ = s; }
    void setExam(int score) { exam_ = score; }
    void setHomework(const std::vector<int>& hw) { homework_ = hw; }

    // Getters
    const std::string& getFirstName() const { return firstName_; }
    const std::string& getLastName() const  { return lastName_; }
    double getFinalGrade() const { return finalGrade_; }

private:
    double averageHW() const;
    double medianHW() const;
};

#endif
