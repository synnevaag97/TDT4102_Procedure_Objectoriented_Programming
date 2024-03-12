#include "Simple_window.h"
#include "Emoji.h"
#include "Face.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	EmptyFace emptyface{Point{xmax/2,ymax/2},emojiRadius};
	//emptyface.attach_to(win);

	SmileyFace smileyface{Point{xmax/2,ymax/2},emojiRadius};
	SadFace sadface{Point{xmax/2,ymax/2},emojiRadius};

	//smileyface.attach_to(win);
	sadface.attach_to(win);

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	win.wait_for_button();
}
