#include "location.h"
#include "cave.h"
#include "player.h"
#include "rock.h"
#include <iostream>
#include "pokestop.h"
#include <stdlib.h>
#include <ctime>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;


int main() {
     	Player p;
	int size = -1;
	Location l;
	cout << "How big should the board be?" << endl;
	do {
		if (size != -1) cout << "Please enter a number greater than 4 to accomodate all necessary elements." << endl;
		size = Location::get_valid_int();
	} while (size <= 4);
	l.setup_board(size);
	do {
	     	p.show_stats();
	     	l.print_board();
		l.get_preceps();
		l.move_player();
		l.run_event(p);
	} while (!l.player_has_won(p));
	cout << "Congratulations! You win!" << endl;
	return 0;
}
