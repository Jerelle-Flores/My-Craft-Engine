#pragma once
#include <string>
#include <map>
#include <vector>
#include "Chest.h"
#include "Ingredient.h"

class ToolUpgrade {
public: 
	static void upgradeTool(Chest& chest, std::string toolName);
};
