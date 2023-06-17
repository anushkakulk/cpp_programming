// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;
template <class T>
void findBiggest(T a, T b, T c) // FIX : takes in 3 args of tpye T
{
   T large = a;
   if (b > large) 
      large = b;
   if (c > large) // FIX: flipped '<' to '>
      large = c;
      // FIX: ensured cout prints the largest, not jsut 'a'
   cout << "The largest of " << a << ", " << b << ", and " << c << " is " << large << endl;
}

template <class T>
void findBiggest(T a, T b)
{
   T large = a;
   if (b > large) // FIX: changed from '==' to '>'
      large = b;
   cout << "The larger of " << a << " and " << b << " is " << large << endl;
}
class BankAccount
{
   friend ostream &operator<<(ostream &, const BankAccount &);

private:
   string name;
   int amount;

public:
   BankAccount(const string &, int); // FIX: bank acc constrcutor should also take in the string name
   bool operator>(const BankAccount &);
};
BankAccount::BankAccount(const string &name, const int amount)
{
   // using this-> to asign
   this->name = name;
   this->amount = amount;
}
ostream &operator<<(ostream &out, const BankAccount &bh)
{
   // FIX: access attributes using bh.*
   out << "Name " << bh.name << " Amount: " << bh.amount;
   return out;
}
bool BankAccount::operator>(const BankAccount &bh)
{
   bool flag = false; // Fix: '==' should be '='
   if (amount > bh.amount)
      flag = true;
   return flag;
}
int main()
{
   BankAccount bAA("A", 800);
   BankAccount bAB("B", 120);
   BankAccount bAC("C", 500);
   findBiggest(bAA, bAB);
   findBiggest(bAB, bAC);
   findBiggest(bAC, bAA);
   findBiggest(bAA, bAB, bAC);
   return 0;
}


/*
ALL FIXES: 
- ensured template type matched up in findBiggest method
- ensure you cant properly access bankacc fields in << overload
- fixed syntactical and logical errors throughout (noted in comments)
*/