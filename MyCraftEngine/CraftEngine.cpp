#include "CraftEngine.h"
#include <iostream>

void CraftEngine::craft(Chest& chest, Recipe recipe) {

    if (!chest.hasIngredients(recipe.ingredients)) {

        std::cout << "Insufficient Ingredients\n";
        return;
    }
    int requiredToolTier = 1;
    if (recipe.tier == 2) requiredToolTier = 2;
    else if (recipe.tier == 3) requiredToolTier = 3;

    if (!chest.hasTool(recipe.station, requiredToolTier)) {
        std::cout << "Required tool not found or insufficient tier: " << recipe.station << " (need tier " << requiredToolTier << ")\n";
        return;
    }
    chest.removeIngredients(recipe.ingredients);
    chest.items.push_back(Item(recipe.itemName));

    std::cout << "Crafted: " << recipe.itemName << "\n";
}