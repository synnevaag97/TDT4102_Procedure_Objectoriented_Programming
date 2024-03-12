#include <cassert>
#include <iostream>


void fillInFibonacciNumbers(int result[], int length){
    assert(length>=1);
    result[0] = 0;
    result[1] = 1;

    for(int i = 2; i < length;i++){
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int arr[], int length){
    assert(length>=1);
    for(int i = 0; i<length;i++){
        std::cout << arr[i] << '\n';
    }
}

void createFibonacci(){
    int length;
    std::cout << "How many numbers should be generated?" << '\n';
    std::cin >> length;

    int *numbers = new int[length];

    fillInFibonacciNumbers(numbers, length);
    printArray(numbers, length); 

    delete[] numbers;
}