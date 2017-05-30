#include "flying.h"

Flying::Flying(int type) {
	this->type = type;
	if (type == 2) name = "Charizard";
	else if (type == 3) name = "Rayquaza";
	catch_chance = 50;
}

Event* Flying::clone() {
	return new Flying(type);
}
