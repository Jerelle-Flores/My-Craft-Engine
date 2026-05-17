#include "doctest.h"

#include "ToolUpgrade.h"

TEST_CASE("Get Forge Hammer requirements") {

    auto req = ToolUpgrade::getRequirements("Forge Hammer");

    CHECK(req.size() == 2);

    CHECK(req[0].name == "Iron Ore");
    CHECK(req[1].name == "Steel Fragment");
}

TEST_CASE("Upgrade tool tier") {

    Chest chest;

    chest.tools.push_back(
        Tool("Universal", 3)
    );

    chest.tools.push_back(
        Tool("Forge Hammer", 1)
    );

    chest.addIngredient(
        Ingredient("Iron Ore", 5, "pcs")
    );

    chest.addIngredient(
        Ingredient("Steel Fragment", 5, "pcs")
    );

    chest.items.push_back(
        Item("Tool Ascension")
    );

    ToolUpgrade::upgradeTool(
        chest,
        "Forge Hammer"
    );

    CHECK(chest.tools[1].tier == 2);
}