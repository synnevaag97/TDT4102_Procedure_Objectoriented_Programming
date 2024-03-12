#include "Car.h"

Car::Car(int fs) : freeSeats(fs)
{}

bool Car::hasFreeSeats() const{
    if(freeSeats>0){
        return true;
    }else{
        return false;
    }
}
void Car::reserveFreeSeats(){
    freeSeats-=1;
}

