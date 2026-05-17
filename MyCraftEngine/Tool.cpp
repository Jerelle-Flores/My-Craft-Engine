#include "Tool.h"

Tool::Tool(std::string n, int t) {
		name = n;
		tier = t;
}

void Tool::upgrade() {
	if (tier < 3) tier++;
}