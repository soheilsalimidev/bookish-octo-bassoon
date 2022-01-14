//
// Created by Soheil Salimi on 1/7/2022.
//

#include <iostream>
#include "Student.h"
#include "Lesson.h"

using namespace std;

void controlActions();

int main() {

    cout << "\n" <<
         "----------[ Welcome to the app ]----------";

    controlActions();

    return 0;
}

void controlActions() {

    int action;

    cout << "\n" <<
         "    1) Add Student \n" <<
         "    2) Add lesson for student \n" <<
         "    3) See results \n" <<
         "    4) Exit\n";

    cin >> action;
//    Student student;

    if (action == 1)
        Student::newStudent();
    else if (action == 2)
        Lesson::addLessonForStudent();
    else if (action == 3)
        Lesson::showStudentLessons();
    else
        exit(0);

    controlActions();

}
