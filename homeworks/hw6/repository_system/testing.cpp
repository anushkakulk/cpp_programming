/*
Anushka Kulkarni
6/18/23
Testing file that makes repositories of strings, doubles, Books, and Courses
and manipulates them.
*/

#include <iostream>
#include <vector>
#include <string>
#include "repository.hpp"
#include "book.hpp"
#include "course.hpp"

using namespace std;

int main()
{
    // ------- GENERIC TYPE TESTING 1 - STRING ------- //
    vector<string> names = {"alice", "bob", "carol", "dana", "edgar", "frank"};

    Repository<string> names_repo(names); // normal constructor
    cout << "Items in names_repo: " << endl;
    names_repo.displayItems();
    cout << endl;

    // Using the copy constructor
    Repository<string> names_repo_copy(names_repo);
    cout << "Items in names_repo_copy (copied from names_repo): " << endl;
    names_repo_copy.displayItems();
    cout << endl;

    // using the move constructor
    Repository<string> names_repo_moved(move(names_repo));
    cout << "items in names_repo_moved (moved from names_repo): " << endl;
    names_repo_moved.displayItems();
    cout << endl;

    // using the copy assignment op
    Repository<string> names_repo_copy_assigned;
    names_repo_copy_assigned = names_repo_moved;
    cout << "items in names_repo_copy_assigned (copy assigned from names_repo_moved): " << endl;
    names_repo_copy_assigned.displayItems();
    cout << endl;

    // using the move assignment op
    Repository<string> names_repo_move_assigned;
    names_repo_move_assigned = std::move(names_repo_copy);
    cout << "items in names_repo_move_assigned (move assigned from names_repo_copy): " << endl;
    names_repo_move_assigned.displayItems();
    cout << endl;

    Repository<string> test_names(names);

    cout << "adding a single item " << endl;
    // adding new names
    test_names.add("george");
    test_names.add("hank");
    // adding existing names
    test_names.add("alice");
    test_names.add("bob");
    test_names.displayItems();

    cout << "adding a vector to repo " << endl;
    // adding list of new names
    vector<string> new_names = {"ian", "jake", "kim"};
    test_names.addItems(new_names);
    // adding llist of existing names
    vector<string> same_names = {"carol", "dana", "edgar"};
    test_names.addItems(same_names);

    cout << "removing a item from reop " << endl;
    // removing new names
    test_names.remove("laney");
    test_names.remove("monica");
    // removing existing names
    test_names.remove("alice");
    test_names.remove("bob");
    test_names.displayItems();

    cout << "removing vector from repo " << endl;
    // removing list of new names
    test_names.removeItems(new_names);
    // removing llist of existing names
    test_names.removeItems(same_names);

    // ------- GENERIC TYPE TESTING 2 - DOUBLE ------- //
    vector<double> nums = {0.1, 2.02, 100.9, 42.3, 63.8887, 999.99};

    Repository<double> double_repo(nums); // normal constructor
    cout << "Items in double_repo: " << endl;
    double_repo.displayItems();
    cout << endl;

    // Using the copy constructor
    Repository<double> double_repo_copy(double_repo);
    cout << "Items in double_repo_copy (copied from double_repo): " << endl;
    double_repo_copy.displayItems();
    cout << endl;

    // using the move constructor
    Repository<double> double_repo_moved(move(double_repo));
    cout << "items in double_repo_moved (moved from double_repo): " << endl;
    double_repo_moved.displayItems();
    cout << endl;

    // using the copy assignment op
    Repository<double> double_repo_copy_assigned;
    double_repo_copy_assigned = double_repo_moved;
    cout << "items in double_repo_copy_assigned (copy assigned from double_repo_moved): " << endl;
    double_repo_copy_assigned.displayItems();
    cout << endl;

    // using the move assignment op
    Repository<double> double_repo_move_assigned;
    double_repo_move_assigned = std::move(double_repo_copy);
    cout << "items in double_repo_move_assigned (move assigned from double_repo_copy): " << endl;
    double_repo_move_assigned.displayItems();
    cout << endl;

    Repository<double> test_double(nums);

    cout << "adding a single item " << endl;
    // adding new double
    test_double.add(5.23);
    test_double.add(2345.3);
    // adding existing double
    test_double.add(0.1);
    test_double.add(2.02);
    test_double.displayItems();

    cout << "adding a vector to repo " << endl;
    // adding list of new double
    vector<double> new_double = {123.123, 321.321, 123.321};
    test_double.addItems(new_double);
    // adding llist of existing double
    vector<double> same_double = {100.9, 42.3, 63.8887};
    test_double.addItems(same_double);

    cout << "removing a item from reop " << endl;
    // removing new double
    test_double.remove(-1000000.1);
    test_double.remove(-1000000.2);
    // removing existing double
    test_double.remove(0.1);
    test_double.remove(2.02);
    test_double.displayItems();

    cout << "removing vector from repo " << endl;
    // removing list of new double
    test_double.removeItems(new_double);
    // removing llist of existing double
    test_double.removeItems(same_double);

    // ------- CUSTOM TYPE TESTING 3 - BOOK CLASS ------- //
    Book a("Cat in The Hat", "Dr Seuss", 1960);
    Book b("Green Eggs and Ham", "Dr Seuss", 1961);
    Book c("Harry Potter 1", "JK Rowling", 1970);
    Book d("Harry Potter 2", "JK Rowling", 1971);
    Book e("Harry Potter 3", "JK Rowling", 1972);
    Book f("Harry Potter 4", "JK Rowling", 1973);
    Book g("Harry Potter 5", "JK Rowling", 1974);
    Book h("Harry Potter 6", "JK Rowling", 1975);
    Book i("Harry Potter 7", "JK Rowling", 1976);

    vector<Book> books = {a, b, c};

    Repository<Book> books_repo(books); // normal constructor
    cout << "Items in books_repo: " << endl;
    books_repo.displayItems();
    cout << endl;

    // Using the copy constructor
    Repository<Book> books_repo_copy(books_repo);
    cout << "Items in books_repo_copy (copied from books_repo): " << endl;
    books_repo_copy.displayItems();
    cout << endl;

    // using the move constructor
    Repository<Book> books_repo_moved(move(books_repo));
    cout << "items in books_repo_moved (moved from books_repo): " << endl;
    books_repo_moved.displayItems();
    cout << endl;

    // using the copy assignment op
    Repository<Book> books_repo_copy_assigned;
    books_repo_copy_assigned = books_repo_moved;
    cout << "items in books_repo_copy_assigned (copy assigned from books_repo_moved): " << endl;
    books_repo_copy_assigned.displayItems();
    cout << endl;

    // using the move assignment op
    Repository<Book> books_repo_move_assigned;
    books_repo_move_assigned = std::move(books_repo_copy);
    cout << "items in books_repo_move_assigned (move assigned from books_repo_copy): " << endl;
    books_repo_move_assigned.displayItems();
    cout << endl;

    Repository<Book> test_books(books);

    cout << "adding a single item " << endl;
    // adding new books
    test_books.add(d);
    test_books.add(e);
    // adding existing books
    test_books.add(a);
    test_books.add(b);
    test_books.displayItems();

    cout << "adding a vector to repo " << endl;
    // adding list of new books
    vector<Book> new_books = {f, g, h};
    test_books.addItems(new_books);
    // adding llist of existing books
    vector<Book> same_books = {c, d, e};
    test_books.addItems(same_books);

    cout << "removing a item from reop " << endl;
    // removing new books
    test_books.remove(i);
    // removing existing books
    test_books.remove(a);
    test_books.displayItems();

    cout << "removing vector from repo " << endl;
    // removing list of new books
    test_books.removeItems(new_books);
    // removing llist of existing books
    test_books.removeItems(same_books);

    // ------- CUSTOM TYPE TESTING 4 - COURSE CLASS ------- //
    Course c_a("CS2500", "Arjun Guha");
    Course c_b("CS2510", "Ben Lerner");
    Course c_c("CS3520", "Adeel Bhutta");
    Course c_d("MATH1365", "Marco Rainho");
    Course c_e("Discrete", "Laney Strange");
    Course c_f("OOD", "Vido");
    Course c_g("PHIL1145", "John Basl");
    Course c_h("MATH101", "Marco Rainho");
    Course c_i("Compilers", "Ben Lear er");

    vector<Course> courses = {c_a, c_b, c_c};

    Repository<Course> courses_repo(courses); // normal constructor
    cout << "Items in courses_repo: " << endl;
    courses_repo.displayItems();
    cout << endl;

    // Using the copy constructor
    Repository<Course> courses_repo_copy(courses_repo);
    cout << "Items in courses_repo_copy (copied from courses_repo): " << endl;
    courses_repo_copy.displayItems();
    cout << endl;

    // using the move constructor
    Repository<Course> courses_repo_moved(move(courses_repo));
    cout << "items in courses_repo_moved (moved from courses_repo): " << endl;
    courses_repo_moved.displayItems();
    cout << endl;

    // using the copy assignment op
    Repository<Course> courses_repo_copy_assigned;
    courses_repo_copy_assigned = courses_repo_moved;
    cout << "items in courses_repo_copy_assigned (copy assigned from courses_repo_moved): " << endl;
    courses_repo_copy_assigned.displayItems();
    cout << endl;

    // using the move assignment op
    Repository<Course> courses_repo_move_assigned;
    courses_repo_move_assigned = std::move(courses_repo_copy);
    cout << "items in courses_repo_move_assigned (move assigned from courses_repo_copy): " << endl;
    courses_repo_move_assigned.displayItems();
    cout << endl;

    Repository<Course> test_courses(courses);

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
    vector<Course> new_courses = {c_f, c_g, c_h};
    test_courses.addItems(new_courses);
    // adding llist of existing courses
    vector<Course> same_courses = {c_c, c_d, c_e};
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