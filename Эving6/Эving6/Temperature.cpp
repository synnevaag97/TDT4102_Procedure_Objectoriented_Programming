#include "Temperature.h"


istream &operator>>(istream &is, Temps &t){
    return is >> t.max >> t.min;
}

vector<Temps> readTemps(const string &filename){
    vector<Temps> temperatures;
    ifstream tempFile(filename);
    for(Temps t;tempFile >> t;){
        temperatures.push_back(t);
    }
    return temperatures;
}

void tempSats(const vector<Temps>& temps){
    double maximum = 0;
    double minimum = 100;
    int MaxDay;
    int MinDay;
    for(size_t i = 0; i < temps.size(); i++){
        if(temps[i].max > maximum){
            maximum = temps[i].max;
            MaxDay=i;
        }
        if(temps[i].min < minimum){
            minimum = temps[i].min;
            MinDay = i;
        }
    }
    cout << "Highest temperature was " << maximum << " at day " << MaxDay << endl;
    cout << "Lowst temperature was " << minimum << " at day " << MinDay << endl;
}
