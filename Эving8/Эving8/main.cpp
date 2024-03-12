#include "Person.h"
#include "Car.h"
#include "Meeting.h"
#include "MeetingWindow.h"

int main(){
// Car fullCar{0};
// Car car{5};

// Person p1{"p1", "p1@ntnu.no"};
// Person p2{"p2", "p2@ntnu.no"};
// Person p3{"p3", "p3@ntnu.no", &fullCar};
// Person p4{"p4", "p4@ntnu.no", &car};
// Person p5{"p5", "p5@ntnu.no"};
// Person p6{"p6", "p6@ntnu.no"};

// Meeting trh1{1, 9, 14, Campus::Trondheim, "C++", &p1};
// trh1.addParticipant(&p3);

// Meeting gjo{1, 9, 14, Campus::Gjovik, "Fusion", &p2};
// gjo.addParticipant(&p4);

// Meeting trh2{1, 8, 15, Campus::Trondheim, "Faculty naming", &p5};
// trh2.addParticipant(&p6);
// trh2.addParticipant(&p3);
// trh2.addParticipant(&p4);

// cout << "All meetings:\n" << trh1 << '\n' << gjo << '\n' << trh2 << '\n';

// cout << "Persons at meetings concurrent with the " << trh1.get_subject() << "-meeting:\n";
// for (auto* p : trh1.findPotentialCoDriving()) {
//     cout << *p << '\n';
// }

    MeetingWindow win(Point{100,100}, 500, 500, "Potato");
    gui_main();

}