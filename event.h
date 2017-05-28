#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <stdlib.h>

class Player;

class Event {
	public:
     		virtual void run_event(Player&)=0;
   		virtual void get_precep()=0;
		virtual Event* clone()=0;
};

#endif
