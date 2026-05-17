#include "doctest.h"

#include "SaveSystem.h"

TEST_CASE("Save and load chest") {

    Chest chest;

    chest.addIngredient(
        Ingredient("Iron Ore", 5, "pcs")
    );

    chest.tools.push_back(
        Tool("Forge Hammer", 2)
    );

    chest.items.push_back(
        Item("Dagger")
    );

    SaveSystem::save(chest, "testsave.txt");

    Chest loaded;

    SaveSystem::load(loaded, "testsave.txt");

    CHECK(loaded.ingredients.size() == 1);
    CHECK(loaded.tools.size() == 1);
    CHECK(loaded.items.size() == 1);

    CHECK(loaded.ingredients[0].name == "Iron Ore");
    CHECK(loaded.tools[0].name == "Forge Hammer");
    CHECK(loaded.items[0].name == "Dagger");
}