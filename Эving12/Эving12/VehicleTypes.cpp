#include "VehicleTypes.h"

PlayerVehicle::PlayerVehicle(double x, double y, double angle, const Track& track):Vehicle(x,y,angle,track)
{}

void PlayerVehicle::drawBody() const{
    fl_color(FL_RED); //Tar opp en rød pen så alt som tegnes etter er rødt.
 
    fl_begin_line();
    fl_arc(state.x-vehicleRadius/2,state.y-vehicleRadius/2,vehicleRadius,0,360);
    fl_end_line();

    fl_begin_polygon();
    fl_arc((state.x-vehicleRadius/2)-vehicleRadius*cos(state.angle),(state.y-vehicleRadius/2)-vehicleRadius*sin(state.angle),vehicleRadius/5,0,360);
    fl_end_polygon();

    auto [current_x, current_y] = track.getGoals()[indeksGoal];
	fl_color(FL_GREEN);
	fl_begin_polygon();
	fl_circle(current_x, current_y, goalRadius);
	fl_end_polygon();
    
}

std::pair<double, double> PlayerVehicle::steer() const{
    std::pair<double, double> direction;
    if (Fl::event_key(FL_Left)){
        direction.second = -1;
    }
    else if (Fl::event_key(FL_Right)){
        direction.second = 1;
    }
    if (Fl::event_key(FL_Up)){
    direction.first = -1;
    }
    else if (Fl::event_key(FL_Down)){
    direction.first = 1;
    }
    return direction;
}