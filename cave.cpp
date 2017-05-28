#include "cave.h"

using namespace std;

Cave::Cave() {
	num_stones = 1;
}

void Cave::get_precep() {
	cout << "You see a precious stone nearby." << endl;
}
/*
void Cave::run_event(Player &p) {
	cout << "You have found a cave containing " << num_stones << " Megastone(s). You add them to your inventory." << endl;
	p.add_megastones(num_stones);
	p.level_pokemon_to_stage_two();
}
*/

void Cave::run_event(Player &p) {
	
}
Event* Cave::clone() {
	return new Cave(*this);
} 
