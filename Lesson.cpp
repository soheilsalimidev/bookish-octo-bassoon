//
// Created by Soheil Salimi on 1/7/2022.
//

#include "Lesson.h"
#include <iostream>
#include <fstream>
#include "string"
#include "include/tabulate/tabulate.hpp"

using namespace std;
using namespace tabulate;

struct Student::studentSt {
    int ID{};
    string name;
};

struct Lesson::LessonSt {
    string name;
    int score{};
    int unit{};
};


void Lesson::addLessonForStudent() {
    system("cls");
    int ID;
    cout << "Enter Student ID that you want to add lesson for \n";
    cin >> ID;
    Student::studentSt st;
    if (checkStudent(ID, st)) {
        addLesson(ID);
        system("cls");
    } else
        cout << "This Id docent Exist :( \n";
    cout << "--------Information saved Successfully :) --------";
}

void Lesson::addLesson(int ID) {
    LessonSt Ls;
    cout << "Enter lesson name: \n";
    cin.ignore();
    getline(cin , Ls.name);
    cout << "Enter lesson score: \n";
    cin >> Ls.score;
    cout << "Enter lesson unit: \n";
    cin >> Ls.unit;
    ofstream studentLessonFile;
    studentLessonFile.open("student" + to_string(ID) + ".txt", std::ios_base::app);
    studentLessonFile << Ls.name << "," << Ls.score << "," << Ls.unit << "\n";
    char con;
    cout << "Do you want continue to add (y/n): \n";
    cin >> con;
    system("cls");
    if (con == 'y')
        addLesson(ID);

}

void Lesson::showStudentLessons() {
    system("cls");
    int ID;
    cout << "Enter Student ID that you want to add lesson for \n";
    cin >> ID;
    Student::studentSt st;


    if (checkStudent(ID, st)) {
        ifstream studentLessonFile("student" + to_string(ID) + ".txt");
        string lines;
//        cout << "------------------------------------------\n";
//        cout << "       [   " << st.ID << "   |     " << st.name << " ]\n";
//        cout << "|   Lesson name   |   score   |   unit   |\n";

        Table LessonsTable;
        LessonsTable.add_row({"Lesson name", "Score", "Unit"});

        double avg = 0;
        int i = 0;
        while (getline(studentLessonFile, lines)) {
            i++;
            LessonSt ls = parseSavedText(lines);
            avg += ls.score;
            LessonsTable.add_row({ls.name, to_string(ls.score), to_string(ls.unit)});
        }
        system("cls");
        cout << LessonsTable << endl;
        cout << "[ Average score of " << st.name << " is " << avg / i << " ]\n\n";

    } else
        cout << "This Id docent Exist :( \n";

}

bool Lesson::checkStudent(int id, Student::studentSt &studentSt) {
    string lines;
    ifstream students("students.txt");
    while (getline(students, lines)) {
        Student::studentSt st = Student::parseSavedText(lines);
        if (st.ID == id) {
            studentSt = st;
            return true;
        }
    }
    return false;
}

Lesson::LessonSt Lesson::parseSavedText(const string &text) {
    stringstream ss(text);
    int i = 0;
    LessonSt st;
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        if (i == 0)st.name = substr;
        else if (i == 1) st.score = stoi(substr);
        else st.unit = stoi(substr);
        i++;
    }
    return st;
}
