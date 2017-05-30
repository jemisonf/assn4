#include "pokestop.h"

using namespace std;

Pokestop::Pokestop() {
	num_pokeballs = (rand() % 8) + 3;
}

int Pokestop::get_pokeballs() {
	return num_pokeballs;
}

void Pokestop::set_pokeballs(const int num) {
	num_pokeballs = num;
}

int Pokestop::run_event(Player& p) {
     	cout << "The pokestop gives you " << num_pokeballs << " pokeballs!" << endl;
	p.add_pokeballs(num_pokeballs);	
	return 1;
}

void Pokestop::get_precep() {
	cout << "Fill up on Pokeballs at the nearby Pokestop." << endl;
}

Event* Pokestop::clone() {
	return new Pokestop(*this);
}
