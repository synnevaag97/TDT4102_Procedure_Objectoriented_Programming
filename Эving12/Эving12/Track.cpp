#include "Track.h"

Track::Track() : Fl_Widget(10, 10, 10, 10)
{
    goals.push_back({100.0,100.0});
    goals.push_back({250.0,300.0});
    goals.push_back({600.0,500.0});
    goals.push_back({800.0,300.0});
    goals.push_back({300.0,100.0});

    obstacles.push_back({500.0,500.0,Obstacle::Spill});
    obstacles.push_back({900.0,300.0, Obstacle::Boost});
    obstacles.push_back({200.0,100.0, Obstacle::Peel});
}

void Track::draw(){
    fl_color(FL_BLACK); //Tar opp en rød pen så alt som tegnes etter er rødt.
    for(auto [x,y] : goals){
        fl_begin_line();
        fl_arc(x,y,goalRadius,0,360);
        fl_end_line();
    }

    fl_color(FL_RED); //Tar opp en rød pen så alt som tegnes etter er rødt.
    for(auto [x,y,Z] : obstacles){
        fl_color(Z);
        fl_begin_line();
        fl_arc(x,y,obstacleToRadius.at(Z),0,360);
        fl_end_line();
    }
}

