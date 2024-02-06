#include <iostream>
#include "LinkedList.h"
#include "Course.h"


int main() {
    LinkedList list;
    list.readFromFile("Data.txt");
    cout << "This is the list just after reading from file:\n";
    list.print();
    cout << endl << endl << endl;


    cout << "Now modifying the list\n";
    /*
    list.add(Course("Maths(2)", "B", 3, 1));
    list.add(Course("Dynamics", "B+", 3, 1));
    list.add(Course("Electricity", "B", 3, 1));
    list.add(Course("Projection", "A+", 3, 1));
    list.add(Course("Fundamentals", "B+", 3, 1));
    list.add(Course("Production", "B-", 3, 1));
    */
    //list.clear();

    list.printGPA();


    cout << endl << endl << endl;
    cout << "This is the list just before saving to file:\n";
    list.print();
    list.writeToFile("Data.txt");
    return 0;
}
