#pragma once
#include <vector>
#include <string>
#include "Recipe.h"

std::vector<Recipe> loadRecipes();
std::vector<Recipe> getBasicRecipes();
std::vector<Recipe> getAdvancedRecipes();
std::vector<Recipe> getSuperiorRecipes();
std::vector<Recipe> getSpecialRecipes();
bool isValidRawIngredient(std::string name);