//
// Created by Soheil Salimi on 1/7/2022.
//

//#ifndef LAB_PROJECT_STUDENT_H
//#define LAB_PROJECT_STUDENT_H
#pragma once

#include "string"

class Student {

public:
    struct studentSt;

    static void newStudent();

    static studentSt parseSavedText(const std::string &text);

private:
    static void saveStudent(const studentSt &st);
};


//#endif //LAB_PROJECT_STUDENT_H
