#ifndef ROCK_H
#define ROCK_H

#include "pokemon.h"

class Rock: public Pokemon {
	public:
     		Rock(int);
   		Event* clone();		
};

#endif
