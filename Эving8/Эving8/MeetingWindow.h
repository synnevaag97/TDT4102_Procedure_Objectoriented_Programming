#pragma once
#include "Meeting.h"

#include "GUI.h"
using namespace Graph_lib;

class MeetingWindow : public Window{

    private: 
    static constexpr int pad = 30;
    static constexpr int btnW = 100;
    static constexpr int btnH = 50;
    static constexpr int fieldW = 200;
    static constexpr int fieldH = 50;
    static constexpr int fieldPad = 50;

    Button quitBtn;
    Button personNewButn;
    In_box personName;
    In_box personEmail;


    vector<Person*> people;

    public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    ~MeetingWindow();
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void addPerson();
};