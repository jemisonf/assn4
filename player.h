#ifndef PLAYER_H
#define PLAYER_H

#include "pokemon.h"
#include "rock.h"
#include "psychic.h"
#include "flying.h"

class Player {
	private:
     		int *num_pokemon;
		int num_megastones;
		int *level_pokemon;
		int num_pokeballs;
	public:
		int* get_pokemon();
		int get_num_pokemon_of_type(int);
		int* get_level_pokemon();
		int get_level_of_type(int);
		int get_num_pokeballs();
		int get_num_megastones();
		
		void set_pokemon(int*);
		void set_pokemon_levels(int*);
		void set_pokemon_of_type(int, int); // type, num
		void set_level_of_type(int, int); // type, level
		void set_pokeballs(int);
		void set_megastones(int);

		void add_pokeballs(int);
		void add_megastones(int);
		void add_pokemon(Pokemon&);
		void add_pokeball(int); // number of pokeballs
		void add_megastone(int); // number of megastones

		void throw_pokeball(); // decrement pokeballs by one
		int has_pokeballs(); // return 1 if player has >0 pokeballs, else return 0
		int has_megastones(); // same as prev.		

		void level_pokemon_to_stage_two();
};

#endif
