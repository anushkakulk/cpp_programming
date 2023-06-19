#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <string>
using namespace std;
class Course
{
private:
    string course_name;
    string prof;


public:
    Course(){};

    // normal constructor
    Course(const string &course_name, const string &prof);

    // copy constructor
    Course(const Course &other);

    // move constructor
    Course(Course &&other);

    // copy assignment op
    Course &operator=(const Course &other);

    // move assignmetn op
    Course &operator=(Course &&other);

    // destructor
    ~Course();

    // prints out Course
    friend ostream &operator<<(ostream &os, const Course &Course);

    // takes in a Course
    friend istream &operator>>(istream &is, Course &Course);

    // overload !=
    friend bool operator!=(const Course &first, const Course &second);

    // overload ==
    friend bool operator==(const Course &first, const Course &second);

    // Getters
    string get_course_name() const;
    string get_prof() const;
};

#endif // Course_HPP