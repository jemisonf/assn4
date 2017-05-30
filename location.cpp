#include "location.h"
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

Location::Location() {
	board = NULL;
	player_position = NULL;
	size = 0;
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
			if (board[i][j]) delete [] board[i][j];
		}
		if (board[i]) delete [] board[i];
	}
	if (board) delete [] board;
	board = NULL;
	if (player_position) delete [] player_position;
	player_position = NULL;
	size = 0;
}

void Location::setup_board(int new_size) {
     	int a, b;
	clear_mem();
	size = new_size;
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
/*	vector<int> vi, vj, vi_rand, vj_rand;
	int num_i, num_j;
	for (int i = 0; i < size; i++) {
		vi.push_back(i);
		vj.push_back(i);
	}
	for (int i = 0; i < size; i++) {
	     	num_i = rand() % vi.size();
		num_j = rand() % vi.size();
		vi_rand.push_back(vi[num_i]);
		vi.erase(vi.begin() + num_i);
		vj_rand.push_back(vi[num_j]);
		vj.erase(vj.begin() + num_j);
	}*/
	vector<Event*> event_vect;
	for (int i = 0; i < 2; i++) {
		event_vect.push_back(new Rock(0));
		event_vect.push_back(new Rock(1));
		event_vect.push_back(new Flying(2));
		event_vect.push_back(new Flying(3));
		event_vect.push_back(new Psychic(4));
		event_vect.push_back(new Psychic(5));
		event_vect.push_back(new Pokestop);
		event_vect.push_back(new Cave);
	}
	for (int i = 0; i < 4; i++) event_vect.push_back(new Cave);	
       	for (int i = 0; i < 20; i++) {
	//	board[vi_rand.at(i)][vj_rand.at(i)] = event_vect[i];
	//	cout << vi_rand[i] << " " << vj_rand[i] << endl;
		do {
			a = rand() % size;
			b = rand() % size;
		} while (board[a][b] && (a + b != 0));
		board[a][b] = event_vect.at(i)->clone();
		delete [] event_vect.at(i);
	}	
}

int Location::get_player_pos_0() const {
	return player_position[0];
}

int Location::get_player_post_1() const {
	return player_position[1];
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
			if ((i == player_position[0] && j == player_position[1])) {
				cout << "P";
			} else if (board[i][j]) {
			     	#ifdef DEBUG
			 	cout << "*";
			    	#endif
				#ifndef DEBUG
				cout << " ";
				#endif	
			}else {
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

void Location::set_location_on_board(Event& e, int i, int j) {
	board[i][j] = e.clone();	
}

void Location::get_preceps() {
	for (int i = player_position[0] - 1; i <= player_position[0] + 1; i++) {
		for (int j = player_position[1] - 1; j <= player_position[1] + 1; j++) {
			if (i >= 0 && i < size && j >= 0 && j < size && board[i][j]) {
			     	board[i][j]->get_precep();
			}
		}
	}	     
}

void Location::run_event(Player &p) {
	if (board[player_position[0]][player_position[1]]) {
		if (board[player_position[0]][player_position[1]]->run_event(p)) {
			delete [] board[player_position[0]][player_position[1]];
			board[player_position[0]][player_position[1]] = NULL;
		} else {
			flee_pokemon(player_position[0], player_position[1]);
		}	     
	}
}

void Location::flee_pokemon(int index_i, int index_j) {
     	cout << "The pokemon flees!" << endl;
	vector<int> vi, vj, vi_rand, vj_rand;
	int num_i, num_j;
	for (int i = 0; i < size; i++) {
		vi.push_back(i);
		vj.push_back(i);
	}
	for (int i = 0; i < size; i++) {
	     	num_i = rand() % vi.size();
		num_j = rand() % vi.size();
		vi_rand.push_back(vi[num_i]);
		vi.erase(vi.begin() + num_i);
		vj_rand.push_back(vi[num_j]);
		vj.erase(vj.begin() + num_j);
	}
	for (int i = 0; i < size; i++) {
		if (!board[vi_rand.at(i)][vj_rand.at(i)]) {
			board[vi_rand.at(i)][vj_rand.at(i)] = board[index_i][index_j]->clone();
			delete [] board[index_i][index_j];
			board[index_i][index_j] = NULL;
			break;
		}
	}
}

int Location::player_has_won(Player &p) {
	if (player_position[0] == 0 && player_position[1] == 0 && p.has_all_lvl2_pokemon()) {
		return 1;
	} else {
		return 0;
	}
}
