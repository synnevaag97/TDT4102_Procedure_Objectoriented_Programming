#include "Game.h"

Game::Game(int board_size, int win_value)
	: board_size(board_size),
	  board(board_size * board_size),
	  win_value{win_value}
{
	new_game();
}

// TASK
int Game::index(int x, int y) const
{
	// BEGIN: G1
	return x + board_size*y;
	// END: G1
}

// TASK
int Game::at(int x, int y) const
{
	// BEGIN: G2
	return board[index(x,y)];
	// END: G2
};

// TASK
int& Game::at(int x, int y)
{
	// BEGIN: G3
	return board[index(x,y)];
	// END: G3
}

// TASK
void Game::new_game()
{
	// BEGIN: G4
	for(unsigned int i = 0; i < board.size();i++){
		board[i] = 0;
	}
	place_new_2();
	place_new_2();
	// END: G4
}

// TASK
// Prerequisites: board does have a free 0-spot
void Game::place_new_2()
{
	// BEGIN: G5
	vector<int> empty;
	for(unsigned int i = 0; i < board.size(); i++){
		if(board[i] == 0){
			empty.push_back(i);
		}
	}

	int randomNumber = rand()%(empty.size());
	int index = empty[randomNumber];
	board[index] = 2;

	// END: G5
}

// TASK
void Game::flip()
{
	// BEGIN: G6
	for(int i = 0; i<2;i++){
		swap(board[i],board[board_size-i-1]);
		swap(board[i+board_size],board[board_size*2-i-1]);
		swap(board[i+board_size*2],board[board_size*3-i-1]);
		swap(board[i+board_size*3],board[board_size*4-i-1]);
	}
	// END: G6
}

// TASK
void Game::transpose()
{
	// BEGIN: G7
	vector<int> a;
	for(int j = 0; j<4;j++){
		for(int i = 0; i<4;i++){
			a.push_back(board[i*4+j]);
		}
	}
	for(unsigned int i = 0; i < a.size();i++){
		board[i] = a[i];
	}
	// END: G7
}

// TASK
void Game::push_right()
{
	// BEGIN: G8
	list<int> a; 
	for(int j = 0; j<4;j++){
		for(int i = 0; i<4;i++){
			if(board[i+j*4] == 0){
				a.push_front(0);
			}else{
				a.push_back(board[i+j*4]);
			}
		}
		int k = 0;
		for(auto it = a.begin();it!=a.end();it++){
			board[k+j*4] = *it;
			k++;
		}
		
		a.clear();
	}
	// END: G8
}

// TASK
void Game::merge_right()
{
	// BEGIN: G9
	for(int j = 3; j>=0;j--){
		for(int i = 3; i>0;i--){
			if(board[i+j*4] == board[i-1 + j*4]){
				if(i==3){
					board[i+j*4] = board[i+j*4]+board[i+j*4];
					board[i-1 + j*4] = board[i-2 + j*4];
					board[i-2 + j*4] = board[i-3 + j*4];
					board[i-3 + j*4] = 0;
				}
				else if (i==2)
				{
					board[i+j*4] = board[i+j*4]+board[i+j*4];
					board[i-1 + j*4] = board[i-2 + j*4];
					board[i-2 + j*4] = 0;
				}else if(i==1){
					board[i+j*4] = board[i+j*4]+board[i+j*4];
					board[i-1 + j*4] = 0;
				}
			}
		}
	}
	// END: G9
}

// TASK
void Game::move_right()
{
	// BEGIN: G10
	push_right();
	merge_right(); 
	// I haven't included a  push_right after merge since the
	// merge_right function already pushes to the right when it merges 
	// END: G10
}

// TASK
void Game::move_down()
{
	// BEGIN: G11
	flip();
	transpose();
	move_right();
	transpose();
	flip();
	// END: G11
}

// TASK
void Game::move_left()
{
	// BEGIN: G12
	flip();
	move_right();
	flip();
	// END: G12
}

// TASK
void Game::move_up()
{
	// BEGIN: G13
	transpose();
	flip();
	move_right();
	flip();
	transpose();
	// END: G13
}

// TASK
bool Game::free_spots() const
{
	// BEGIN: G14
	for(auto c : board){
		if(c == 0){
			return true;
		}
	}
	return false;
	// END: G14
}

// TASK
void Game::tick()
{
	// BEGIN: G15
	if((moved = true) && (free_spots() == true)){
		place_new_2();
	}
	// END: G15
}

// TASK
bool Game::win() const
{
	// BEGIN: G16
	for(auto c : board){
		if( c == win_value){
			return true;
		}
	}
	return false;
	// END: G16
}

// TASK
// Prerequisites: all tiles are non-zero
bool Game::legal_moves() const
{
	
	// BEGIN: G17
	for(int j = 0; j<4;j++){
		for(int i = 0; i<3;i++){
			if(board[i+j*4] == board[i+1+j*4]){
				return true;
			}
		}
	}
	for(int j = 0; j<3;j++){
		for(int i = 0; i<4;i++){
			if(	board[i+j*4]==board[i+4+j*4]){
				return true;
			}
		}
	}

	return false;
	// END: G17
}



/**** Provided code ****/

// API version of tile value - const external interface
int Game::value(int x, int y) const { return at(x, y); }

// This function keeps track of changes to the board
// and calls the move function requested by the player
void Game::move(Direction direction)
{
	// We have not moved any tiles yet
	moved = false;

	// Keep the old board matrix for comparison
	std::vector<int> old_board{board};

	if (status() == Status::playing) {
		switch (direction) {
		case Direction::up:
			move_up();
			break;
		case Direction::right:
			move_right();
			break;
		case Direction::down:
			move_down();
			break;
		case Direction::left:
			move_left();
			break;
		}
	}

	// Did we move anything?
	if (board != old_board) {
		moved = true;
	}

	tick();
}

// We use this to figure out if a game
// is won, game over or if the player still
// can play legal moves
Game::Status Game::status() const
{
	if (win()) {
		return Status::win;
	}

	if (free_spots() || legal_moves()) {
		return Status::playing;
	}

	return Status::game_over;
}

bool Game::game_over() const { return status() == Status::game_over; }

std::ostream& operator<<(std::ostream& os, const Game& g)
{
	for (int i = 0; i < g.board_size; ++i) {
		for (int j = 0; j < g.board_size; ++j) {
			std::cout << g.at(j, i) << " ";
		}
		std::cout << '\n';
	}

	return os;
}

// Debug methods - debug API
void Game::debug_all_twos()
{
	static const std::array<int, 16> debug_board_all_twos{
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

	std::copy(debug_board_all_twos.begin(),
	          debug_board_all_twos.end(),
	          board.begin());
	tick();
}

void Game::debug_increasing()
{
	static const std::array<int, 16> debug_board_increasing{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	std::copy(debug_board_increasing.begin(),
	          debug_board_increasing.end(),
	          board.begin());
	tick();
}

void Game::debug_push_merge()
{
	// clang-format off
	static const std::array<int, 16> debug_board_push_merge{
		2,0,2,0,
		0,2,2,4,
		0,2,2,2,
		8,8,8,8
	};
	// clang-format on

	std::copy(debug_board_push_merge.begin(),
	          debug_board_push_merge.end(),
	          board.begin());
	tick();
}

void Game::debug_flip() { flip(); }
void Game::debug_transpose() { transpose(); }
