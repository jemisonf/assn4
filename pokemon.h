#ifndef POKEMON_H
#define POKEMON_H

#include "event.h"
#include <string>

class Player;

class Pokemon: public Event {
	protected:
     		int type;
   			/* 0 = geodude
			 * 1 = onyx
			 * 2 = charizard
			 * 3 = rayquaza
			 * 4 = mewtwo
			 * 5 = espeon */
		std::string name;
		int catch_chance;
	public:
		int get_type() const;		
		std::string get_name() const;
		int run_event(Player &p); 
		void get_precep();
		int is_caught();
		virtual Event* clone();

};

#endif
