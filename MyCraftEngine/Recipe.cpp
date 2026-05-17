#include "Recipe.h"

Recipe::Recipe(std::string name, std::vector<Ingredient> ing, std::string s, int t) {
    itemName = name;
    ingredients = ing;
    station = s;
    tier = t;
}