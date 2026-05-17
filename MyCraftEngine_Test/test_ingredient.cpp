#include "doctest.h"
#include "Ingredient.h"

TEST_CASE("Ingredient constructor stores values correctly") {

    Ingredient ing("Iron Ore", 5, "pcs");

    CHECK(ing.name == "Iron Ore");
    CHECK(ing.quantity == 5);
    CHECK(ing.unit == "pcs");
}

TEST_CASE("Ingredient supports decimal quantity") {

    Ingredient ing("Magic Dust", 2.5, "pcs");

    CHECK(ing.quantity == 2.5);
}

TEST_CASE("Ingredient stores different units") {

    Ingredient ing("Water", 1, "liters");

    CHECK(ing.unit == "liters");
}