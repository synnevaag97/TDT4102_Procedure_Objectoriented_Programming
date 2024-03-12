#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}, remainingTiles{height * width - mines}, 
	gameEndMenu{Point{Width() / 2 - 60, Height() / 2}, 60, 40, Menu::horizontal, "Game End"},
	gameEndBackGround{Point{Width() / 2 - 60, Height() / 2 - 40}, Point{Width() / 2 + 60, Height() / 2}},
	gameEndText{Point{Width() / 2 - 60 + 3, Height() / 2 - 40 * 3 / 10}, " "}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner
	int i = 0;
	while(i<mines){
		int randNumber = rand()%tiles.size();
		if(tiles[randNumber].get_isMine() == false){
			tiles[randNumber].set_isMine(true);
		}
		i++;
	}

	//gameEndMenu.attach(new Button{ Point{ 0,0 }, 0, 0, "Restart", cb_restart });
	//gameEndMenu.attach(new Button{ Point{ 0,0 }, 0, 0, "Quit", cb_quit });
	attach(gameEndMenu);
	gameEndMenu.hide();

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if(at(xy).get_isMine() == true){
		gameLost();
		return;
	}


	if(at(xy).getState() == Cell::closed){
		at(xy).open();
		remainingTiles--;
		if(remainingTiles== 0){
			gameWon();
			return;
		}
	

		vector<Point> adjacentpoints = adjacentPoints(xy);
		int totalMines = countMines(adjacentpoints);
		if(totalMines > 0){
			at(xy).setAdjMines(totalMines);
		}else{
			for(auto c : adjacentpoints){
				openTile(c);
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if(at(xy).getState() != Cell::open){
		at(xy).flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}

	flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int totalMines = 0;
	for(auto c : coords ){
		if(at(c).get_isMine()){
			totalMines++;
		}
	}
	return totalMines;
}


void MinesweeperWindow::gameLost(){
	for (Tile* tile : tiles) {
		if (tile->get_isMine()) {
			tile->open();
		}
	}

	// Legger til meny for at spillet er tapt
	addGameEndMenu("Game Over", Color::red);
}
void MinesweeperWindow::gameWon(){
	for (Tile* tile : tiles) {
		if (tile->getState() == Cell::closed) {
			tile->flag();
		}
	}
	addGameEndMenu("Game Won", Color::green);
}

void MinesweeperWindow::addGameEndMenu(string s, Color c) {
	// setter riktig font og farger til vinn eller tap
	gameEndBackGround.set_color(c);
	gameEndBackGround.set_fill_color(c);
	gameEndText.set_label(s);
	gameEndText.set_color(Color::black);
	gameEndText.set_font_size(20);

	// Legger til menyen paa vinduet
	attach(gameEndBackGround);
	attach(gameEndText);
	gameEndMenu.show();

	// Oppdaterer vinduet og tegn alle objekter paa nytt
	flush();
}