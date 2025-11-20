#include "Utilities.h"

double Median(vector<double>& list) {
    double Median;

    int length = list.size();

    if (length == 0) return 0;

    sort(list.begin(), list.end());

    if (length % 2 == 0) {
        int mid = length / 2;
        int mid1 = mid - 1;

        Median = (list[mid] + list[mid1]) / 2;
    }
    else Median = list[length / 2];

    return Median;
}

double average(vector<double>& list)
{
    double average = (accumulate(list.begin(), list.end(), 0.0) / list.size());

    return average;
}

void clearWrongInputs()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "invalid input!\n";
}

vector<Person> randomizePersons()
{
	vector<Person> randomStudents;
	vector<double> hw;
	int n;

	cout << "Please input number of students you want to randomize: ";

	while (true)
	{
		cin >> n;
		if (cin.fail())
		{
			clearWrongInputs();

			cout << "Input a number: ";
		}
		else
			break;
	}

    auto start = high_resolution_clock::now();

	for (int i = 1; i <= n; i++)
	{
		Person p;
		hw.clear();

		p.setFirstName("Name" + std::to_string(i));
		p.setSurname("Surname" + std::to_string(i));

		for (int j = 0; j < 6; j++)
		{
			double homework = rand() % 11;
			hw.push_back(homework);
		}

		p.setHomework(hw);

		double exam = rand() % 11;
		p.setExamScore(exam);

		p.calcFinalGrade(1);

		randomStudents.push_back(p);
	}

    std::chrono::duration<double> duration = high_resolution_clock::now() - start;
    cout << "\nRandomizing and pushing n number of students into a vector takes " << duration.count() << " seconds\n";

	return randomStudents;
}

void gradeSplitter_Vect(vector <Person>& students, vector <Person>& Passed, vector <Person>& Failed)
{
    auto start = high_resolution_clock::now();

    for (auto& s : students)
    {
        if (s.getGrade() < 5)
            Failed.push_back(s);
        else
            Passed.push_back(s);
    }

    std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the vector into two containers: " << duration.count() << " seconds\n";
}

void gradeSorter_Vect(vector <Person>& students)
{
	auto start = high_resolution_clock::now();

	sort(students.begin(), students.end(), [](Person& a, Person& b) { return a.getGrade() > b.getGrade(); });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to sort the vector of students: " << duration.count() << " seconds\n";
}

void printGrades_AverAndMed(vector<Person>& students)
{
    cout << left << setw(20) << "Name"                   //format for header of file
        << setw(20) << "Surname"
        << right << setw(20) << "Final (Avg. )" << " | "
        << left << setw(20) << "Final (Med. )" << endl;

    string line(79, '-');           //to get accurate width of line but it's not accurate for some reason, even though 83 is the width of previous line
    cout << line << endl;

    for (auto& student : students)             //loops through persons and  calculates Average and median and then prints each line in the file with results in console.
    {
        cout << left << student;

        student.calcAverage();
        cout << fixed << setprecision(2) << right << setw(20) << student.getGrade() << " | ";

        student.calcMedian();
        cout << fixed << setprecision(2) << setw(15) << student.getGrade() << endl;
    }
}

void printGrades_AverOrMed(vector<Person>& students)
{
    cout << "\nCalculate Grade with:\n1. Average\n2. Median\n";
    int m;

    while (true)
    {
        cout << "Please press 1 or 2: ";
        cin >> m;

        if (cin.fail())                                 //exception handler to control input that are not intergers of type int.
            clearWrongInputs();
        else if (m == 1 || m == 2)
            break;
        else
            cout << "Invalid selection!\n";
    }

    cout.setf(ios::left);           //formats header for manual input of students
    cout.width(20);
    cout << "Name";
    cout.width(20);
    cout << "Surname";
    cout.width(20);
    cout << ((m == 1) ? "Final_point(Aver.)" : "Final_point(Median)") << endl;
    string line(60, '-');
    cout << line << endl;

    for (Person& student : students)
    {
        cout << student;        //calls overloaded cout to print first and last name of student

        student.calcFinalGrade(m);                  //calculates and updates the grade member of persons class based on user's choice

        cout << fixed << setw(20) << setprecision(2) << student.getGrade() << endl;
    }
}
