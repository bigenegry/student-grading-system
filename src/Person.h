#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Person();
    Person(const std::string& first, const std::string& last);

    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    friend std::istream& operator>>(std::istream& is, Person& person);
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    void calculateFinalGrade(bool useAverage);

    std::string getFirstName() const;
    std::string getLastName() const;
    double getFinalGrade() const;

    void addHomework(int score);
    void setExam(int score);

private:
    double calculateAverage() const;
    double calculateMedian() const;
};

#endif
