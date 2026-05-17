#include "doctest.h"

#include "CraftEngine.h"
#include "Chest.h"
#include "Ingredient.h"
#include "Tool.h"
#include "Recipe.h"

TEST_CASE("Craft item successfully") {

    Chest chest;

    chest.addIngredient(
        Ingredient("Iron Ore", 2, "pcs")
    );

    chest.addIngredient(
        Ingredient("Wood", 1, "pcs")
    );

    chest.tools.push_back(
        Tool("Forge Hammer", 1)
    );

    Recipe dagger(
        "Dagger",
        {
            Ingredient("Iron Ore", 2, "pcs"),
            Ingredient("Wood", 1, "pcs")
        },
        "Forge Hammer",
        1
    );

    CraftEngine::craft(chest, dagger);

    CHECK(chest.hasItem("Dagger"));
}

TEST_CASE("Craft fails with missing ingredients") {

    Chest chest;

    chest.tools.push_back(
        Tool("Forge Hammer", 1)
    );

    Recipe dagger(
        "Dagger",
        {
            Ingredient("Iron Ore", 2, "pcs"),
            Ingredient("Wood", 1, "pcs")
        },
        "Forge Hammer",
        1
    );

    CraftEngine::craft(chest, dagger);

    CHECK_FALSE(
        chest.hasItem("Dagger")
    );
}

TEST_CASE("Craft fails without tool") {

    Chest chest;

    chest.addIngredient(
        Ingredient("Iron Ore", 2, "pcs")
    );

    chest.addIngredient(
        Ingredient("Wood", 1, "pcs")
    );

    Recipe dagger(
        "Dagger",
        {
            Ingredient("Iron Ore", 2, "pcs"),
            Ingredient("Wood", 1, "pcs")
        },
        "Forge Hammer",
        1
    );

    CraftEngine::craft(chest, dagger);

    CHECK_FALSE(
        chest.hasItem("Dagger")
    );
}

TEST_CASE("Craft fails with low tool tier") {

    Chest chest;

    chest.items.push_back(
        Item("Magic Necklace")
    );

    chest.items.push_back(
        Item("Magic Necklace")
    );

    chest.tools.push_back(
        Tool("Forge Hammer", 1)
    );

    Recipe azureBlade(
        "Azure Blade",
        {
            Ingredient("Magic Necklace", 2, "pcs")
        },
        "Forge Hammer",
        2
    );

    CraftEngine::craft(chest, azureBlade);

    CHECK_FALSE(
        chest.hasItem("Azure Blade")
    );
}

TEST_CASE("Craft succeeds with proper tool tier") {

    Chest chest;

    chest.items.push_back(
        Item("Magic Necklace")
    );

    chest.items.push_back(
        Item("Magic Necklace")
    );

    chest.tools.push_back(
        Tool("Forge Hammer", 2)
    );

    Recipe azureBlade(
        "Azure Blade",
        {
            Ingredient("Magic Necklace", 2, "pcs")
        },
        "Forge Hammer",
        2
    );

    CraftEngine::craft(chest, azureBlade);

    CHECK(
        chest.hasItem("Azure Blade")
    );
}