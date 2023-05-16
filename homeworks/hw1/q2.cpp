// Anushka Kulkarni
// 5/15/2023
// c++ program to calculate price of Mona Lisa in 2023 
// based on different interest rates from 2.0 to 12.0

#include <iostream>
#include <iomanip>
#include <cmath> // standard math library
using namespace std;

int main()
{
   double amount = 0; // amount on deposit at end of each year
   double principal = 11.0; // initial amount before interest
   double rate = 0; // annual interest rate

   // display headers
   cout << "Interest Rate" << setw(30) << "Amount on deposit in 2023" << endl;

   // set floating-point number format
   cout << fixed << setprecision(2);

   for (rate = 2.0; rate <= 12.0; rate += 0.5) {
       // calculate amount on deposit for 397 years
       amount =  principal * pow(1.0 + (rate / 100), 397);

   
       cout << setw(7) << rate << setw(30) << amount << endl;
   } 

   return 0;
}
