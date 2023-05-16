// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

#include<iostream>
  
int main(){
   char digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   std::cout<< "Hello, I am a telemarketing calling making program.\n";
   std::cout<< "Enter a three-digit area code ";
   std::cin >> areaCode;
   std::cout<< "Enter a three-digit exchange to call ";
   std::cin >> exchange;
   std::cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!" << std::endl;
   for(digit1 = '0'; digit1 <= '9'; ++digit1){
        for(digit2 = '0'; digit2 <= '9'; ++digit2){
            for(digit3 = '0'; digit3 <= '9'; ++digit3) {
               for(digit4 = '0'; digit4 <= '9'; ++digit4) {
                std::cout<< "Dialing "<< areaCode<<" - "<< exchange<<" - ";
                std::cout<< digit1 << digit2 <<digit3 << digit4 <<std::endl;
            }
        }
    }
}
   std::cout<< "\nCalls completed"<<std::endl;
   return 0;

}

/* ALL FIXES: 
    - semicolon separating statements in for loops
    - total of 4 for loops, incrementing digit1, digit2, digit3, and digit4 
        from 0 until 10, respectively
    - the digits are not ints, but chars, so they should start at '0' not 0 and go 
        until equal to '9' not 9
    - ensured using std library for cout, cin, and endl
    - main method is not void, so we must return something 
    - 

*/