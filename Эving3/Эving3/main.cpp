#include "cannonball.h"
#include "utilities.h"


void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main(){
    /*srand(static_cast<unsigned int>(time(nullptr)));
    double maxError = 0.01;
    cout << "Deviation tests:\n";
	testDeviation(acclY(), -9.81, maxError, "AcclY()");

	testDeviation(velY(25.0, 0.0), 25.0, maxError, "velY(0.0, 0.0)");
	testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0, 2.5)");
	testDeviation(velY(25.0, 5.0), -24.05, maxError, "velY(25.0, 5.0)");

	testDeviation(posX(0.0, 50.0, 0.0), 0.0, maxError, "posX(0.0, 50.0, 0.0)");
	testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0, 50.0, 2.5)");
	testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0, 50.0, 5.0)");

	testDeviation(posY(0.0, 25.0, 0.0), 0.0, maxError, "posY(0.0, 25.0, 0.0)");
	testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
	testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0, 25.0, 5.0)");

	testDeviation(flightTime(30.0), 6.116, maxError, "flightTime(30.0)");

    for(int i=1;i<100;i++){
        cout << randomWithLimits(50,110) << endl;
    }*/
    playTargetPractice();
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if(abs(compareOperand-toOperand) <= maxError){
        cout << name << " is valid." << endl;
    }else{
        cout << name << " not valid. Expected " << toOperand << " got " << compareOperand << endl;  
    }
}
