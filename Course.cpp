#include "Course.h"
#include <utility>
#include "Grade.h"


Course::Course(string n, string g, int h, int s) {
    name = std::move(n);
    grade = Grade(std::move(g));
    hours = h;
    semester = s;
}

string Course::getName() {
    return name;
}

Grade Course::getGrade() {
    return grade;
}

int Course::getHours() {
    return hours;
}

int Course::getSemester() {
    return semester;
}

void Course::setName(string n) {
    name = std::move(n);
}

void Course::setGrade(Grade g) {
    grade = std::move(g);
}

void Course::setHours(int h) {
    hours = h;
}

void Course::setSemester(int s) {
    semester = s;
}





