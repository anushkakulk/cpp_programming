#include "simulation.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ncurses.h>

using namespace std;

int main()
{

    int num_d;
    int num_q;
    int num_m;
    int num_w;
    cout << "" << endl;
    cout << "Welcome to DoodleBug/Ant Simulator" << endl;
    cout << "Once simulator begins, press [p]/[P] at any time to pause or [q]/[Q] to quit!" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Enter Number of DoodleBugs: ";
    cin >> num_d;
    cout << "Enter Number of Queen Ants: ";
    cin >> num_q;
    cout << "Enter Number of Male Ants: ";
    cin >> num_m;
    cout << "Enter Number of Worker Ants: ";
    cin >> num_w;
    cout << endl;

    simulation(num_d, num_q, num_m, num_w);
    return 0;
}