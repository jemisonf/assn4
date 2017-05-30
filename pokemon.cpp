#include "pokemon.h"

using namespace std;

int Pokemon::get_type() const {
	return type;	
}

std::string Pokemon::get_name() const {
	return name;
}

int Pokemon::run_event(Player&p) {
     	string choice;
	cout << "You see a " << name << ". Do you want to try to catch it? Enter y or n: ";
	getline(cin, choice);
	if (choice == "y") {
		if (p.has_pokeballs()) {
			p.throw_pokeball();
			if (is_caught()) {
			     	cout << "You catch the " << name << "!" << endl;
				p.add_pokemon(type, name);
				return 1;
			} else {
				cout << "You fail to catch the " << name << "." << endl;
				return 0;
			}
		} else {
			cout << "You don't have any pokeballs!" << endl;
			return 0;
		}
	}
}

void Pokemon::get_precep() {
	cout << "Capture the " << name << " nearby!" << endl;
}

Event* Pokemon::clone() {
	return new Pokemon(*this);
}

int Pokemon::is_caught() {
	if ((rand() % 100) < catch_chance) {
		return 1;
	} else {
		return 0;
	}
}
