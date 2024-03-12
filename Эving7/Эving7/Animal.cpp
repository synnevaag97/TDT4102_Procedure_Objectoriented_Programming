#include "Animal.h"
#include "Graph.h"

using namespace Graph_lib; // What does this mean? namespace?


string Animal::toString() const{ //Also need const after () because of abstraction. 
    return "Animal: " + name + ", " + to_string(age);
}

string Cat::toString() const{
    return "Cat: " + name + ", " + to_string(age);
}

string Dog::toString() const{
    return "Dog: " + name + ", " + to_string(age);
}

void testAnimal(){
    // Cant have an instance of abstract class.
    //Animal animal("Peter", 20);
    //cout << animal.toString() << endl;

    Dog dog("Karl", 25);
    cout << dog.toString() << endl;

    Cat cat("Jump", 97);
    cout << cat.toString() << endl;

    Vector_ref<Animal> Animals;
    //Animals.push_back(animal);
    Animals.push_back(dog);
    Animals.push_back(cat);

    for(auto x : Animals){
        cout << x->toString() << endl;
    }
    
}