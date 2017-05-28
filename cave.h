#ifndef CAVE_H
#define CAVE_H

#include "event.h"
#include "player.h"

class Cave: public Event {
	private:	
		int num_stones;
	public:
		Cave();
		void run_event(Player &);
		void get_precep();
		Event * clone();
};

#endif
