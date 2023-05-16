/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */
#include<iostream>

int main(void){
    int num, i;
    bool factor_found = false;
    std::cout<<"Enter Number:\n";
    std::cin>>num;
    if(num == 0 || num == 1) {
        std::cout<<num<<" is not prime or composite"<< std::endl;
    } else if (num > 1) {
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                factor_found = true;
                break;
            }
        }

        if (factor_found) {
            std::cout << num << " is a composite number" << std::endl;
        } else {
            std::cout << num << " is a prime number"<< std::endl;
        }

    } else {
        std::cout << "negative numbers cannot be prime/composite "<< std::endl;
    }
    
}

/* ALL FIXES
    - iostream, not iosteam
    - conditions should first check if num == 0 || num == 1, then check if num > 1. if none of
        these conditions, then return that negative numbers cannot be prime or composite
    - if factor_found is true, then the num is compositite, not prime.
    - false and true are correct options for a boolean, not False and True

*/