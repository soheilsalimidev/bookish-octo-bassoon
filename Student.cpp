//
// Created by Soheil Salimi on 1/7/2022.
//

#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student::studentSt {
    int ID{};
    string name;
};

void Student::newStudent() {
    system("cls");
    studentSt student;
    cout << "   Enter Student ID: \n   ";
    cin >> student.ID;
    cout << "   Enter Student name: \n   ";
    cin.ignore();
    getline(cin, student.name);
    saveStudent(student);
    system("cls");
    cout << "--------Information saved Successfully :) --------";
}

void Student::saveStudent(const studentSt &st) {
    ofstream studentsFile;
    studentsFile.open("students.txt", std::ios_base::app);
    studentsFile << st.ID << "," << st.name << "\n";
    studentsFile.close();
}

Student::studentSt Student::parseSavedText(const string& text) {
    stringstream ss(text);
    int i = 0;
    studentSt st;
    string substr;
    while (getline(ss, substr, ',')) {
        if (i == 0)st.ID = stoi(substr);
        else st.name = substr;
        i++;
    }
    return st;
}


