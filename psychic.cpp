#include "psychic.h"

Psychic::Psychic(int type) {
	this->type = type;
	if (type == 4) name = "Mewtwo";
	else if (type == 5) name = "Espeon";
	catch_chance = 25;
}

Event* Psychic::clone() {
	return new Psychic(type);
}
