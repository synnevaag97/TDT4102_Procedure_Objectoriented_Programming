#include "Face.h"


Face::Face(Point c, int r): face(c,r){
    face.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
}

EmptyFace::EmptyFace(Point c, int r): 
Face{c,r}, 
eye1{Point{c.x-r/6,c.y-r/12},r/6}, 
eye2{Point{c.x+r/6,c.y-r/12},r/6}
{
    eye1.set_fill_color(Color::white);
    eye2.set_fill_color(Color::white);
}

void EmptyFace::attach_to(Graph_lib::Window& win)
{
    Face::attach_to(win);
    win.attach(eye1);
    win.attach(eye2);
}

SmileyFace::SmileyFace(Point c, int r): EmptyFace{c,r}, mouth{Point{c.x, c.y + 10}, 60, 40, 180, 360}
{
    mouth.set_color(Color::black);
}

void SmileyFace::attach_to(Graph_lib::Window& win)
{
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

SadFace::SadFace(Point c, int r): EmptyFace{c,r}, mouth{Point{c.x+5, c.y + 10}, 60, 40, 0, 180}
{
    mouth.set_color(Color::black);
}

void SadFace::attach_to(Graph_lib::Window& win)
{
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

