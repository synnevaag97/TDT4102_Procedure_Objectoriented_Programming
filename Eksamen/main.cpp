
#include <iostream>
int main(){
    int a = 20;
    float b = a * 2 + 1;
    std::cout << b << '\n';
    int c = b++;
    std::cout << b << '\n';
    std::cout << c << '\n';
    b += b / 100;
    std::cout << a << " " << b << " " << c << '\n';

    int *foo = &a;
    std::cout << *foo;
}