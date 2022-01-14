//
// Created by Soheil Salimi on 1/7/2022.
//

#pragma once

#include "string"
#include "Student.h"

class Lesson {
public:
    static void addLessonForStudent();

    static void showStudentLessons();

    struct LessonSt;
private:
    static bool checkStudent(int id, Student::studentSt &st);

    static LessonSt parseSavedText(const std::string &text);

    static void addLesson(int ID);
};
