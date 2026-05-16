#pragma once
#include <string>
#include <map>
#include <vector>
#include "Chest.h"
#include "Ingredient.h"

class ToolUpgrade {
public: 
    static void upgradeTool(Chest& chest, std::string toolName);
	static std::vector<Ingredient> getRequirements(std::string toolName);
	static void showRequirements(Chest& chest, std::string toolName);
};
