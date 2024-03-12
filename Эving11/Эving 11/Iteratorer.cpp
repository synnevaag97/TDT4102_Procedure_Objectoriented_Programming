#include "Iteratorer.h"

void loopVector(std::vector<std::string> vec){

    for(auto n = vec.begin();n != vec.end();n++){
        std::cout << *n << '\n';
    }

    for(auto n = vec.rbegin();n != vec.rend();n++){
        std::cout << *n << '\n';
    }
}

void replaceVector(std::vector<std::string>& vec, std::string old, std::string replacement){
    for(auto str = vec.begin(); str != vec.end(); str++){
        if(*str == old){
            str = vec.erase(str);
            str = vec.insert(str, replacement);
        }
    }
}

void loopSet(std::set<std::string> vec){
    for(auto n = vec.begin();n != vec.end();n++){
        std::cout << *n << '\n';
    }

    for(auto n = vec.rbegin();n != vec.rend();n++){
        std::cout << *n << '\n';
    }
}

void replaceSet(std::set<std::string>& vec, std::string old, std::string replacement){
    for(auto str = vec.begin(); str != vec.end(); str++){
        if(*str == old){
            str = vec.erase(str);
            str = vec.insert(str, replacement);
        }
    }
}