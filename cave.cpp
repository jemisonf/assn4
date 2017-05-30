#include "cave.h"

using namespace std;

Cave::Cave() {
	num_stones = 1;
}

void Cave::get_precep() {
	cout << "You see a precious stone nearby." << endl;
}

int Cave::run_event(Player &p) {
	cout << "You have found a cave containing " << num_stones << " Megastone(s). You add them to your inventory." << endl;
	p.add_megastones(num_stones);
	p.use_megastone();
	return 1;
}


Event* Cave::clone() {
	return new Cave(*this);
} 
