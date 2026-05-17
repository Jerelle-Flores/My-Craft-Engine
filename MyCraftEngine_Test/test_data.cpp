#include "doctest.h"

#include "Data.h"

TEST_CASE("Load recipes is not empty") {

    auto recipes = loadRecipes();

    CHECK_FALSE(recipes.empty());
}

TEST_CASE("Basic recipes exist") {

    auto recipes = getBasicRecipes();

    CHECK_FALSE(recipes.empty());

    for (auto& r : recipes) {
        CHECK(r.tier == 1);
    }
}

TEST_CASE("Advanced recipes exist") {

    auto recipes = getAdvancedRecipes();

    CHECK_FALSE(recipes.empty());

    for (auto& r : recipes) {
        CHECK(r.tier == 2);
    }
}

TEST_CASE("Superior recipes exist") {

    auto recipes = getSuperiorRecipes();

    CHECK_FALSE(recipes.empty());

    for (auto& r : recipes) {
        CHECK(r.tier == 3);
    }
}

TEST_CASE("Special recipes exist") {

    auto recipes = getSpecialRecipes();

    CHECK_FALSE(recipes.empty());

    for (auto& r : recipes) {
        CHECK(r.tier == 4);
    }
}

TEST_CASE("Valid raw ingredient") {

    CHECK(
        isValidRawIngredient("Iron Ore")
    );
}

TEST_CASE("Invalid raw ingredient") {

    CHECK_FALSE(
        isValidRawIngredient("Dagger")
    );
}