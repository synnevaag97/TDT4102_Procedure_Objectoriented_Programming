#pragma once
#include "Emoji.h"

class Face : public Emoji{
    private: 
    Circle face;

    public:
    Face(Point c, int r);
	void attach_to(Graph_lib::Window& win) override = 0;
};

class EmptyFace : public Face{
    private:
    Circle eye1;
    Circle eye2;

    public:
    EmptyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;

};

class SmileyFace : public EmptyFace
{
    private:
    Arc mouth;

    public:
    SmileyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;

};

class SadFace : public EmptyFace
{
    private:
    Arc mouth;

    public:
    SadFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};