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

            if (!chest.hasItem("Tool Ascension")) {
                std::cout << "Missing Tool Ascension item to upgrade " << name << "\n";
                showRequirements(chest, name);
                return;
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

    for (auto& r : req) {
        double have = 0;
        for (auto& ing : chest.ingredients) {
            if (ing.name == r.name) { have = ing.quantity; break; }
        }
        std::cout << " - " << r.name << " x" << r.quantity << " (You have: " << have << ")\n";
    }

 
    if (toolName == "Universal" || toolName == "Forge Hammer" || toolName == "Mystical Arcane Table") {
        bool hasTA = chest.hasItem("Tool Ascension");
        std::cout << " - Tool Ascension (You have: " << (hasTA ? "Yes" : "No") << ")\n";
    }
}
