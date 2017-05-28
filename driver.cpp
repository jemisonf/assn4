#include "location.h"
#include "cave.h"
#include <iostream>
#include "pokestop.h"
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

int main() {
     	Location l(15);
	Pokestop c;
	l.set_location_on_board(c, 4, 4);
	while (true) {
	     	l.print_board();
		l.move_player();
		if (l.get_event(l.get_player_pos_0(), l.get_player_post_1())) l.get_event(l.get_player_pos_0(), l.get_player_post_1())->get_precep();
	}
	return 0;
}
