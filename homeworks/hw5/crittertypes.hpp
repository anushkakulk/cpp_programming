#ifndef CRITTERTYPES_HPP
#define CRITTERTYPES_HPP

// represenets all critter types
enum class CritterTypes : char
{
    db = 'X',
    queen = 'Q',
    male = 'o',
    worker = 'w'
};

class CritterTypeHelper
{
public:
    // return true if the given char is in the CritterType enum
    static bool contains(char value);
};

#endif // CRITTERTYPES_HPP