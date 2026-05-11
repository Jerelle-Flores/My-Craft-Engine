#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe {
public:
	std::string itemName;
	std::vector<Ingredient> ingredients;
	std::string station = "";
	int tier = 1;

	Recipe();

	Recipe(std::string name, std::vector<Ingredient> ing, std::string s, int t);
};