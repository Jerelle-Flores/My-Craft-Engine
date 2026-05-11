#include "SaveSystem.h"
#include <fstream>
#include <iostream>

void SaveSystem::save(Chest& chest, std::string file) {

    std::ofstream out(file);

    for (auto& i : chest.ingredients)
        out << "I\n" << i.name << "\n" << i.quantity << "\n";

    for (auto& t : chest.tools)
        out << "T\n" << t.name << "\n" << t.tier << "\n";

    for (auto& it : chest.items)
        out << "IT\n" << it.name << "\n";
}
void SaveSystem::load(Chest& chest, std::string file) {

    std::ifstream in(file);

    if (!in.is_open()) {

        std::cout << "No save file found. Starting new game.\n";
        return;
    }

    chest.ingredients.clear();
    chest.tools.clear();
    chest.items.clear();

    std::string type;

    while (in >> type) {

        in.ignore();

        if (type == "I") {

            std::string n;
            double q;

            std::getline(in, n);
            in >> q;

            chest.ingredients.push_back(
                Ingredient(n, q, "pcs")
            );
        }

        else if (type == "T") {

            std::string n;
            int t;

            std::getline(in, n);
            in >> t;

            chest.tools.push_back(Tool(n, t));
        }

        else if (type == "IT") {

            std::string n;

            std::getline(in, n);

            chest.items.push_back(Item(n));
        }
    }
}