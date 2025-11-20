#include "Utilities.h"

Person::Person() {
    firstName = "";
    surName = "";
    exam = 0;
    grade = 0;
    HW = {0};
}
Person::Person(string firstName, string surName, double exam, double grade, vector<double> HW) : firstName(firstName), surName(surName), exam(exam), grade(grade), HW(HW) {}
Person::Person(const Person& other) {
    firstName = other.firstName;
    surName = other.surName;
    exam = other.exam;
    grade = other.grade;
    HW = other.HW;
}
Person::~Person() {}
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName = other.firstName;
        surName = other.surName;
        exam = other.exam;
        grade = other.grade;
        HW = other.HW;
    }
    return *this;
}


void Person::setFirstName(const string& firstName) { this->firstName = firstName; }
string Person::getfirstName() { return firstName; }

void Person::setSurname(const string& surName) { this->surName = surName; }
string Person::getSurname() { return surName; };

void Person::setExamScore(double exam) { this->exam = exam;}
double Person::getExamScore() { return exam; }

void Person::setHomework(const vector<double> HW){ this->HW = HW; }
vector <double> Person::getHomework() { return HW; }

double Person::getGrade() { return grade; }

void Person::calcFinalGrade(int n) {

    if (n == 1) {
        grade = 0.4 * average(HW) + 0.6 * exam;
    }
    else if (n == 2)
        grade = 0.4 * Median(HW) + 0.6 * exam;
}

void Person::calcMedian()
{   
    grade = 0.4 * Median(HW) + 0.6 * exam; 
}
void Person::calcAverage()
{
    grade = 0.4 * average(HW) + 0.6 * exam;
}

istream& operator>>(istream& input, Person& p) {

    string firstName, surName;
    double exam;
    vector <double> h;

    cout << "\nPlease enter student's name and surname: ";
    cin >> firstName >> surName;
    p.setFirstName(firstName);
    p.setSurname(surName);

    cout << "1. Input Exam Score\t 2. Generate random exam Score" << endl;     // collects exam score from user
    int n;

    while(true)                                 // Loop to ask if user wants to input or generate exam score
    {   
        cout << "Please input option 1 or 2: ";
        cin >> n;

        if(cin.fail())
            clearWrongInputs();

        else if (n == 1)
        {
            cout << "\nEnter student's exam score" << endl;

            while (true)              // loop to collect only valid exam score from 0 to 100
            {
                cout << "Please input exam score from 0 - 100:  ";
                cin >> exam;

                if (cin.fail())
                    clearWrongInputs();

                else if (exam >= 0 && exam <= 100)
                    break;

                else
                    cout << "Invalid Score!\n";
            }

            p.setExamScore(exam);
            break;
        }
        else if (n == 2)
        {
            exam = rand() % 100 + 1;
            cout << exam << " generated" << endl << endl;
            p.setExamScore(exam);
            break;
        }
        else 
            cout << "Invalid selection!\n";
    }

    cout << "\n1. Add homework\t 2.No Homework\t 3.Randomize Homework" << endl; 
    int i; 
  
    while(true)                                                                     // Loop to enter homework scores
    {
        cout << "Please input option 1, 2 or 3: ";   
        cin >> i;

        if (cin.fail())
            clearWrongInputs();

        else if (i == 2)
            break;

        else if (i == 1)
        {
            string hw;
            int j = 0;

            while (true)
            {
                cout << "\nPlease X to finish or Input Homework " << j + 1 << ": ";
                cin >> hw;
                
                if (hw == "x" || hw == "X" )
                    break;
                
                try 
                {
                    double hws = stod(hw);
                    h.push_back(hws);
                    j++;
                }
                catch(const invalid_argument& e)
                {
                    cout << "Invalid input!";
                }
            } 

            if (!h.empty())
            {
                p.setHomework(h);
                break;
            }
            else
                break;
        }
        else if (i == 3)
        {
            cout << "Input number of homeworks to generate randomly: ";
            int j;
            
            while(true)
            {
                cin >> j;

                if (cin.fail())
                {
                    clearWrongInputs();
                    cout << "Input a number: ";
                }
                else
                    break;
            }

            for (int i = 0; i < j; i++)
            {
               double hw = rand() % 100 + 1.00;           // generates random number for homework between 1 and 100
                cout << hw << " generated" << endl;

                h.push_back(hw);
            }

            p.setHomework(h);
            break;
        }
        else
        {
            cout << "Invalid selection!\n";
        }    
    }
 
    return input;
}
ostream& operator<<(ostream& out, Person& p) {
    cout.setf(ios::left);
    out.width(20);
    out << p.firstName;
    out.width(20);
    out << p.surName;

    return out;
}