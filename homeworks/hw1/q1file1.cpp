/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/
#include <iostream>

int main()
{
    int limit = 10;
    int even_product = 1;
    int odd_product = 1;
    int sum;
    char c;

    std::cout << "The value of limit is " << limit << std::endl;
    // iterates from 1 until the limit and changes either the even_product or odd_product
    // to multiply itself by the current number (depending on if the number is even/odd)
    for (int i = 1; i <= limit; i += 1)
    {
        if (i % 2 == 0)
        {
            even_product *= i;
        }
        else
        {
            odd_product *= i;
        }
    }
    // after iterating, calculates and prints the final sum of products of even and odd
    sum = even_product + odd_product;
    std::cout << "The Sum = " << sum << std::endl;

    for (c = 'z'; c >= 'a'; c -= 2)
    {
        std::cout << " " << c;
    }

    return 0;
}

/* ALL FIXES:

 FIXES FOR THE LIMIT/SUM PORTION

    - gave each variable a clear and separate definition and instantiation
    - changed even and odd products to initially be at 1 (since we are multiplying them by numbers)
    - changed limit to initially be at 10, since that is our limit and our for loop should increment until then
    - changed fo
    - included 'std::' for all output statements
    - changed conditional statement to be an if-else block
    - to check for evenness : i % 2 == 0
    - ensured '==' in conditional statements
    - since we are multiplying the built-up even and odd products by i, we use '*='
    - sum calculation happens after iterating through for loop
    - fixed for loop to use semicolons instead colons

 FIXED FOR THE ALPHABET PORTION

    - for loop should iterate from z to a (decrementing by 2 each time)
    - changed stopping condition of for loop from <= a to >= a
*/