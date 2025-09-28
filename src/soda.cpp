#include "soda.hpp"

std::string brandToString(Brand b)
{
    switch (b)
    {
    case COCA: return "COCA";
    case PEPSI: return "PEPSI";
    case GUARANA: return "GUARANÁ";
    default: return "DESCONHECIDO";
    }
}
// soda.cpp