#include "files.h"

void writeToFile(){
    //create file
    const string filename("Data.txt");
    ofstream outfile(filename);

    cout << "Write words to store in file: " << endl;
    for(string words; cin >> words && words!="quit";){
        outfile << words << '\n';
    }   
}

void copyFile(string filename){
    const string copyfilename("copy.txt");
    ofstream outfile(copyfilename);

    ifstream infile;
    infile.open(filename);
    int i=1;
    string line;
    while( getline (infile,line)){
        outfile << i << ": " << line << '\n';
        i++;
    }
}

void letterStatistics(string filename){
    ifstream infile(filename);
    vector<int> statistics(26);
    cout << "hello1";
    string line;
    for(unsigned char c;infile >> c;){
        if(isalpha(c)){
            statistics[tolower(c) - 'a']++;
        }
    }

    cout << "hello2";
    for(char c = 'a'; c < 'z';c++){
        cout << c << ": " << statistics[c-'a'] << endl;
    }
}