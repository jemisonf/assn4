#ifndef EVENT_H
#define EVENT_H

#include "player.h"

class Event {
	public:
     		virtual void run_event(Player&)i=0;
   		virtual void get_precep()=0;
};

#endif
