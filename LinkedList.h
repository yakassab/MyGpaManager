#pragma once
#include "Course.h"

class Node {

    // should be private but will take too long to use the functions, I made it public
public:
    Course data;
    Node* next;

public:
    Node(Course value) : data(value), next(nullptr) {}

    // unused getters
    Course getData() const {return data;}
    Node* getNext() const {return next;}
};

class LinkedList {

private:
    Node* head;
    int size;

public:
    LinkedList();
    void add(const Course& data);
    void remove(Course data);
    void print() const;
    int getSize() const;
    bool contains(int data) const;
    int get(int index) const;
    void insert(int index, const Course& data);
    void removeAt(int index);
    void clear();
    double getGPA() const;
    void printGPA() const;
    int getHours() const;
    void printHours() const;
    double getTermGPA(int semester) const;
    void printTermGPA(int semester) const;
    void sort();
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);
    void fixDataFile();
    ~LinkedList();

};


