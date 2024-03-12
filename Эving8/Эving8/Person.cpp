#include "Person.h"

Person::Person(string name, string email)
    : Person(name, email, nullptr)
{}

Person::Person(string n, string e, Car* c)
    : name(n), email(e), car(c)
{}

string Person::get_name() const{
    return name;
}
string Person::get_email() const{
    return email;
}
void Person::set_email(string new_email){
    email = new_email;
}

bool Person::hasAvailableSeats() const{
    if(car != nullptr){
        return car->hasFreeSeats();
    }
    return false;
}


ostream& operator<<(ostream& os, const Person& p) 
{
	return os << p.name << " (" << p.email << ")";
}