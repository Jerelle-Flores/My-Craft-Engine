#pragma once
#include "Chest.h"
#include <string>

class SaveSystem {
public:
	static void save(Chest& chest, std::string filename);
	static void load(Chest& chest, std::string filename);
};