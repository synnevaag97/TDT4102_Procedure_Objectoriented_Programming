#pragma once
#include "std_lib_facilities.h"

//Difference between public, private and protected.
// Public ar class functions and variables that can be access outside the class, 
//e.g. when a class instance is called in main. 
// When these are private these can only be accessed within the class. They can't be accessed from main e.g.
// When these are protected, both the class itself and sub-classes can access these. But they still can't be accessed from main. 

class Animal{
    protected:
    string name;
    int age;

    public: 
    Animal(string n, int a): name(n), age(a){};
    virtual string toString() const = 0; // const = 0 makes the class abstract.
};

class Cat : public Animal{
    public:
    Cat(string name, int age) : Animal(name, age){};
    string toString() const override; // Have to write const because of the abstraction in Animal?
};

class Dog : public Animal{
    public: 
    Dog(string name, int age) : Animal(name, age){};
    string toString() const override; 
};

void testAnimal();