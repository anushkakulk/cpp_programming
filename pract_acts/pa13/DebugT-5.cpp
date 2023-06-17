// The goal of this debug execrice is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

#include <iostream>

using namespace std;

class car
{
private:
    string name;
    int modelYear;
    

public:
    car(const string &n, const int my) : name(n), modelYear(my) {}

    string get_name() const { return name;}
    int get_year() const { return modelYear;}
    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << endl;
    }

    virtual const car &operator=(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
        return *this;
    }
// FIX: moved assign method to protected to mirror suv structure
protected:
void assign(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }
};

class sedan : public car
{
// FIX: miles is private and uses a getter
private:
    int mileage;

public:
    int get_mpg() const {return mileage;};
    sedan(const string &n, const int my, const int m) : car(n, my), mileage(m) {}

    virtual void print() const
    {
        cout << "Name: " << get_name() << " model Year: " << get_year() << " Mileage: " << get_mpg() << endl; // FIX: use getters to print
    }
};

class suv : public car
{
// FIX: miles is private and uses a getter
private:
    int miles;
   

public:
   
    int get_mpg() const {return miles;};
    suv(const string &n, const int my, const int m) : car(n, my), miles(m) {} // FIX: Creates car object

    virtual void print() const
    {
        cout << "Name: " << get_name() << " model Year: " << get_year() << " Mileage: " << get_mpg() << endl; // FIX: use getters to print
    }

    virtual const suv &operator=(const car c)
    {
        if (const suv *b = dynamic_cast<const suv *>(&c))
        {
            suv::assign(*b); // FIX: calls assign properly
        }
        return *this;
    }

protected:
    void assign(const suv &c)
    {
        car::assign(c);
        miles = c.miles;
    }
};

void printCarInfo(const car &c) // FIX: param should be deref to ensure each car type overriden print() works
{
    c.print();
}

int main()
{
    car tesla = car("tesla", 2019);
    sedan hyundai = sedan("Hyundai", 2020, 23);
    suv ford = suv("Ford", 2012, 20000);

    printCarInfo(tesla);
    printCarInfo(hyundai);

    car &ref = ford;
    printCarInfo(ref);
    suv ford2 = suv("Ford", 2017, 10000);
    ref = ford2;
    printCarInfo(ref);
    return 0;
}


/*
ALL FIXES :
- assign method is protected in both car and suv class
- used getters for all private methods
- made miles/mileage private
- deref given car argument to ensure overriden print() runs
*/