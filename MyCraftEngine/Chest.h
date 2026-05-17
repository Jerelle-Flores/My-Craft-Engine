#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "Item.h"

class Chest {
public:
    std::vector<Ingredient> ingredients;
    std::vector<Tool> tools;
    std::vector<Item> items;

    void addIngredient(Ingredient ing);
    bool hasIngredients(std::vector<Ingredient> req);
    bool hasTool(std::string name, int minTier = 1);
    void removeIngredients(std::vector<Ingredient> req);
    bool hasItem(std::string name);
    void removeItem(std::string name);
};