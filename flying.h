#ifndef FLYING_H
#define FLYING_H

#include "pokemon.h"

class Flying: public Pokemon {
     	public:
	  	Flying(int);
		Event* clone();	
};

#endif
