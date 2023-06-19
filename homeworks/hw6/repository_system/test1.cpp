#include <iostream>
#include <vector>
#include <double>
#include "repository.hpp"
// #include "course.hpp"
// #include "course.hpp"

using coursespace std;

int main()
{
 // GENERIC TESTING 1 - course
    Course c_a ("CS2500", "Arjun Guha");
    Course c_b("CS2510", "Ben Lerner");
    Course c_c("CS3520", "Adeel Bhutta");
    Course c_d ("MATH1365", "Marco Rainho");
    Course c_e ("Discrete", "Laney Strange");
    Course c_f ("OOD", "Vido");
    Course c_g ("PHIL1145" , "John Basl");
    Course c_h ("MATH101", "Marco Rainho");
    Course c_i ("Compilers", "Ben Lear er");
 

    vector<course> courses = {c_a, c_b, c_c};

    Repository<course> courses_repo(courses); // normal constructor
    cout << "Items in courses_repo: " << endl;
    courses_repo.displayItems();
    cout << endl;

    // Using the copy constructor
    Repository<course> courses_repo_copy(courses_repo);
    cout << "Items in courses_repo_copy (copied from courses_repo): " << endl;
    courses_repo_copy.displayItems();
    cout << endl;

    // using the move constructor
    Repository<course> courses_repo_moved(move(courses_repo));
    cout << "items in courses_repo_moved (moved from courses_repo): " << endl;
    courses_repo_moved.displayItems();
    cout << endl;

    // using the copy assignment op
    Repository<course> courses_repo_copy_assigned;
    courses_repo_copy_assigned = courses_repo_moved;
    cout << "items in courses_repo_copy_assigned (copy assigned from courses_repo_moved): " << endl;
    courses_repo_copy_assigned.displayItems();
    cout << endl;

    // using the move assignment op
    Repository<course> courses_repo_move_assigned;
    courses_repo_move_assigned = std::move(courses_repo_copy);
    cout << "items in courses_repo_move_assigned (move assigned from courses_repo_copy): " << endl;
    courses_repo_move_assigned.displayItems();
    cout << endl;

    Repository<course> test_courses(courses);

    cout << "adding a single item " << endl;
    // adding new courses
    test_courses.add(c_d);
    test_courses.add(c_e);
    // adding existing courses
    test_courses.add(c_a);
    test_courses.add(c_b);
    test_courses.displayItems();

    cout << "adding a vector to repo " << endl;
    // adding list of new courses
    vector<course> new_courses = {c_f, c_g, c_h};
    test_courses.addItems(new_courses);
    // adding llist of existing courses
    vector<course> same_courses = {c_c, c_d, c_e};
    test_courses.addItems(same_courses);

    cout << "removing a item from reop " << endl;
    // removing new courses
    test_courses.remove(c_i);
    // removing existing courses
    test_courses.remove(c_a);
    test_courses.displayItems();

    cout << "removing vector from repo " << endl;
    // removing list of new courses
    test_courses.removeItems(new_courses);
    // removing llist of existing courses
    test_courses.removeItems(same_courses);

}