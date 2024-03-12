#include "Mastermind.h"
#include "utilities.h"
#include "masterVisual.h"

int checkCharactersAndPosition(int size, string code, string guess){
    int correct = 0;
    for(int i = 0; i < size; i++){
        if(code[i] == toupper(guess[i])){
            correct++;
        }
    }
    return correct; 
}

int checkCharacters(string code, string guess){
    int number = 0;
    //instead of doing complicated for loops to find only the unique characters in guess we use set.
    set<char> guessCh;
    for(char ch : guess){ //For each char in the string guess.
        guessCh.insert(ch); //Only unique elements are added, no repeated elements. 
    }
    for(char ch : guessCh){
        cout << ch << endl;
        int codeCount = countChar(code,ch); 
        int guessCount = countChar(guess,ch);
        number += min(codeCount, guessCount); 
        //The three lines of code above ensure that we only add a character once. 
    }
    return number;
}

void playMasterMind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    constexpr char lowerLimit = 'A';
    constexpr char upperLimit = lowerLimit +(letters - 1);
    constexpr int maxTries = 6;
    //Constexpr blir benyttet når verdien blir bestemt i kompileringstid. 
    // Vi vet verdien før vi kjører koden.
    //const blir benyttet når vrdien blir bestemt i kjøretid.

    MastermindWindow mwin{Point{900,20}, winW, winH, "Mastermind"};
    string code = randomizeString(size, upperLimit, lowerLimit);
    int trials = 0;
    int posAndCh = 0;
    addGuess(mwin,code,size,'A',trials);
    //hideCode(mwin,size);
    do{
        string guess = mwin.getInput(size, upperLimit, lowerLimit);
        cout << guess << endl;
        int ch = checkCharacters(code, guess);
        posAndCh = checkCharactersAndPosition(size, code, guess);
        addGuess(mwin, guess,size, 'A', trials);
		addFeedback(mwin, posAndCh, ch, size,trials);
		mwin.redraw();


        cout << "You got " << ch << " correct charactes and " << posAndCh << " in correct position." << endl;
        trials++;
    }while(posAndCh < size && trials <= maxTries);

    if(posAndCh == size){
        cout << "Congrats my man! You won :)" << endl;
        cout << "The code was: " << code << endl;
    }else{
        cout << "Sorry you lost!" << endl;
        cout << "The code was: " << code << endl;
    }    
}