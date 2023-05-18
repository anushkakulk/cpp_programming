// Anushka Kulkarni
// 5/17/2023
// c++ program that defines a class representing a car, with two public
// and two private member variables.

#include <iostream>
using namespace std;

class Car {
public:
    static int total_cars_made;
    string company;
    string model;
private:
    static string manufacturer;
    int id_number;

public:
    Car (const string& carCompany, const string& carModel, int carId) {
        company = carCompany;
        model = carModel;
        id_number = carId;
        total_cars_made++;
    }

    void displayCarInfo() {
        cout << "Manufacturer: " << manufacturer << " | Variable memory address: " << &manufacturer << endl;
        cout << "Company: " << company << " | Variable memory address: " << &company << endl;
        cout << "Model: " << model  << " | Variable memory address: " << &model << endl;
        cout << "ID number : " << id_number  << " | Variable memory address: " << &id_number << endl;
        cout << "Total cars made: " << total_cars_made << " | Variable memory address: " << &total_cars_made << endl;
    }

    static void displayTotalCarsMade() {
        cout << "Total cars made: " << total_cars_made << endl;
    }
};

int Car::total_cars_made = 0;
string Car::manufacturer = "Anushka Motors";

void printMemoryAddress(Car& car) {
    cout << &car << endl;
}

int main(void) {
    Car car1("Honda", "Civic", 0001);
    Car car2("Tesla", "X", 0002);

    cout << "car1's memory address : ";
    printMemoryAddress(car1);
    cout << "car2's memory address : ";
    printMemoryAddress(car2);
    cout << "--------------" << endl;
    cout << "CAR1 DETAILS " << endl;
    car1.displayCarInfo();
    cout << "--------------" << endl;
    cout << "CAR2 DETAILS " << endl;
    car2.displayCarInfo();
    cout << "--------------" << endl;
    Car::displayTotalCarsMade();

    return 0;
}


/* observations:
the memory addresses for the static variable is the same, 
even though there are different objects, meaning that the 
static fields are shared memory between all Car objects. The non-static variables
have different memory addresses, which makes sense since those variables are unique to 
the object, not shared within the class.  
*/ 
