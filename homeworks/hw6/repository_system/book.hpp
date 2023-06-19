#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string title;
    string author;
    int year_pub;

public:
    Book(){};

    // normal constructor
    Book(const string &title, const string &author, int year_pub);

    // copy constructor
    Book(const Book &other);

    // move constructor
    Book(Book &&other);

    // copy assignment op
    Book &operator=(const Book &other);

    // move assignmetn op
    Book &operator=(Book &&other);

    // destructor
    ~Book();

    // prints out book
    friend ostream &operator<<(ostream &os, const Book &book);

    // takes in a book
    friend istream &operator>>(istream &is, Book &book);

    // overload !=
    friend bool operator!=(const Book &first, const Book &second);

    // overload ==
    friend bool operator==(const Book &first, const Book &second);

    // Getters
    string get_title() const;
    string get_author() const;
    int get_year() const;
};

#endif // BOOK_HPP