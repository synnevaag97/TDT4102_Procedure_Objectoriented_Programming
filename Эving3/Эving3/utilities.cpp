#include "utilities.h"
#include "ctime"
#include "cstdlib"
#include "std_lib_facilities.h"
#include "cannonball.h"
#include "cannonball_viz.h"

int randomWithLimits(int lowerLimit, int upperLimit){
    int tilfeldig_tall = rand();
    return tilfeldig_tall%(upperLimit-lowerLimit)+lowerLimit;
}


void playTargetPractice(){
    keep_window_open();
    double blink = randomWithLimits(100,1000);
    int i = 0;
    while(i <= 10){
        i++;
        cout << "Trial " << i << " out of " << 10 << endl;
        double theta = getUserInputTheta();
        double absVel = getUserInputAbsVelocity();
        double error = targetPractice(blink, getVelocityX(theta,absVel), getVelocityY(theta,absVel));
        cannonBallViz(blink,1000,getVelocityX(theta,absVel),getVelocityY(theta,absVel),5);
        if(error <= 5 && error >= -5){
            cout << "Yay you won" << endl;
            cout << error << endl;
            break;
        }else{
            cout << "You missed with "<< error << " meters." << endl;
            if(i >= 10){
                cout << "You lost!" << endl;
                break;
            }
        }
    }
}