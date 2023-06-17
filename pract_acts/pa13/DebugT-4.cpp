// Debug T-5
/* Calculator class uses template class to perform arithmetic operations on different types of data.
 *  It also has function to determine which value is greater which return a boolean type.
 */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>

using namespace std;
// class to perform various operations on two variables of type T
template <class T>
class Calculator
{
private:
    T num1;
    T num2;

public:
    Calculator(T n1, T n2);
    T add();
    T subtract();
    T multiply();
    T divide();
    bool isgreater();
};

template <class T>
Calculator<T>::Calculator(T n1, T n2) // FIX: takes in both T types
{
    num1 = n1;
    num2 = n2;
}

template <class T>
T Calculator<T>::add() // FIX: added T return type
{
    return num1 + num2;
}

template <class T>
T Calculator<T>::subtract() // FIX: added T return type
{
    return num1 - num2;
}

template <class T>
T Calculator<T>::multiply() // FIX: should not take any args
{
    return num1 * num2;
}

template <class T>
T Calculator<T>::divide()
{
    return num1 / num2; // FIX: division is / not modulo
}

template <class T>
bool Calculator<T>::isgreater() // FIX: returns a bool not T
{
    return (num1 > num2); // FIX: lol fixed redundant if-else

}

int main()
{
    Calculator<int> calc(10, 4); // int operations
    cout << calc.add() << endl;
    cout << calc.subtract() << endl;
    cout << calc.multiply() << endl;
    cout << calc.divide() << endl;
    cout << std::boolalpha << calc.isgreater() << endl;

    Calculator<double> calc2(10.234, 4.235); // double operations
    cout << calc2.add() << endl;
    cout << calc2.subtract() << endl;
    cout << calc2.multiply() << endl;
    cout << calc2.divide() << endl;
    cout << std::boolalpha << calc2.isgreater() << endl;

    Calculator<string> calc3("Hello", "1"); // string operations //FIX: made both args strings
    cout << calc3.add() << endl;
    cout << std::boolalpha << calc3.isgreater() << endl;
    return 0;
}


/*
ALL FIXES
- ensured constructor took two args of T 
- ensured all operation methods took in no args and returned type T
    - for isgreater(), method should return a bool
- fixed minor synactical and logical throughout, noted in comments
*/