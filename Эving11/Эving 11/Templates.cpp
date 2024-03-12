#include "Templates.h"
#include <vector>


template<typename T>
T maximum(T a, T b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

template<typename T>
void shuffle(std::vector<T>& vec){
    for (size_t i = 0; i < vec.size() - 1; i++){
        int j = rand() % (vec.size() - i);
        std::swap(vec[i], vec[i + j]);
    }
}

void test_template(){
    int a = 1;
    int b = 2;
    int c = maximum(a, b);
    std::cout << c << '\n';
    // c er nå 2.
    double d = 2.4;
    double e = 3.2;
    double f = maximum(d,e);
    // f er nå 3.2
    std::cout << f;


    std::vector<int> vec{1,2,3,4,5,6,6,7,8,8};
    shuffle(vec);
    for(auto c : vec){
        std::cout << c << '\n';
    }
}