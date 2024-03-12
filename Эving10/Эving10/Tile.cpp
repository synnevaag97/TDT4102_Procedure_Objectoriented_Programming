#include "Tile.h"
#include <assert.h>

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
	if(state == Cell::closed){
		static_cast<Fl_Button *>(pw)->set(); //Setter en button som trykket paa, tilsvarer aapnet rute
		state = Cell::open;
		if(get_isMine()){
			set_label("X");
			set_label_color(Color::red);
		}
	}else{
		return;
	}

}

void Tile::flag()
{
	if(state == Cell::flagged){
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	}else if(state == Cell::closed){
		state = Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
	}
}

void Tile::set_isMine(bool TorF){
	isMine = TorF;
}

void Tile::setAdjMines(int n)
{
	assert(n<=8 && n>=1);
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}