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
    // Constructors
    Person();
    Person(const std::string& first, const std::string& last);
    
    // Rule of Three
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    // Input/Output methods
    friend std::istream& operator>>(std::istream& is, Person& person);
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    // Grade calculation
    void calculateFinalGrade(bool useAverage);
    
    // Getters
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    double getFinalGrade() const { return finalGrade; }

    // Utility methods
    void addHomework(int score);
    void setExam(int score);
    
private:
    double calculateAverage() const;
    double calculateMedian() const;
};

#endif