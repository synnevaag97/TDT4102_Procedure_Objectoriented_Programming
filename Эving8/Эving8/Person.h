#pragma once
#include "Car.h"


class Person{
    private:
    string name;
    string email;
    Car* car;

    public:
    Person(string n, string e);
    Person(string n, string e, Car* c);


    string get_name() const;
    string get_email() const;
    void set_email(string new_email);
    bool hasAvailableSeats() const;

    friend ostream& operator<<(ostream& os, const Person& person);

};


