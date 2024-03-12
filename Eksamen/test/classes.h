#include <iostream>
class alpha {
    public:
    alpha(){
        std::cout << "alpha's constructor called\n";
    }
    ~alpha(){
        std::cout << "alpha's destructor called\n";
    }
};

class beta{
    public:
    beta(){
        std::cout << "beta's constructor called\n";
    }
    ~beta(){
        std::cout << "beta's destructor called\n";
    }
};

class Derived: public alpha,beta{
    public:
    Derived(){
        std::cout << "derived's constructor called\n";
    }
    ~Derived(){
        std::cout << "derived's destructor called\n";
    }
};

class Charlie{
    public:
    virtual std::string print() const{
        return "printed from charlie\n";
    }
};

class Delta: public Charlie{
    public:
    virtual std::string print() const override{
        return "printed from delta\n";
    }
};

void print1(const Charlie obj){
    std::cout << obj.print();
}
void print2(const Charlie& objr){
    std::cout << objr.print();
}