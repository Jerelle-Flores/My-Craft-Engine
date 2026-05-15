#include "Data.h"


std::vector<std::string> validRawIngredients = {

    "Iron Ore",
    "Wood",
    "Leather",
    "Cloth",

    "Mana Crystal",
    "Magic Dust",
    "Crystal Shard",

    "Beast Fang",
    "Energy Core",
    "Steel Fragment",
    "Dark Essence"
};

bool isValidRawIngredient(std::string name) {

    for (auto& item : validRawIngredients) {

        if (item == name)
            return true;
    }

    return false;
}



std::vector<Recipe> loadRecipes() {

    std::vector<Recipe> r;


    Ingredient iron("Iron Ore", 2, "pcs");
    Ingredient iron1("Iron Ore", 1, "pcs");

    Ingredient wood("Wood", 1, "pcs");
    Ingredient wood2("Wood", 2, "pcs");

    Ingredient leather("Leather", 3, "pcs");
    Ingredient cloth("Cloth", 1, "pcs");
    Ingredient cloth2("Cloth", 2, "pcs");

    Ingredient mana("Mana Crystal", 2, "pcs");
    Ingredient dust("Magic Dust", 2, "pcs");
    Ingredient shard("Crystal Shard", 1, "pcs");
    Ingredient shard2("Crystal Shard", 2, "pcs");

    Ingredient fang("Beast Fang", 2, "pcs");
    Ingredient energy("Energy Core", 1, "pcs");
    Ingredient steel("Steel Fragment", 1, "pcs");
    Ingredient dark("Dark Essence", 1, "pcs");

    r.push_back(
        Recipe(
            "Dagger",
            { iron, wood },
            "Forge Hammer",
            1
        )
    );

    r.push_back(
        Recipe(
            "Knife",
            { iron1, steel },
            "Forge Hammer",
            1
        )
    );

    r.push_back(
        Recipe(
            "Javelin",
            { wood2, iron },
            "Forge Hammer",
            1
        )
    );

    r.push_back(
        Recipe(
            "Vampire Mallet",
            {
                Ingredient("Wood", 1, "pcs"),
                Ingredient("Beast Fang", 2, "pcs"),
                Ingredient("Dark Essence", 1, "pcs")
            },
            "Forge Hammer",
            1
        )
    );

    r.push_back(
        Recipe(
            "Mystery Codex",
            { dust, cloth },
            "Mystical Arcane Table",
            1
        )
    );

    r.push_back(
        Recipe(
            "Book of Sages",
            {
                Ingredient("Mystery Codex", 1, "pcs"),
                Ingredient("Mana Crystal", 2, "pcs")
            },
            "Mystical Arcane Table",
            1
        )
    );

    r.push_back(
        Recipe(
            "Magic Necklace",
            {
                Ingredient("Mana Crystal", 2, "pcs"),
                Ingredient("Crystal Shard", 1, "pcs")
            },
            "Mystical Arcane Table",
            1
        )
    );



    r.push_back(
        Recipe(
            "Vitality Crystal",
            {
                Ingredient("Crystal Shard", 2, "pcs"),
                Ingredient("Energy Core", 1, "pcs")
            },
            "Guardian Sigil",
            1
        )
    );

    r.push_back(
        Recipe(
            "Leather Jerkin",
            {
                Ingredient("Leather", 3, "pcs"),
                Ingredient("Cloth", 1, "pcs")
            },
            "Guardian Sigil",
            1
        )
    );

    r.push_back(
        Recipe(
            "Magic Resist Cloak",
            {
                Ingredient("Cloth", 2, "pcs"),
                Ingredient("Mana Crystal", 1, "pcs")
            },
            "Guardian Sigil",
            1
        )
    );


    r.push_back(
        Recipe(
            "Silence Robe",
            {
                Ingredient("Vitality Crystal", 1, "pcs"),
                Ingredient("Magic Resist Cloak", 1, "pcs")
            },
            "Guardian Sigil",
            2
        )
    );

    r.push_back(
        Recipe(
            "Steel Legplates",
            {
                Ingredient("Leather Jerkin", 1, "pcs")
            },
            "Guardian Sigil",
            2
        )
    );

    r.push_back(
        Recipe(
            "Ares Belt",
            {
                Ingredient("Vitality Crystal", 1, "pcs")
            },
            "Guardian Sigil",
            2
        )
    );

    r.push_back(
        Recipe(
            "Magic Wand",
            {
                Ingredient("Mystery Codex", 1, "pcs")
            },
            "Mystical Arcane Table",
            2
        )
    );

    r.push_back(
        Recipe(
            "Exotic Veil",
            {
                Ingredient("Mystery Codex", 1, "pcs")
            },
            "Mystical Arcane Table",
            2
        )
    );

    r.push_back(
        Recipe(
            "Tome of Evil",
            {
                Ingredient("Magic Necklace", 1, "pcs"),
                Ingredient("Book of Sages", 1, "pcs")
            },
            "Mystical Arcane Table",
            2
        )
    );

    r.push_back(
        Recipe(
            "Azure Blade",
            {
                Ingredient("Magic Necklace", 2, "pcs")
            },
            "Forge Hammer",
            2
        )
    );

    r.push_back(
        Recipe(
            "Legion Sword",
            {
                Ingredient("Dagger", 2, "pcs")
            },
            "Forge Hammer",
            2
        )
    );

    r.push_back(
        Recipe(
            "Regular Spear",
            {
                Ingredient("Knife", 1, "pcs"),
                Ingredient("Dagger", 1, "pcs")
            },
            "Forge Hammer",
            2
        )
    );

    r.push_back(
        Recipe(
            "Rogue Meteor",
            {
                Ingredient("Knife", 1, "pcs"),
                Ingredient("Javelin", 1, "pcs")
            },
            "Forge Hammer",
            2
        )
    );

    r.push_back(
        Recipe("Athena's Shield",{
            Ingredient("Silence Robe", 1, "pcs"),
            Ingredient("Vitality Crystal", 1, "pcs")
            },
            "Guardian Sigil",3
        )
    );

    r.push_back(
        Recipe(
            "Chastise Pauldron",
            {
                Ingredient("Steel Legplates", 1, "pcs"),
                Ingredient("Ares Belt", 1, "pcs")
            },
            "Guardian Sigil",
            3
        )
    );

    r.push_back(
        Recipe(
            "Blade Armor",
            {
                Ingredient("Steel Legplates", 1, "pcs"),
                Ingredient("Leather Jerkin", 2, "pcs")
            },
            "Guardian Sigil",
            3
        )
    );

   

    r.push_back(
        Recipe(
            "Blood Wings",
            {
                Ingredient("Magic Wand", 2, "pcs")
            },
            "Mystical Arcane Table",
            3
        )
    );

    r.push_back(
        Recipe(
            "Genius Wand",
            {
                Ingredient("Exotic Veil", 1, "pcs"),
                Ingredient("Magic Wand", 1, "pcs")
            },
            "Mystical Arcane Table",
            3
        )
    );

    r.push_back(
        Recipe(
            "Glowing Wand",
            {
                Ingredient("Exotic Veil", 1, "pcs"),
                Ingredient("Mystery Codex", 1, "pcs"),
                Ingredient("Vitality Crystal", 1, "pcs")
            },
            "Mystical Arcane Table",
            3
        )
    );

    r.push_back(
        Recipe(
            "Enchanted Talisman",
            {
                Ingredient("Tome of Evil", 1, "pcs"),
                Ingredient("Magic Necklace", 1, "pcs"),
                Ingredient("Magic Wand", 1, "pcs")
            },
            "Mystical Arcane Table",
            3
        )
    );

    r.push_back(
        Recipe(
            "Starlium Scythe",
            {
                Ingredient("Azure Blade", 1, "pcs"),
                Ingredient("Book of Sages", 1, "pcs"),
                Ingredient("Magic Wand", 1, "pcs")
            },
            "Mystical Arcane Table",
            3
        )
    );

    // ---------- PHYSICAL ----------

    r.push_back(
        Recipe(
            "Blade of Despair",
            {
                Ingredient("Legion Sword", 2, "pcs")
            },
            "Forge Hammer",
            3
        )
    );

    r.push_back(
        Recipe(
            "Sea Healberd",
            {
                Ingredient("Legion Sword", 1, "pcs"),
                Ingredient("Regular Spear", 1, "pcs")
            },
            "Forge Hammer",
            3
        )
    );

    r.push_back(
        Recipe(
            "Demon Hunter Sword",
            {
                Ingredient("Regular Spear", 1, "pcs"),
                Ingredient("Vampire Mallet", 1, "pcs"),
                Ingredient("Knife", 1, "pcs")
            },
            "Forge Hammer",
            3
        )
    );

    r.push_back(
        Recipe(
            "Berserker's Fury",
            {
                Ingredient("Legion Sword", 1, "pcs"),
                Ingredient("Javelin", 2, "pcs")
            },
            "Forge Hammer",
            3
        )
    );

    r.push_back(
        Recipe(
            "Haas' Claw",
            {
                Ingredient("Vampire Mallet", 1, "pcs"),
                Ingredient("Rogue Meteor", 1, "pcs"),
                Ingredient("Dagger", 1, "pcs")
            },
            "Forge Hammer",
            3
        )
    );


    r.push_back(
        Recipe(
            "Tool Ascension",
            {
                Ingredient("Iron Ore", 1, "pcs"),
                Ingredient("Magic Dust", 1, "pcs"),
                Ingredient("Steel Fragment", 1, "pcs")
            },
            "Universal",
            4
        )
    );

    return r;
}


std::vector<Recipe> getBasicRecipes() {

    std::vector<Recipe> result;

    for (auto& r : loadRecipes()) {

        if (r.tier == 1)
            result.push_back(r);
    }

    return result;
}


std::vector<Recipe> getAdvancedRecipes() {

    std::vector<Recipe> result;

    for (auto& r : loadRecipes()) {

        if (r.tier == 2)
            result.push_back(r);
    }

    return result;
}


std::vector<Recipe> getSuperiorRecipes() {

    std::vector<Recipe> result;

    for (auto& r : loadRecipes()) {

        if (r.tier == 3)
            result.push_back(r);
    }

    return result;
}

std::vector<Recipe> getSpecialRecipes() {

    std::vector<Recipe> result;

    for (auto& r : loadRecipes()) {

        if (r.tier == 4)
            result.push_back(r);
    }

    return result;
}