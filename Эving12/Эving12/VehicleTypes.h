#pragma once
#include "Vehicle.h"

#include  <FL/Fl.H>

class PlayerVehicle : public Vehicle
{
    public:
    PlayerVehicle(double x, double y, double angle, const Track& track);
    void drawBody() const override;
    std::pair<double, double> steer() const override;
};