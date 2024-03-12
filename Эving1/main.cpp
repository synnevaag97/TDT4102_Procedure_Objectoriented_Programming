#include "std_lib_facilities.h"

//Problem 1
//def isFibonacciNumber(n):
//    a = 0
//    b = 1
//    while b < n:
//        temp = b
//        b += a
//        a = temp
//    retun b == n


//Problem 2
int maxOfTwo(int a, int b) {
    if(a>b){
        cout << "A is greater than B" << endl;
        return a;
    } else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

int fibonacci(int n){
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers: " << endl;
    for(int i = 1; i < n+1; ++i){
        cout << i << ", " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "---" << endl;
    return b;
}

int squareNumberSum(int n){
    int totalSum = 0;
    for(int i = 1; i<n; ++i){
        totalSum+= i*i;
        cout << i*i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":\n";
    while(acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    cout << "\n";
}

bool isPrime(int n){
    for(int j = 2; j<n; ++j){
        if(n%j == 0){
            return false;
        }
    }
    return true;
}


void naivePrimeNumberSearch(int n) {
    for(int number = 2; number<n; ++number){
        if(isPrime(number)){
            cout << number << "is a prime" << endl;
        }
    }
}

int findGreastestDivisor(int n){
    for(int divisor = n-1; divisor > 0; --divisor){
        if(n%divisor == 0){
            return divisor;
        }
    }
    return 1;
}

int main(){
    cout << "Oppgave a)\n";
    cout << maxOfTwo(5,6) << "\n";

    cout << "oppgave c)\n";
    cout << fibonacci(5) << endl;

    cout << "oppgave d)\n";
    cout << squareNumberSum(6) << endl;

    cout << "oppgave e)\n";
    triangleNumbersBelow(5);


    cout  << "Oppgave f)\n";
    cout << isPrime(13) << endl;

    cout << "Oppgave g)\n";
    naivePrimeNumberSearch(20);

    cout << "oppgave h)\n";
    cout << findGreastestDivisor(100) << endl;

}