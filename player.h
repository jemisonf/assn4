#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>


class Player {
	private:
     		int *num_pokemon;
		int num_megastones;
		int *level_pokemon;
		int num_pokeballs;
	public:
		Player();
		Player(const Player&);
		void operator=(const Player&);
		void clear_mem();

		~Player();
		int* get_pokemon()const;
		int get_num_pokemon_of_type(int)const;
		int* get_level_pokemon()const;
		int get_level_of_type(int)const;
		int get_num_pokeballs()const;
		int get_num_megastones()const;
		
		void show_stats();
		int has_all_lvl2_pokemon();

		void set_pokemon(int*);
		void set_pokemon_levels(int*);
		void set_pokemon_of_type(int, int); // type, num
		void set_level_of_type(int, int); // type, level
		void set_pokeballs(int);
		void set_megastones(int);

		void add_pokeballs(int);
		void add_megastones(int);
		void add_pokemon(int, std::string);

		void throw_pokeball(); // decrement pokeballs by one
		void use_megastone();
		int has_pokeballs(); // return 1 if player has >0 pokeballs, else return 0
		int has_megastones(); // same as prev.		

		std::string get_pokemon_name(int);
};

#endif
