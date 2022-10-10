#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char firstName[30];
  char lastName[30];
  int studentID;
  float gpa;
};

void newStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> &studentList);

int main() {
  char input[7];
  bool running = true;
  vector<Student*> studentList;
  
  while (running == true) {
    cout << "---------------------------------------------------------" << endl;
    cout << "What Would You Like To Do? (ADD/PRINT/DELETE/QUIT/HELP)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0) {
      newStudent(studentList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudent(studentList);
    }
    else if (strcmp(input, "DELETE") == 0) {
      // 
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else if (strcmp(input, "HELP") == 0) {
      cout << "Type \"ADD\" To Enter A New Student" << endl;
      cout << "Type \"PRINT\" To Print Out All Stored Students" << endl;
      cout << "Type \"DELETE\" To Delete A Student" << endl;
      cout << "Type \"QUIT\" To End Program" << endl;
    }
    else {
      cout << "Not Sure What You're Trying To Do, Type \"HELP\" For Help" << endl;
    }
  }  
  return 0;
}

void newStudent(vector<Student*> &studentList) {
  Student* addStudent = new Student();
  char firstNameTemp[30];
  char lastNameTemp[30];
  int studentIDTemp;
  float gpaTemp;
  
  cout << "What Is The Student's First Name?" << endl;
  cin >> firstNameTemp;
  cout << "What Is The Student's Last Name?" << endl;
  cin >> lastNameTemp;
  cout << "What Is The Student's ID Number?" << endl;
  cin >> studentIDTemp;
  cout << "What Is The Student's GPA?" << endl;
  cin >> gpaTemp;

  strcpy(addStudent->firstName, firstNameTemp);
  strcpy(addStudent->lastName, lastNameTemp);
  addStudent->studentID = studentIDTemp;
  addStudent->gpa = gpaTemp;

  studentList.push_back(addStudent);
}

void printStudent(vector<Student*> &studentList) {
  cout << "Here Are All The Students You've Listed So Far:" << endl;

  for (int i = 0; i < studentList.size(); i++) {
    cout << studentList.at(i) << ' ' << endl;
  }
}
