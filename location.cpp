#include "location.h"

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

Location::Location(Location &l) {
	size = l.get_size();
	board = new Event**[size];
	for (int i = 0; i < size; i++) {
		board[i] = new Event*[size];
		for (int j = 0; j < size; j++) {
			board[i] = get_copy_of_event(*l.get_event(i, j));
		}
	}
}

template <typename T>
T get_copy_of_event(T const &event) {
	T* ptr = new T;
	*ptr = event;
	return *ptr;
}

Event* get_event(int i, int j) {
	return board[i][j];
}
