#include "ToolUpgrade.h"
#include <iostream>

void ToolUpgrade::upgradeTool(Chest& chest, std::string name) {

    for (auto& t : chest.tools) {
        if (t.name == name) {
            t.upgrade();
            std::cout << "Tool upgraded to Tier " << t.tier << "\n";
            return;
        }
    }

    std::cout << "Tool not found\n";
}