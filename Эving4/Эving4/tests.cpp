#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}   

void testCallByValueRef() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations;
}   

void testStudentStruct(){
    Student student = {"Trym", "Kyb", 23};
    printStudent(student);

    cout << isInProgram(student, "Kyb") << endl;
}

void testString(){
    static constexpr int numGrades = 8;
	string grades{randomizeString(numGrades, 'F', 'A')};
	cout << "Random grades: " << grades << '\n';

    vector<int> gradeCount(6);
    int meidanGrades = 0;
    char c = 'A';
    for(int i = 0; i < 6; i++){
        int count = countChar(grades, c);
        gradeCount[i] = count;
        meidanGrades += count*(5-i);
        cout << c << ":" << count << endl;
        c ++;
    }
    double gpa = meidanGrades/double{numGrades};
    cout << gpa << endl;
}