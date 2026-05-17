#pragma once
#include <string>

class Ingredient {
public:
    std::string name;
    double quantity;
    std::string unit;

    Ingredient(std::string n, double q, std::string u);
};