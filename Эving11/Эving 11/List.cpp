#include "List.h"

Person::Person(std::string fornavn, std::string etternavn) : fornavn{fornavn},etternavn{etternavn}
{}


std::ostream& operator<<(std::ostream& out, const Person& person){
    out << person.get_fornavn() << person.get_etternavn() << '\n';
    return out;
}

void insertOrdered(std::list<Person> &l, const Person& p){
    for(auto person = l.begin(); person != l.end() ; person++){
        if(p < *person){
            l.insert(person,p);
            return;
        }
    }
    l.push_back(p);
    
}

bool Person::operator <(const Person& p) const{
    return (etternavn+fornavn) < (p.etternavn + p.fornavn);
}
