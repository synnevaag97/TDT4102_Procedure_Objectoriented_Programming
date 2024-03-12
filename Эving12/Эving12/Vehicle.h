#pragma once

#include "utilities.h"
#include "Track.h"
#include <tuple>

#include <FL/Fl_Widget.H>

#include <FL/fl_draw.H>
#include <FL/Enumerations.H>

class Vehicle : public Fl_Widget 
{
public:
    Vehicle(double x, double y, double angle, const Track& track);

    void draw() final;



protected:
    PhysicsState state;
    const Track& track;

    int indeksGoal = 0;

    virtual std::pair<double, double> steer() const = 0;
    virtual void drawBody() const = 0;
};

bool circleCollision(double delX, double delY, double sumR);
