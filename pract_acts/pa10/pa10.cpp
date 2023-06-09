// Anushka Kulkarni
// 6/8/2023
// c++ program that performs computations on Groups and Employees

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Employee
{
private:
    string employee_name;
    string email;
    string designation;
    int group_id;

public:
    // use this default constrcut for the >> overload 
    Employee() {}

    Employee(const string &name, const string &email, const string &designation, int group)
        : employee_name(name), email(email), designation(designation), group_id(group) {}

    string getEmployeeName() const
    {
        return employee_name;
    }

    string getEmail() const
    {
        return email;
    }

    string getDesignation() const
    {
        return designation;
    }

    int getGroupId() const
    {
        return group_id;
    }

    void setGroupId(int newGroupId)
    {
        group_id = newGroupId;
    }

    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);
};

ostream &operator<<(ostream &os, const Employee &employee)
{
    os << "Name: " << employee.employee_name << endl;
    os << "Email: " << employee.email << ::endl;
    os << "Designation: " << employee.designation << ::endl;
    return os;
}
istream &operator>>(istream &is, Employee &employee)
{
    cout << "Enter Employee Name: ";
     getline(is, employee.employee_name);
    cout << "Enter Employee Email: ";
    getline(is, employee.email);
    cout << "Enter Employee Designation: ";
    getline(is, employee.designation);

    return is;
}


class Group
{
private:
    string group_name;
    int group_number;
    string responsibility;
    vector<Employee *> members;

public:
    Group(const string &name, int groupNumber, const string &focus)
        : group_name(name), group_number(groupNumber), responsibility(focus) {}

    string getGroupName() const
    {
        return group_name;
    }

    int getGroupNumber() const
    {
        return group_number;
    }

    string getResponsibility() const
    {
        return responsibility;
    }

    vector<Employee *> getEmployees() const
    {
        return members;
    }

    void addEmployee(Employee *employee)
    {
        employee->setGroupId(group_number);
        members.push_back(employee);
        
    }

    // randomly removes/"fires" the given number of employes
    void removeEmployees(int count)
    {
        if (count > 0 && count <= members.size())
        {
            srand(time(0));
            random_shuffle(members.begin(), members.end());

            // since theyre getting fired, change their group ids to -1
            for (int i = 0; i < count; i++)
            {
                members[i]->setGroupId(-1);
            }
            members.erase(members.begin(), members.begin() + count);
        }
    }
    // overriding + operator and returns this group merged with the given other group
    Group operator+(const Group &other) const
    {
        string merged_name = group_name + " + " + other.group_name;
        int merged_num = group_number;
        string merged_focus = responsibility + " & " + other.responsibility;
        vector<Employee *> merged_employees = members;
        merged_employees.insert(merged_employees.end(), other.members.begin(), other.members.end());
        Group mergedGroup(merged_name, merged_num, merged_focus);

        for (size_t i = 0; i < merged_employees.size(); i++)
        {
            merged_employees[i]->setGroupId(merged_num);
            mergedGroup.addEmployee(merged_employees[i]);
        }
        return mergedGroup;
    }

    // overriding - operator and returns the group after firing the given num of employees
    Group operator-(int count) const
    {
        Group modifiedGroup = *this;
        modifiedGroup.removeEmployees(count);
        return modifiedGroup;
    }

    friend ostream &operator<<(ostream &os, const Group &group);
    friend istream &operator>>(istream &is, Group &group);
};

istream &operator>>(istream &is, Group &group)
{
    cout << "Enter Group Name: ";
    getline(is, group.group_name);

    cout << "Enter Group Number: ";
    is >> group.group_number;
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Focus Area: ";
    getline(is, group.responsibility);

    int numEmployees;
    std::cout << "Enter the number of employees in the group: ";
    is >> numEmployees;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numEmployees; ++i)
    {
        Employee* employee = new Employee;
        std::cout << "Enter details for Employee " << (i + 1) << ":" << std::endl;
        is >> *employee;
        group.addEmployee(employee);
    }


    return is;
}
ostream &operator<<(ostream &os, const Group &group)
{
    os << "Group Name: " << group.group_name << endl;
    os << "Group ID Number: " << group.group_number << endl;
    os << "Focus Area: " << group.responsibility << endl;
    os << "Employees in the group:" << endl;
    for (const auto employee : group.members)
    {
        os << *employee;
        os << endl;
    }

    return os;
}


int main()
{
    // making Group 1 in gwitter from user input- Data Analytics
    Group data_analytics_group("Data Analytics", 1, "Monitoring User Statistics");
    cout << "Enter details for Group 'Data Analytics':" << endl;
    cin >> data_analytics_group;
    cout << endl;


    //  making Group 2 in gwitter from user input (>> override)- Marketing
    Group marketingGroup("Marketing", 2, "Advertising");
    cout << "Enter details for Group 'Marketing':" << endl;
    cin >> marketingGroup;
    cout << endl;

    // prints out the two groups using << override
    cout << "Initial Details:" << endl;
    cout << data_analytics_group << endl;
    cout << marketingGroup << endl;

    // removes/fires 2 employees from group 1 
    data_analytics_group.removeEmployees(2);
    cout << "Data Analytics Group has laid off 2 employees:" << endl;
    cout << data_analytics_group << endl;

    // merge group1 and group2 groups and prints out the merged info
    Group mergedGroup = data_analytics_group + marketingGroup;
    cout << "Marketing Group has merged with Data Analytics Group:" << endl;
    cout << mergedGroup << endl;

    return 0;
}

