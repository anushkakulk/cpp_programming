#include <iostream>
#include <string>
#include "course.hpp"

using namespace std;

// normal constructor
Course::Course(const string& course_name, const string& prof)
    : course_name(course_name), prof(prof) {}

// Copy constructor
Course::Course(const Course& other) {
    cout << "Copy constructor" << endl;
    course_name = other.course_name;
    prof = other.prof;

}

// Move constructor
Course::Course(Course&& other) {
    cout << "Move constructor" << endl;
    course_name = move(other.course_name);
    prof = move(other.prof);
  
}

// copy assignment operator
Course& Course::operator=(const Course& other) {
    cout << "Copy assignment operator" << endl;

    if (this != &other) {
        course_name = other.course_name;
        prof = other.prof;
        
    }
    return *this;
}

// move assignment operator
Course& Course::operator=(Course&& other) {
    cout << "Move assignment operator" << endl;

    if (this != &other) {
        course_name = move(other.course_name);
        prof = move(other.prof);
       
    }
    return *this;
}

Course::~Course(){};

// overloads <<
ostream& operator<<(ostream& os, const Course& Course) {
    os << "course_name: " << Course.course_name << endl;
    os << "prof: " << Course.prof << endl;

    return os;
}

// overload >>
istream& operator>>(istream& is, Course& Course) {
    cout << "Enter course_name: ";
    getline(is, Course.course_name);

    cout << "Enter prof: ";
    getline(is, Course.prof);

    return is;
}

// overloaded !=
bool operator!=(const Course& first, const Course& second) {
    return (first.course_name != second.course_name) || (first.prof != second.prof) ;
}

// overloaded ==
bool operator==(const Course& first, const Course& second) {
    return (first.course_name == second.course_name) && (first.prof == second.prof);
}

// getters
string Course::get_course_name() const { return course_name; }
string Course::get_prof() const { return prof; }

