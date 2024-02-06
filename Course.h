#pragma once

#include <string>
#include "Grade.h"

using namespace std;

class Course {
private:
    string name;
    Grade grade = Grade("F");
    int hours;
    int semester;

public:
    Course(string n, string g, int h, int s);
    string getName();
    Grade getGrade();
    int getHours();
    int getSemester();
    void setName(string name);
    void setGrade(Grade grade);
    void setHours(int hours);
    void setSemester(int s);
};

