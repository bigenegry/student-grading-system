#include "OutputPerson.h"
#include "InputPerson.h"


int main()
{
    srand(time(0));     //seed for rand fucntion to generate from time

    cout << "1.Input students from file\t2.Output Random Students to file\t3.Input students manually\n" << endl;
    int studentInputChoice;

    while (true)
    {
        cout << "Please choose option 1 , 2 or 3: ";
        cin >> studentInputChoice;
        if (cin.fail())
            clearWrongInputs();

        else if (studentInputChoice == 1 || studentInputChoice == 2 || studentInputChoice == 3)
            break;

        else
            cout << "invalid Selection! ";
    }

    if (studentInputChoice == 1)       // Read INPUT from file 
    {
        vector <Person> filePersons = inputFileVector("students10000.txt");

		gradeSorter_Vect(filePersons);                  //sorts students by final grade (average)
        outputSplitGrade_Vect(filePersons);
    }

    if (studentInputChoice == 2)            //Output random students to file
    {
       cout << "\nPlease type in Name of file you want to create or replace... \nexample, 'Filename.txt': ";
       string fileName;
       cin >> fileName;

        vector<Person> randomStudents = randomizePersons();

        outputToFile_HW_EX(fileName, randomStudents);
    }

    if (studentInputChoice == 3)    // to input information manually into person class and print final grade by average or median by users choice
    {
        vector <Person> students = manualInputPerson();

        printGrades_AverOrMed(students);
    }
    return 0;
}
