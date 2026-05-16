#include "Chest.h"

bool isAllowed(std::string name) {
    std::string allowed[] = {
        "Iron Ore","Wood","Leather","Cloth","Mana Crystal",
        "Magic Dust","Crystal Shard","Beast Fang",
        "Energy Core","Steel Fragment","Dark Essence"
    };

    for (auto& a : allowed)
        if (a == name) return true;

    return false;
}

void Chest::addIngredient(Ingredient ing) {

    if (!isAllowed(ing.name)) {
        return; // reject non-raw items
    }

    for (auto& i : ingredients) {
        if (i.name == ing.name) {
            i.quantity += ing.quantity;
            return;
        }
    }

    ingredients.push_back(ing);
}

bool Chest::hasIngredients(std::vector<Ingredient> req) {
    for (auto r : req) {
        bool found = false;
        for (auto& i : ingredients) {
            if (i.name == r.name && i.quantity >= r.quantity)
                found = true;
        }
        if (!found) return false;
    }
    return true;
}

bool Chest::hasTool(std::string name) {

    for (auto& t : tools) {
        // exact match
        if (t.name == name)
            return true;

        // a "Universal" tool should satisfy any station requirement
        if (t.name == "Universal")
            return true;
    }   

    return false;
}

void Chest::removeIngredients(std::vector<Ingredient> req) {
    for (auto r : req) {
        for (auto& i : ingredients) {
            if (i.name == r.name)
                i.quantity -= r.quantity;
        }
    }
}

bool Chest::hasItem(std::string name) {
    for (auto& it : items) {
        if (it.name == name) return true;
    }
    return false;
}

void Chest::removeItem(std::string name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            items.erase(it);
            return;
        }
    }
}