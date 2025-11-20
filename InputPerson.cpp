#include "InputPerson.h"

 vector<Person> inputFileVector(const string& fileName)
 {
     vector <vector <string>> fileInfo;
     stringstream myBuffer;
     vector<Person> personsInFile;

     auto start = high_resolution_clock::now();

     ifstream file(fileName);

     if (!file.is_open())
     {
         std::cerr << "\nFile not found!\n";
         return personsInFile;
     }
     
     myBuffer << file.rdbuf();
     file.close();
     
     std::chrono::duration<double> duration  = high_resolution_clock::now() - start;
     cout << "\nTime taken to read files to buffer: " << duration.count() << " seconds\n";

     vector <string> wordsInLine;
     string lineOfFile;

     start = std::chrono::high_resolution_clock::now();

     while (std::getline(myBuffer, lineOfFile))
     {
         wordsInLine.clear();
         std::istringstream is(lineOfFile);                  // Reads the lineOffile string

         string word;

         while (is >> word)                                     //words in lineOffile string is read separately using the word variable
         {
             wordsInLine.push_back(word);                             // fill the vector of string with each word from line
         }
         fileInfo.push_back(wordsInLine);                    //fill the vector with vector of string
     }

     duration = high_resolution_clock::now() - start;
     cout << "Time taken to put the buffer into a vector containing vector of strings: " << duration.count() << " seconds\n";

     bool firstLine = true;

     for (auto& lines : fileInfo)            // loops through entire vector which contains the file information, first index in vector is for first line in file
     {
         if (firstLine)
         {
             firstLine = false;
             continue;                       //skips first line in the file 
         }

         Person p;
         vector<double> hw;

         p.setFirstName(lines[0]);                           //sets object firstname variable with first word in the vector of string

         if (lines.size() > 1)
             p.setSurname(lines[1]);

         for (int i = 2; i < lines.size(); i++)
         {
             try
             {
                 if (lines[i].length() > 17) {
                     throw out_of_range("Number too large to fit into a double");
                 }

                 double value = std::stod(lines[i]);                     //converts string to double in exception checker block

                 if (i < lines.size() - 1)                      //checks if index is not on the last column which is reserved for exam scores
                     hw.push_back(value);
                 else
                     p.setExamScore(value);
             }
             catch (const invalid_argument& e)
             {
                 std::cerr << "\ninvalid homework or exam score detected in file for "
                     << lines[0] << " " << lines[1] << endl << endl;
             }
             catch (const out_of_range& e)
             {
                 std::cerr << "\nout of range homework score detected in file for "
                     << lines[0] << " " << lines[1] << ": " << lines[i] << endl << endl;
             }
         }

         p.setHomework(hw);
		 p.calcFinalGrade(1);                                   // (1) for calculting final grade via Average method for all file inputs
         personsInFile.push_back(p);
     }

     return personsInFile;
 }

 vector<Person> manualInputPerson()
 {
     int n;
     
     while (true)
     {
         cout << "\nPlease input number of students: ";

         cin >> n;
         if (cin.fail())
             clearWrongInputs();
         else break;
     }

     vector<Person> students(n);

     for (Person& student : students)
     {
         cin >> student;                 // calls overloaded cin to input data into Persons class member variables until number of students required has reached
     }

     return students;
 }

 /*void inputFile_list(const string& fileName)
 {
     stringstream buffer;
     list<string> fileData;
     string line;

     ifstream fileIn(fileName);

     if (!fileIn)
     {
         cout << "File not found!";
     }
     
     buffer << fileIn.rdbuf();
     fileIn.close();

     while(getline(buffer,line))
     {
         fileData.push_back(line);
     }
     
 }

 void inputFile_Deque(const string& fileName)
 {
     stringstream buffer;
     deque<string> fileData;

     ifstream fileIn(fileName);

     if(!fileIn)
     {
         cerr << "Error opening File";
     }

     buffer << fileIn.rdbuf();
     fileIn.close();

     string line;

     while (getline(buffer,line))
     {
         fileData.push_back(line);
     }
 }

void inputFile_Vector(const string& fileName)
 {
     stringstream buffer;
     vector<string> fileData;

     ifstream fileIn(fileName);
     
     if(!fileIn)
     {
         cerr << "Error opening file!";
     }

     buffer << fileIn.rdbuf();
     fileIn.close();

     string line;

     while(getline(buffer,line))
     {
         fileData.push_back(line);
     }
 }*/