#include "location.h"

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

void print_board() {
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
		for (int i = 0; i <  (size * 2) + 1; i++) {	// print top row
			cout << "-";
		}
	}
}
