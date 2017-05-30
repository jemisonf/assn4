#include "player.h"

using namespace std;

Player::Player() {
	num_pokemon = new int[6];
	level_pokemon = new int[6];
	for (int i = 0; i < 6; i++) {
		num_pokemon[i] = 0;
		level_pokemon[i] = 0;
	}	     
	num_megastones = 0;
	num_pokeballs = 0;
}


void Player::clear_mem() {
	delete [] num_pokemon;
	delete [] level_pokemon;	
}

Player::Player(const Player &p) {	
	num_pokemon = new int[6];
	level_pokemon = new int[6];
	for (int i = 0; i < 6; i++) {
		num_pokemon[i] = p.get_num_pokemon_of_type(i);
		level_pokemon[i] = p.get_level_of_type(i);
	}	     
	num_megastones = p.get_num_megastones();
	num_pokeballs = p.get_num_pokeballs();
}

void Player::operator=(const Player &p) {
     	clear_mem();
	num_pokemon = new int[6];
	level_pokemon = new int[6];
	for (int i = 0; i < 6; i++) {
		num_pokemon[i] = p.get_num_pokemon_of_type(i);
		level_pokemon[i] = p.get_level_of_type(i);
	}	     
	num_megastones = p.get_num_megastones();
	num_pokeballs = p.get_num_pokeballs();

}

Player::~Player() {
	clear_mem();
}

int* Player::get_pokemon() const {
	return num_pokemon;
}

int* Player::get_level_pokemon() const {
	return level_pokemon;
}

int Player::get_num_pokemon_of_type(int i) const {
	return num_pokemon[i];
}

int Player::get_level_of_type(int i) const {
	return level_pokemon[i];
}

int Player::get_num_pokeballs() const {
	return num_pokeballs;
}

int Player::get_num_megastones() const {
	return num_megastones;
}

void Player::add_pokemon(int type, string name) {
	num_pokemon[type] += 1;
	if (num_pokemon[type] >= 2) {
		cout << "Your " << name << " is evolving to stage 1!" << endl;
		level_pokemon[type] = 1;
		if (num_megastones > 0) {
			cout << "Your " << name << " is evolving to stage 2!" << endl;
			level_pokemon[type] = 2;
			num_megastones--;

		}
	}
}

void Player::add_pokeballs(int num_new_pokeballs) {
	num_pokeballs += num_new_pokeballs;
} 

void Player::add_megastones(int num_new_megastones) {
	num_megastones += num_new_megastones;
}

void Player::use_megastone() {
     	string choice;
	if (num_megastones > 0) {
		for (int i = 0; i < 6; i++) {
			if (level_pokemon[i] == 1 && num_megastones > 0) {
				cout << "Do you want to use a megastone to level up your " << get_pokemon_name(i) << "? Enter y or n: ";
				getline(cin, choice);
				if (choice == "y") {
					level_pokemon[i] = 2;
					num_megastones--;
				}
			}
		} 
	}	     
}

string Player::get_pokemon_name(int type) {
	switch(type) {
	     case 0: return "Geodude";
	     case 1: return "Onyx";
	     case 2: return "Charizard";
	     case 3: return "Rayquaza";
	     case 4: return "Mewtwo";
	     case 5: return "Espeon"; 
	}
}

int Player::has_megastones() {
	if (num_megastones > 0) return 1;
	else return 0;
}

int Player::has_pokeballs() {
	if (num_pokeballs > 0) return 1;
	else return 0;
}

int Player::has_all_lvl2_pokemon() {
     	int sum = 0;
	for (int i = 0; i < 6; i++) sum += level_pokemon[i];
	if (sum == 12) return 1;
	else return 0;
}

void Player::throw_pokeball() {
     	string str;
	cout << "Press enter to throw pokeball: ";
	getline(cin, str);
	num_pokeballs--;
}

void Player::show_stats() {
     	int sum = 0;
	cout << "You have " << num_pokeballs << " pokeballs and " << num_megastones << " megastones." << endl;
	if (has_all_lvl2_pokemon()) cout << "You have all the level 2 pokemon. Return to the trainer to complete the game." << endl; 
}
