#include "ToolUpgrade.h"
#include <iostream>
#include <algorithm>

void ToolUpgrade::upgradeTool(Chest& chest, std::string name) {

    for (auto& t : chest.tools) {
        if (t.name == name) {
            if (!chest.hasTool("Universal")) {
                std::cout << "Universal tool is required to perform upgrades.\n";
                showRequirements(chest, name);
                return;
            }
            auto req = getRequirements(name);
            // determine Tool Ascension requirement based on current tool tier
            int ascNeeded = 0;
            if (t.tier == 1) ascNeeded = 1; // upgrading to tier 2
            else if (t.tier == 2) ascNeeded = 2; // upgrading to tier 3

            if (ascNeeded > 0) {
                req.push_back(Ingredient("Tool Ascension", ascNeeded, "pcs"));
            }

            if (!chest.hasIngredients(req)) {
                std::cout << "Missing ingredient requirements to upgrade " << name << "\n";
                showRequirements(chest, name);
                return;
            }
            chest.removeIngredients(req);

            t.upgrade();

            std::cout << "Tool upgraded to Tier " << t.tier << "\n";
            return;
        }
    }

    std::cout << "Tool not found\n";
}

std::vector<Ingredient> ToolUpgrade::getRequirements(std::string toolName) {
    if (toolName == "Forge Hammer") {
        return { Ingredient("Iron Ore", 5, "pcs"), Ingredient("Steel Fragment", 5, "pcs") };
    }
    if (toolName == "Mystical Arcane Table") {
        return { Ingredient("Magic Dust", 5, "pcs"), Ingredient("Mana Crystal", 5, "pcs") };
    }
    if (toolName == "Guardian Sigil") {
        return { Ingredient("Crystal Shard", 5, "pcs"), Ingredient("Dark Essence", 5, "pcs") };
    }
    if (toolName == "Universal") {
        return { Ingredient("Energy Core", 5, "pcs"), Ingredient("Magic Dust", 5, "pcs") };
    }

    return {};
}

void ToolUpgrade::showRequirements(Chest& chest, std::string toolName) {
    auto req = getRequirements(toolName);
    std::cout << "Requirements to upgrade " << toolName << ":\n";
    if (req.empty()) {
        std::cout << " - None\n";
        return;
    }
    // show each ingredient along with how much the player has
    for (auto& r : req) {
        double rawHave = 0;
        for (auto& ing : chest.ingredients) {
            if (ing.name == r.name) { rawHave = ing.quantity; break; }
        }

        int craftedCount = 0;
        for (auto& it : chest.items) {
            if (it.name == r.name) craftedCount++;
        }

        double totalHave = rawHave + craftedCount;
        std::cout << " - " << r.name << " x" << r.quantity << " (You have: " << totalHave << ")\n";
    }

    // determine ascension requirement based on current tool tier
    int ascNeeded = 0;
    for (auto& t : chest.tools) {
        if (t.name == toolName) {
            if (t.tier == 1) ascNeeded = 1;
            else if (t.tier == 2) ascNeeded = 2;
            break;
        }
    }

    if (ascNeeded > 0) {
        int taCount = 0;
        // count Tool Ascension items in crafted items
        for (auto& it : chest.items) {
            if (it.name == "Tool Ascension") taCount++;
        }
        // also include any raw quantity entries named "Tool Ascension" (if present)
        for (auto& ing : chest.ingredients) {
            if (ing.name == "Tool Ascension") taCount += (int)ing.quantity;
        }

        std::cout << " - Tool Ascension x" << ascNeeded << " (You have: " << taCount << ")\n";
    }
}
