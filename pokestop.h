#ifndef POKESTOP_H
#define POKESTOP_H

#include "event.h"
#include "player.h"

class Pokestop: public Event {
     	private:
	     	int num_pokeballs;
	public:
		Pokestop();
		int get_pokeballs();
		void set_pokeballs(const int);
		Event* clone();
		int run_event(Player&);
		void get_precep();
};

#endif
