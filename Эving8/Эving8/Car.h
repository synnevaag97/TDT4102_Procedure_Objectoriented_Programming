#pragma once
#include "std_lib_facilities.h"

class Car
{
    private:
    int freeSeats;

    public:
    Car(int fs);
    bool hasFreeSeats() const;
    void reserveFreeSeats();
};

