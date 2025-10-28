#include <iostream>
#include <vector>
#include <iomanip>
#include "Person.h"

int main() {
    std::vector<Person> students;
    char choice;
    
    std::cout << "Student Grading System v0.1" << std::endl;
    
    // Input students
    do {
        Person student;
        std::cin >> student;
        students.push_back(student);
        
        std::cout << "Add another student? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    // Choose calculation method
    char calcMethod;
    std::cout << "Calculate final grade using (a)verage or (m)edian? ";
    std::cin >> calcMethod;
    bool useAverage = (calcMethod == 'a' || calcMethod == 'A');
    
    // Calculate final grades
    for (auto& student : students) {
        student.calculateFinalGrade(useAverage);
    }
    
    // Display results
    std::cout << "\nName       Surname       Final_Point(" 
              << (useAverage ? "Aver.)" : "Med.)") << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    for (const auto& student : students) {
        std::cout << std::left << std::setw(11) << student.getFirstName() 
                  << std::setw(13) << student.getLastName() 
                  << std::fixed << std::setprecision(2) << student.getFinalGrade() 
                  << std::endl;
    }
    
    return 0;
}