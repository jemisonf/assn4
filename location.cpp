#include "location.h"
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

Location::Location() {
	board = NULL;
	player_position = NULL;
}

Location::Location(int size) {
     	this->size = size;
	board = new Event**[size];
	for (int i = 0; i < size; i++) {
		board[i] = new Event*[size];
		for (int j = 0; j < size; j++) {
			board[i][j] = NULL;
		}
	}
	player_position = new int[2];
	player_position[0] = 0;
	player_position[1] = 0;

}

Location::Location(const Location &l) {
	size = l.get_size();
	board = new Event**[size];
	for (int i = 0; i < size; i++) {
		board[i] = new Event*[size];
		for (int j = 0; j < size; j++) {
			if (l.get_event(i, j)) board[i][j] = l.get_event(i, j)->clone();	
		}
	}
	player_position = new int[2];
	player_position[0] = 0;
	player_position[0] = 0;
}

void Location::operator=(const Location &l) {
	clear_mem();
	board = new Event**[size];
	for (int i = 0; i < size; i++) {
		board[i] = new Event*[size];
		for (int j = 0; j < size; j++) {
			if (l.get_event(i, j)) board[i][j] = l.get_event(i, j)->clone();	
		}
	}
	player_position = new int[2];
	player_position[0] = 0;
	player_position[0] = 0;
}

Location::~Location() {
	clear_mem();
}

void Location::clear_mem() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			delete [] board[i][j];
		}
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
	delete [] player_position;
	player_position = NULL;
	size = 0;
}
/*
template <typename T>
void Location::get_copy_of_event(T const &event, Event** destination) {
	*destination = new T;
	**destination = event;
}
*/

Event* Location::get_event(int i, int j) const {
	return board[i][j];
}

int Location::get_size() const {
	return size;
}

void Location::print_board() {
	for (int i = 0; i <  (size * 2) + 1; i++) {	// print top row
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "|"; // print left border bar
		for (int j = 0; j < size; j++) {
			if (i == player_position[0] && j == player_position[1]) {
				cout << "P";
			} else {
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
		for (int i = 0; i <  (size * 2) + 1; i++) {	// print top row
			cout << "-";
		}
		cout << endl;
	}
}

int Location::is_valid_move(int move) {
     	if (move > 3 || move < 0) {
		return 0;
	} else if (move == UP) {
		if (player_position[0] > 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (move == LEFT) {
		if (player_position[1] > 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (move == DOWN) {
		if (player_position[0] == (size - 1)) {
			return 0;
		} else {
			return 1;
		}
	} else if (move == RIGHT) {
		if (player_position[1] == (size - 1)) {
			return 0;
		} else {
			return 1;
		}
	}
}

int Location::get_move() {
     	int user_choice = -1;
	cout << "Select a move:\n\t0. Up\n\t1. Right\n\t2. Down\n\t3. Left" << endl;
	cout << "Your choice: ";
	do {
		if (user_choice != -1) cout << "You cannot move in that direction." << endl;
	     	user_choice = get_valid_int(4);
	} while (!is_valid_move(user_choice));
	return user_choice;
}

void Location::move_player() {
	int move = get_move();
	switch(move) {
		case 0:
		     player_position[0]--;
		     break;
		case 1:
		     player_position[1]++;
		     break;
		case 2:
		     player_position[0]++;
		     break;
		case 3:
		     player_position[1]--;
		     break;
	}
}

int Location::get_valid_int(int max) {
	string temp = "";
     	do {
		if (temp != "") cout << "Enter a valid integer." << endl;
		getline(cin, temp);
	} while (!is_valid_int(temp, max));
	return atoi(temp.c_str());	
}

int Location::is_valid_int(string str, int max) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] > '9' || str[i] < '0') {
			return 0;
		}
	}
	if (max != -1 && atoi(str.c_str()) > max) return 0;
	return 1;
}
