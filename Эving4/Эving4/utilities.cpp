#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) 
{
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) 
{
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int a, int b){
    int c = a;
    a = b;
    b = c;
}


void printStudent(Student student){
    cout << "Name: " << student.name 
    << ", Age: " << student.age 
    << ", Study program: " << student.studyProgram 
    << endl;
}

bool isInProgram(Student student, string program){
    if(student.studyProgram == program){
        return true;
    }else{
        return false;
    }
}

string randomizeString(int size, char upperLimit, char lowerLimit){
    string generatedString;
    for(int i = 1;i<=size;i++){
        int randomNumber = rand();
        char randomChar = randomNumber%(upperLimit-lowerLimit)+lowerLimit;
        generatedString += randomChar;
    }
    return generatedString;
}

string readInputToString(int size, char upperLimit, char lowerLimit){
    string generatedString;
    char userInputCharLarge;
    char userInputChar;
    for(int i = 1;i<=size;i++){
        do{
            cout << "Give a char!" << endl;
            cin >> userInputChar;
            userInputCharLarge = toupper(userInputChar);
        }while(userInputCharLarge>upperLimit || userInputCharLarge<lowerLimit);
        generatedString += userInputChar;
    }
    return generatedString;
}

int countChar(string str, char c){
    int count = 0;
    c = toupper(c);
    char compareChar;
    for(unsigned int i = 0; i < str.length(); i++){
        compareChar = toupper(str[i]);
        if(compareChar == c){
            count++;
        }
    }
    return count;
}
