#include "Vehicle.h"

Vehicle::Vehicle(double x, double y, double angle, const Track& t): 
    Fl_Widget(10,10,10,10),
	state{ x,y,angle }, // speed = 0
	track{ t }
{
    state.x = x;
    state.y = y; 
    state.angle = angle;
}

void Vehicle::draw(){
    std::pair<double, double> steering = steer();
    state.update(steering.first, steering.second);
    auto [current_x, current_y] = track.getGoals()[indeksGoal];
    double diffX = abs(state.x - current_x);
    double diffY = abs(state.y - current_y);
    //double diffY = abs(state.y-track[indeksGoal].second)
    if(circleCollision(diffX, diffY, vehicleRadius+vehicleRadius/2)){
        indeksGoal = (indeksGoal+1)% track.getGoals().size();;
    }

	for (auto [x, y, type] : track.getObstacle()) // Behandle hindringar
	{
		if (circleCollision(x - state.x, y - state.y, vehicleRadius + (type == Obstacle::Boost ? boostRadius : type == Obstacle::Spill ? spillRadius : peelRadius)))
		{
			switch (type)
			{
			case Obstacle::Spill:
				state.grip = 0.5;
				break;
			case Obstacle::Peel:
				if (status == Obstacle::Peel || state.speed < 2.0)
					break;
				status = Obstacle::Peel;
				slideAngle = physics.angle;
				break;
			case Obstacle::Boost:
				physics.grip = 2;
				break;
			default:
				break;
			}
		}
	}

    state.x = std::min(std::max(vehicleRadius, state.x), screenWidth - vehicleRadius);
	state.y = std::min(std::max(vehicleRadius, state.y), screenHeight - vehicleRadius);
    
    drawBody();
}


bool circleCollision(double delX, double delY, double sumR){
    if(sqrt(pow(delX,2)+pow(delY,2))<sumR){
        return true;
    }
    return false;
}
