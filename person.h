#ifndef Person_H
#define Person_H

#include "MyLib.h"

class Person {
private:
    string firstName, surName;
    double exam, grade;
    vector<double> HW;
public:
    Person();
    Person(string firstName, string surName, double exam, double grade, vector<double> HW);
    Person(const Person& other);
    ~Person();
    Person& operator= (const Person& other);
    friend istream& operator>>(istream& input, Person& p);
    friend ostream& operator<<(ostream& out, Person& p);
    

    void setFirstName(const string& firstName);
    string getfirstName();

    void setSurname(const string& surName);
    string getSurname();

    void setExamScore(double exam);
    double getExamScore();

    void setHomework(const vector<double> HW);
    vector <double> getHomework();

    void calcFinalGrade(int n );
    void calcMedian();
    void calcAverage();

    double getGrade();
};

#endif