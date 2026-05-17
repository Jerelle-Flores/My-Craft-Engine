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
        // compute total available = raw quantity + crafted item count
        double rawQty = 0;
        for (auto& i : ingredients) {
            if (i.name == r.name) { rawQty = i.quantity; break; }
        }

        int craftedCount = 0;
        for (auto& it : items) {
            if (it.name == r.name) craftedCount++;
        }

        double totalAvailable = rawQty + craftedCount;
        if (totalAvailable < r.quantity) return false;
    }
    return true;
}

bool Chest::hasTool(std::string name, int minTier) {

    for (auto& t : tools) {
        // a "Universal" tool should satisfy any station requirement
        if (t.name == "Universal" && t.tier >= minTier) return true;

        // exact match with minimum tier
        if (t.name == name && t.tier >= minTier)
            return true;
    }

    return false;
}

void Chest::removeIngredients(std::vector<Ingredient> req) {
    for (auto r : req) {
        // remove from raw ingredients first
        double remaining = r.quantity;
        for (auto& i : ingredients) {
            if (i.name == r.name && remaining > 0) {
                double take = std::min(i.quantity, remaining);
                i.quantity -= take;
                remaining -= take;
                // do not break; in case multiple raw entries exist (shouldn't)
            }
        }

        // then remove crafted items for any remaining amount (one crafted item == 1 unit)
        for (auto it = items.begin(); it != items.end() && remaining > 0; ) {
            if (it->name == r.name) {
                it = items.erase(it);
                remaining -= 1.0;
            }
            else ++it;
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