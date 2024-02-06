#pragma once

#include <string>

using namespace std;

class Grade {
private:
    string letter;
    double gpa;

public:
    Grade(string l);
    string getLetter();
    double getGpa();
    void setLetter(string letter);
    void setGpa(double gpa);
};


