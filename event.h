#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <stdlib.h>
#include "player.h"

class Event {
	public:
     		virtual int run_event(Player&)=0; // all events return 1 except pokemon which return 0 when not captured
   		virtual void get_precep()=0;
		virtual Event* clone()=0;
};

#endif
