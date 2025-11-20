#ifndef Utilities_H
#define Utilities_H

#include "Person.h"

double Median(vector<double>& list);

double average(vector<double>& list);

void clearWrongInputs();

vector<Person> randomizePersons();

void gradeSplitter_Vect(vector <Person>& students, vector <Person>& Passed, vector <Person>& Failed);

void gradeSorter_Vect(vector <Person>& students);

void printGrades_AverAndMed(vector<Person>& students);

void printGrades_AverOrMed(vector<Person>& students);

#endif