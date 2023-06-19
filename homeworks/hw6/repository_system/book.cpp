#include <iostream>
#include <string>
#include "book.hpp"

using namespace std;

// normal constructor
Book::Book(const string &title, const string &author, int year_pub)
    : title(title), author(author), year_pub(year_pub) {}

// Copy constructor
Book::Book(const Book &other)
{
    cout << "Copy constructor" << endl;
    title = other.title;
    author = other.author;
    year_pub = other.year_pub;
}

// Move constructor
Book::Book(Book &&other)
{
    cout << "Move constructor" << endl;
    title = move(other.title);
    author = move(other.author);
    year_pub = other.year_pub;
    other.year_pub = 0;
}

// copy assignment operator
Book &Book::operator=(const Book &other)
{
    cout << "Copy assignment operator" << endl;

    if (this != &other)
    {
        title = other.title;
        author = other.author;
        year_pub = other.year_pub;
    }
    return *this;
}

// move assignment operator
Book &Book::operator=(Book &&other)
{
    cout << "Move assignment operator" << endl;

    if (this != &other)
    {
        title = move(other.title);
        author = move(other.author);
        year_pub = other.year_pub;
        other.year_pub = 0;
    }
    return *this;
}

Book::~Book(){};

// overloads <<
ostream &operator<<(ostream &os, const Book &book)
{
    os << "Title: " << book.title << endl;
    os << "Author: " << book.author << endl;
    os << "Year Published: " << book.year_pub << endl;
    return os;
}

// overload >>
istream &operator>>(istream &is, Book &book)
{
    cout << "Enter Title: ";
    getline(is, book.title);

    cout << "Enter Author: ";
    getline(is, book.author);

    cout << "Enter Year Published: ";
    is >> book.year_pub;
    cin.ignore();

    return is;
}

// overloaded !=
bool operator!=(const Book &first, const Book &second)
{
    return (first.title != second.title) || (first.author != second.author) || (first.year_pub != second.year_pub);
}

// overloaded ==
bool operator==(const Book &first, const Book &second)
{
    return (first.title == second.title) && (first.author == second.author) && (first.year_pub == second.year_pub);
}

// getters
string Book::get_title() const { return title; }
string Book::get_author() const { return author; }
int Book::get_year() const { return year_pub; }
