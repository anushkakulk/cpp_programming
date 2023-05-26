// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25


//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.


#include<iostream>
using namespace std;
bool isPalindrome(int x); 

int main() {
        int input;
	cout << "enter an integer please: "; 
        cin >> input;
        bool returned_val = isPalindrome(input);

        if (returned_val) { 
                cout<<"It is a palindrome"<<endl;
        }
        else{
                cout<<"It is not a palindrome"<<endl;
        }
		
		return 0;
}

//the return value of your func should be true / false only
bool isPalindrome(int n) {
            int given_number = n;
            long reversed = 0;
            int remainder; 

            while (n != 0) {
		remainder = n % 10;	
                reversed = reversed * 10 + remainder;   
                n = n/10;    
            }

            return (given_number == reversed);
          
}


/* FIXES

- added using namespace std
- func is changed to name "isPalindrome" and only takes in an int
- stores user input as an int
- func/isPalindrome returns a bool, its not void
- added quotes to cout in if block and added ';' at the end of statement
- changed main return type to int, its not void
- in func/isPalindrome, it should be while n!=0, not while n = 0
- remainder % 10, not remainder / 10
- changed temp name to reversed (better naming)
- it isnt just n/10, its n = n/10;
- we want to check if given_number == temp/reversed, not if n == temp/reversed
- if given_number == temp/reversed, we want to return true, not false
- if returned_value is true, then in the main, we want to cout "it is a palindrome" 
*/