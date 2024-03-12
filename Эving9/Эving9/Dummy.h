#pragma once
#include <utility>


class Dummy {
    public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    ~Dummy() {
        delete num;
    }

    Dummy& operator=(Dummy newDummy){
        std::swap(this->num,newDummy.num); // Swap the copied dummy with a new dummy int. 
        return *this; // Return the copied dummy with new memory int. 
    }

    Dummy(Dummy& aDummyWeWantToCopyFrom) : Dummy{}{
        *num = *aDummyWeWantToCopyFrom.num; //We set the num of the new Dummy equal to the dummy we want to copy. 
    }
};

void dummyTest();