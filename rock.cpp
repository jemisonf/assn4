#include "rock.h"

Rock::Rock(int type) {
	this->type = type;
	if (type == 0) name = "Geodude";
	else if (type == 1) name = "Onyx";
	catch_chance = 75;
}

Event* Rock::clone() {
	return new Rock(type);
}
