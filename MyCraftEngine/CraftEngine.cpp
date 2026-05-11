#include "CraftEngine.h"
#include <iostream>

void CraftEngine::craft(Chest& chest, Recipe recipe) {

    if (!chest.hasIngredients(recipe.ingredients)) {

        std::cout << "Insufficient Ingredients\n";
        return;
    }

    if (!chest.hasTool(recipe.station)) {

        std::cout << "Required tool not found: " << recipe.station << "\n";

        return;
    }
    chest.removeIngredients(recipe.ingredients);
    chest.items.push_back(Item(recipe.itemName)
    );

    std::cout << "Crafted: " << recipe.itemName << "\n";
}