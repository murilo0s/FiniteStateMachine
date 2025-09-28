#ifndef SODA_HPP
#define SODA_HPP

#include <string>

enum Brand
{
    COCA,
    PEPSI,
    GUARANA
};

struct Soda
{
    Brand brandName;
    int inventory;
    int price;
};

std::string brandToString(Brand b);

#endif
// soda.hpp