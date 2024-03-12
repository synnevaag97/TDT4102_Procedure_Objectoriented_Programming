#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& a, int& b);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);

bool isInProgram(Student student, string program);

string randomizeString(int size, char upperLimit, char lowerLimit);
string readInputToString(int size, char upperLimit, char lowerLimit);

int countChar(string str, char c);