#include "crittertypes.hpp"

bool CritterTypeHelper::contains(char value)
{
    CritterTypes critter = static_cast<CritterTypes>(value);
    switch (critter)
    {
    case CritterTypes::db:
    case CritterTypes::queen:
    case CritterTypes::male:
    case CritterTypes::worker:
        return true;
    default:
        return false;
    }
}