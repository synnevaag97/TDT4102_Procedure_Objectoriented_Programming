#pragma once
#include <string>
#include <iostream>
#include <list>


class Person{

    private:
    std::string fornavn;
    std::string etternavn;


    public:
    Person(std::string fornavn, std::string etternavn);

    std::string get_fornavn() const {return fornavn;}
    std::string get_etternavn() const{return etternavn;}

    bool operator <(const Person& p) const;
};

std::ostream& operator<<(std::ostream& out, const Person& o);

void insertOrdered(std::list<Person> &l, const Person& p);