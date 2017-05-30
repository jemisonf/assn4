#ifndef LOCATION_H
#define LOCATION_H

#include "event.h"
#include "player.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include "pokestop.h"
#include "cave.h"
#include <iostream>
#include <exception>
#include <string>
#include <stdlib.h>
#include <vector>

class Location {
     	private:
	     	Event ***board;
		int *player_position;
		int size;
	public:
		Location(); // default constructor
		Location(int); // initialize with board size;
		Location(const Location&); // copy constr.
		void operator=(const Location&);
		~Location();
		void clear_mem();
		Event **get_board() const;
		Event *get_event(int, int) const;
		int* get_player_position() const;	
		int get_size() const;
		int get_player_pos_0() const;
		int get_player_post_1() const;

		void setup_board(int);

		void set_location_on_board(Event&, int, int);
		void get_preceps();
		void run_player_event(Player&);
		void setup_location();

		void print_board();
		
		int is_valid_move(int);
		int get_move();
		void move_player();
		
		void run_event(Player &);
		void flee_pokemon(int, int); // coords of pokemon
		
		int player_has_won(Player &);

		static int get_valid_int(int=-1);
		static int is_valid_int(std::string, int=-1);
};

#endif
