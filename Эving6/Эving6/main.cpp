#include "files.h"
#include "maps.h"
#include "Temperature.h"


int main(){
    //writeToFile();
    //letterStatistics("grunnlov.txt");
    // CourseCatalog NTNUcoures;
    // NTNUcoures.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    // NTNUcoures.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    // NTNUcoures.addCourse("TMA4100", "Matematikk 1");
    // //NTNUcoures.getCourse("TDT4110");
    // //NTNUcoures.getCourse("TDT4102");
    // //NTNUcoures.getCourse("TMA4100");
    // NTNUcoures.addCourse("TDT4102", "C++");
    // // I can override a codename in the map by using the function above.
    // cout << NTNUcoures << endl;

    // NTNUcoures.storeData();

    // NTNUcoures.loadData("NTNUcourses.txt");
    // cout << NTNUcoures << endl;


    //ifstream temp_file{"temperatures.txt"};
    //Temps t;
    //temp_file >> t; // t.max = 3.14, t.min = -4.0
    vector<Temps> temps = readTemps("Temperature.txt");
    tempSats(temps);
    

}
