// Anushka Kulkarni
// 5/24/2023

#include <iostream>
#include <string.h>

struct planet
{
    const char *planet_name;
    double planet_distance;
    struct
    {
        char galaxy_system[13];
        double mass;
    } facts, *facts_ptr = &facts;
}

planet_record,
    *planet_ptr = &planet_record, all_records[5];

/*
PART 1 ORGINAL ANSWERS:

a) planet_record.planet_name // planet_name of structure planet_record
b) planet_ptr->planet_name   // planet_name of member structure pointed to by planet_ptr.
c) planet_record.planet_distance // planet_distance of structure planet_record.
d) planet_ptr->planet_distance  // planet_distance of the structure pointed to by planet_ptr.
e) planet_record.facts.mass // mass of the structure member facts of structure planet_record.
f) planet_ptr->facts_ptr->mass // mass of member pointed to by facts_ptr of the structure pointed to by planet_ptr.
g) planet_record.facts.galaxy_system // galaxy_system of the structure member facts of structure planet_record.
h) planet_ptr->facts_ptr->galaxy_system// galaxy_system of member pointed to by facts_ptr of the structure pointed to by planet_ptr.

*/

int main()
{

    planet_record.planet_name = "Mercury";
    planet_record.planet_distance = 124707049.0;
    strcpy(planet_record.facts.galaxy_system, "Milky Way");
    planet_record.facts.mass = 10000;

    std::cout << planet_record.planet_name << std::endl; // a
    std::cout << planet_ptr->planet_name << std::endl;   // b

    std::cout << planet_record.planet_distance << std::endl; // c
    std::cout << planet_ptr->planet_distance << std::endl;   // d

    std::cout << planet_record.facts.mass << std::endl;    // e
    std::cout << planet_ptr->facts_ptr->mass << std::endl; // f

    std::cout << planet_record.facts.galaxy_system << std::endl;    // g
    std::cout << planet_ptr->facts_ptr->galaxy_system << std::endl; // h

    // My initial code had no errors, and the pointers were correctly used to access
    // the structure members

    all_records[0].planet_name = "Venus";
    all_records[0].planet_distance = 23123.0;
    strcpy(all_records[0].facts.galaxy_system, "Milky Way");
    all_records[0].facts.mass = 2.0;

    all_records[1].planet_name = "Earth";
    all_records[1].planet_distance = 1.0;
    strcpy(all_records[1].facts.galaxy_system, "Milky Way");
    all_records[1].facts.mass = 3.0;

    all_records[2].planet_name = "Mars";
    all_records[2].planet_distance = 1231.0;
    strcpy(all_records[2].facts.galaxy_system, "Milky Way");
    all_records[2].facts.mass = 4.0;

    all_records[3].planet_name = "Jupiter";
    all_records[3].planet_distance = 2347986123.0;
    strcpy(all_records[3].facts.galaxy_system, "Milky Way");
    all_records[3].facts.mass = 5.0;

    all_records[4].planet_name = "Saturn";
    all_records[4].planet_distance = 334798234123.0;
    strcpy(all_records[4].facts.galaxy_system, "Milky Way");
    all_records[4].facts.mass = 6.0;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "----------" << std::endl;
        std::cout << "Planet " << i + 1 << ": " << std::endl;
        std::cout << "Name: " << all_records[i].planet_name << std::endl;
        std::cout << "Distance: " << all_records[i].planet_distance << std::endl;
        std::cout << "Galaxy System: " << all_records[i].facts.galaxy_system << std::endl;
        std::cout << "Mass: " << all_records[i].facts.mass << std::endl;
        std::cout << " " << std::endl;
    }

    // the pointer to a dynamically allocated array of records
    struct planet moreRecords[5];
    // initializing the arr
    moreRecords[0].planet_name = "hii";
    moreRecords[0].planet_distance = 0;
    strcpy(moreRecords[0].facts.galaxy_system, "Milky Way");
    moreRecords[0].facts.mass = 6.324;
    moreRecords[1].planet_name = "bar";
    moreRecords[1].planet_distance = 1;
    strcpy(moreRecords[1].facts.galaxy_system, "Milky Way");
    moreRecords[1].facts.mass = 6.43;
    moreRecords[2].planet_name = "baz";
    moreRecords[2].planet_distance = 1.5;
    strcpy(moreRecords[2].facts.galaxy_system, "Milky Way");
    moreRecords[2].facts.mass = 6.234;
    moreRecords[3].planet_name ="qux";
    moreRecords[3].planet_distance = 4;
    strcpy(moreRecords[3].facts.galaxy_system, "Milky Way");
    moreRecords[3].facts.mass = 6.1234;
    moreRecords[4].planet_name = "quux";
    moreRecords[4].planet_distance = 5;
    strcpy(moreRecords[4].facts.galaxy_system, "Milky Way");
    moreRecords[4].facts.mass = 6.6431;

    // made a pointer to dynamic arr 
    struct planet *moreRecordsPtr = moreRecords;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "----------" << std::endl;
        std::cout << "Dynamic Record " << i + 1 << ": " << std::endl;
        std::cout << "Name: " << (moreRecordsPtr + i)->planet_name << std::endl;
        std::cout << "Distance: " << (moreRecordsPtr + i)->planet_distance << std::endl;
        std::cout << "Galaxy System: " << (moreRecordsPtr + i)->facts.galaxy_system << std::endl;
        std::cout << "Mass: " << (moreRecordsPtr + i)->facts.mass << std::endl;
        std::cout << std::endl;
    }
}