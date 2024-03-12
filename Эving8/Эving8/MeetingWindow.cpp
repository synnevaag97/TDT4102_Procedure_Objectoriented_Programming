#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
    :Window(xy, w, h, title), quitBtn{Point{w-pad-btnW,pad},btnW, btnH, "Quit", cb_quit},
    personName{Point{fieldPad, pad}, fieldW, fieldH, "Name"}, 
    personEmail{Point{fieldPad, pad*2+fieldH}, fieldW, fieldH, "Email"}, 
    personNewButn{Point{fieldPad, pad*3+fieldH*2}, btnW, btnH, "AddPerson",cb_new_person}
    {
        attach(quitBtn);
        attach(personName);
        attach(personEmail);
        attach(personNewButn);
    }

MeetingWindow::~MeetingWindow()
{
	for (auto* p : people) {
		delete p;
	}
}

//Callback function
void MeetingWindow::cb_quit(Address, Address pw){
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_new_person(Address, Address pw){
    reference_to<MeetingWindow>(pw).addPerson();
}


void MeetingWindow::addPerson(){

    const string& name = personName.get_string();
	const string& email = personEmail.get_string();

    if(name.empty() || email.empty()){
        cerr << "Not enough info to add person."; 
        return;
    }
    people.push_back(new Person{name, email});

    personName.clear_value();
    personEmail.clear_value();
}