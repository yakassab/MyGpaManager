#include "Grade.h"
#include <utility>

// Grade constructor sets gpa based on letter.
Grade::Grade(string l) : letter(std::move(l)) {
    if (letter == "A+" || letter == "A") {
        gpa = 4.0;
    }
    else if (letter == "A-") {
        gpa = 3.7;
    }
    else if (letter == "B+") {
        gpa = 3.3;
    }
    else if (letter == "B") {
        gpa = 3.0;
    }
    else if (letter == "B-") {
        gpa = 2.7;
    }
    else if (letter == "C+") {
        gpa = 2.3;
    }
    else if (letter == "C") {
        gpa = 2.0;
    }
    else if (letter == "C-") {
        gpa = 1.7;
    }
    else if (letter == "D+") {
        gpa = 1.3;
    }
    else if (letter == "D") {
        gpa = 1.0;
    }
    else if (letter == "F") {
        gpa = 0.0;
    }
}


// Accessor for letter.
string Grade::getLetter() {
    return letter;
}

// Accessor for gpa.
double Grade::getGpa() {
    return gpa;
}

// Mutator for letter.
void Grade::setLetter(string l) {
    letter = std::move(l);
}

// Mutator for gpa.
void Grade::setGpa(double g) {
    gpa = g;
}


