#include "cannonball.h"

double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){
    return initVelocityY+acclY()*time;
}

double posX(double initPositionX, double initVelocityX, double time){
    return initPositionX + initVelocityX*time+(0*pow(time,2))/2;
}

double posY(double initPositionY, double initVelocityY, double time){
    return initPositionY + initVelocityY*time+(acclY()*pow(time,2))/2;

}

void printTime(double seconds){
    int hours = seconds/(60*60);
    seconds = static_cast<int>(seconds)%(60*60);
    int minutes = seconds/60;
    seconds = static_cast<int>(seconds)%60;
    cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: " << seconds << endl;
}

double flightTime(double initVelocityY){
    return (-2*initVelocityY)/acclY();
}


//Part 2 
double getUserInputTheta(){
    double angle;
    cout << "Give us a angle: " << endl;
    cin >> angle;
    return angle;
}

double getUserInputAbsVelocity(){
    double absVelocity;
    cout << "Give us a absolute velocity: " << endl;
    cin >> absVelocity;
    return absVelocity;
}
double degToRad(double deg){
    return deg * pi/180;
}
double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(theta);
}
double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(theta);
}
vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velVec;
    velVec.push_back(getVelocityX(theta,absVelocity));
    velVec.push_back(getVelocityY(theta,absVelocity));
    return velVec;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double fTime = flightTime(velocityY);
	double distanceTraveled = posX(0, velocityX, fTime);
	return distanceTraveled;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget-getDistanceTraveled(velocityX, velocityY);
}




