#include "Meeting.h"

ostream& operator<<(ostream& os, Campus c)
{
    return os << campusToString.at(c);
}

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader)
: day(day), startTime(startTime), endTime(endTime), location(location), subject(subject), leader(leader)
{
    meetings.insert(this);
    participants.insert(leader);
}

void Meeting::addParticipant(Person* p){
    participants.insert(p);
}

vector<string> Meeting::getParticipantsList() const{
    vector<string> results;
    for(auto p:participants)
    {
        results.push_back(p->get_name());
    }
    return results;
}

vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> persons;
    // Go trhough all meeting and compare to this meeting to find same meeting.
    for(auto* m : meetings){
        if(m->get_location()==location && m->get_startTime()-startTime<=1 && m->get_endTime()-endTime<=1 && m->get_day() == day){
            for(const Person* p : m->participants){
                if(p->hasAvailableSeats()){
                    persons.push_back(p);
                }
            }
        }
    }
    return persons;

}


ostream& operator<<(ostream& os, const Meeting& meeting){
    return os << meeting.get_subject() << " meeting at " << 
    meeting.get_location() << " from " << meeting.get_startTime() <<
    " to " << meeting.get_endTime() << " lead by " << meeting.get_leader() << endl;
}



Meeting::~Meeting()
{
    meetings.erase(this);
}