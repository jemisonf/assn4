#ifndef LOCATION_H
#define LOCATION_H

#include "event.h"

class Location {
     	private:
	     	Event ***board;
		int *player_position;
		int size;
	public:
		Location(); // default constructor
		Location(int) // initialize with board size;
		Location(const Location&); // copy constr.
		void operator=(const Location&);
		~Location();
		Event **get_board() const;
		Event *get_event(int, int) const;
		int* get_player_position() const;	
		int get_size;
		void get_preceps();
		void run_player_event(Player&);
		void setup_location();
}

#endif
