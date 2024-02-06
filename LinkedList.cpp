#include "LinkedList.h"
#include <fstream>
#include <iostream>



// Constructor
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

// Destructor
LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

// Adds a new node to the end of the list.
void LinkedList::add(const Course& data) {
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

// Removes a node from the list.
void LinkedList::remove(Course data) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data.getName() != data.getName()) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        return;
    }
    if (prev == nullptr) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
    size--;
}

// Returns the size of the list.
int LinkedList::getSize() const {
    return size;
}

// Returns true if the list contains the given data.
bool LinkedList::contains(int data) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getHours() == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Returns the data at the given index.
int LinkedList::get(int index) const {
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data.getHours();
}

// Inserts Course at a given index.
void LinkedList::insert(int index, const Course& data) {
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = nullptr;
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

// Removes the node at the given index.
void LinkedList::removeAt(int index) {
    Node* temp = head;
    if (index == 1) {
        head = temp->next;
        delete temp;
    }
    else {
        for (int i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
    size--;
}


// Reads the list from a file.
void LinkedList::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        std::string grade;
        int hours, semester;
        while (file >> name >> grade >> hours >> semester) {
            Course course(name, grade, hours, semester);
            add(course);
        }
        file.close();
    } else {
        std::cout << "File not found" << std::endl;
        exit(1);
    }
}

// Writes the list to a file.
void LinkedList::writeToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data.getName() << " " << temp->data.getGrade().getLetter() << " " << temp->data.getHours() << " " << temp->data.getSemester() << std::endl;
            temp = temp->next;
        }
        file.close();
    }else {
        std::cout << "File not found" << std::endl;
        exit(1);
    }
}

//Function to Put My personal courses in Data.txt
void LinkedList::fixDataFile() {
    clear();
    readFromFile("MyValues.txt");
    writeToFile("Data.txt");
}

void LinkedList::print() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data.getName() << " " << temp->data.getGrade().getLetter() << " " << temp->data.getHours() << std::endl;
        temp = temp->next;
    }
}

double LinkedList::getGPA() const {
    Node* temp = head;
    double totalPoints = 0;
    int totalHours = 0;
    while (temp != nullptr) {
        totalPoints += temp->data.getGrade().getGpa() * temp->data.getHours();
        totalHours += temp->data.getHours();
        temp = temp->next;
    }
    return totalPoints / totalHours;
}

void LinkedList::printGPA() const {
    cout << "Cumulative GPA: " << getGPA() << endl;
}

void LinkedList::sort() {
    Node* temp = head;
    Node* temp2 = nullptr;
    while (temp != nullptr) {
        temp2 = temp->next;
        while (temp2 != nullptr) {
            if (temp->data.getSemester() > temp2->data.getSemester()) {
                Course tempCourse = temp->data;
                temp->data = temp2->data;
                temp2->data = tempCourse;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void LinkedList::clear() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
    size = 0;

}



int LinkedList::getHours() const {
    Node* temp = head;
    int totalHours = 0;
    while (temp != nullptr) {
        totalHours += temp->data.getHours();
        temp = temp->next;
    }
    return totalHours;
}

void LinkedList::printHours() const {
    cout << "Total Hours Completed: " << getHours() << endl;

}

double LinkedList::getTermGPA(int semester) const {
    Node* temp = head;
    double totalPoints = 0;
    int totalHours = 0;
    while (temp != nullptr) {
        if (temp->data.getSemester() == semester) {
            totalPoints += temp->data.getGrade().getGpa() * temp->data.getHours();
            totalHours += temp->data.getHours();
        }
        temp = temp->next;
    }
    return totalPoints / totalHours;
}

void LinkedList::printTermGPA(int semester) const {
    cout << "GPA for semester " << semester << " equals: " << getTermGPA(semester) << endl;
}

