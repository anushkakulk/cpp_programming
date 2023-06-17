// Debug T-1
// Function template adds objects. The function works on any object which has '+' opertor defined.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;
template <class T>
T add(T x, T y) // FIX: both args need type
{
   T sum; // FIX: sum is of the same type
   sum = x + y;
   return sum;
}
class Person
{
   friend ostream &operator<<(ostream &, const Person &);

private: 
   string lastName;
   string firstName;
   int age;

public:
   void setValues(string, string, int);
   // FIX: getters for private field
   string getLastName()const;
   string getFirstName()const;
   int getAge() const;

   Person operator+(const Person &p ); // FIX: takes in a reference
};

string Person::getLastName() const { return lastName; }
string Person::getFirstName() const { return firstName; }
int Person::getAge() const { return age; }

ostream &operator<<(ostream &out, Person & per)
{
   out << per.getFirstName() << " " << per.getLastName() << " " << per.getAge() << " years old" << endl; // used getters here
   return out; // FIX: seturn the os
}
void Person::setValues(string last, string first, int a)
{
   lastName = last;
   firstName = first;
   age = a;
}
Person Person::operator+(const Person& p) {
   Person temp;
   // FIX: adds the two using the set method
   temp.setValues("of age", "Sum" , p.getAge() + this->age);
   return temp;
}

int main()
{
   int a = 7, b = 26, c;
   double d = 39.25, e = 2.01, f;
   Person g, h, i;
   g.setValues("Mitchell", "Donald", 40);
   h.setValues("Clayton", "Rita", 35);
   c = add(a, b);
   f = add(d, e);
   i = add(g, h);
   cout << c << endl;
   cout << f << endl;
   cout << i << endl;
   
   return 0;
}


/*
ALL FIXES: 
- made getters for private firstname,lastname, and age.
- made sure operation overload takes in a reference
- ensured template type matched up in sum method
- ensure overloading << returns the os
*/