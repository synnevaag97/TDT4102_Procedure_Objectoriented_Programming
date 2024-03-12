#pragma once
#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus{Trondheim, Aalesund, Gjovik};

const map<Campus, string> campusToString {
	{ Campus::Trondheim, "Trondheim" },
	{ Campus::Aalesund, "Aalesund" },
	{ Campus::Gjovik, "Gjovik "}
}; //Need to use map to map the campuses to their names. 

ostream& operator<<(ostream& os, Campus c);


class Meeting
{
    private: 
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    
    static inline set<const Meeting*> meetings{};


    public:
    Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader);
    ~Meeting();
    
    int get_day() const {return day;};
    int get_startTime() const {return startTime;}
    int get_endTime() const {return endTime;}
    Campus get_location() const {return location;}
    string get_subject() const {return subject;}
    const Person& get_leader() const {return *leader;}

    void addParticipant(Person* p);
    vector<string> getParticipantsList() const;
    vector<const Person*> findPotentialCoDriving(); 

};

ostream& operator<<(ostream& os, const Meeting& meeting);
