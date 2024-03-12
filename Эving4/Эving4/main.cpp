#include "tests.h"
#include "utilities.h"
#include "Mastermind.h"

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice = -1;

    while(choice != 0){
        cout << "0) Avslutt \n"
        << "1) Test\n"
        << "2) TestRef\n";

        cout << "Angi valg (0-13): " << endl;
        cin >> choice;

        switch(choice){
            case 0:
                break;
            case 1:
                testCallByValue();
                break;
            case 2: 
                testCallByValueRef();
                break;
            case 3:
                testStudentStruct();
                break;
            case 4:
                testString();
                break;
            case 5:
                playMasterMind();
                break;
        }
    }
}