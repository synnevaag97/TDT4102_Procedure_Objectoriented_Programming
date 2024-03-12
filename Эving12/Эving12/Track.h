#pragma once

#include <tuple>
#include "utilities.h"
#include <FL/Fl_Widget.H>
#include  <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Enumerations.H>
#include <map>


enum Obstacle{Spill = FL_GREEN, Boost = FL_YELLOW, Peel = FL_BLUE, None = FL_BLACK};

const std::map<Obstacle,int> obstacleToRadius{
    {Obstacle::Spill, spillRadius},
    {Obstacle::Boost, boostRadius},
    {Obstacle::Peel, peelRadius},
    {Obstacle::None, 0},
};

class Track : public Fl_Widget{
    private: 
    std::vector<std::pair<double,double>> goals;
    std::vector<std::tuple<double,double,Obstacle>> obstacles;

    public:
    Track();
    void draw() override;
    const auto& getGoals() const { return goals; }
    const auto& getObstacle() const { return obstacles; }
};
