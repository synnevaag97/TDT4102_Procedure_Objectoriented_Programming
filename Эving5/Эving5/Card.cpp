#include "Card.h"

string rankToString(Rank var){
    return rankToStringMap.at(var);    
}
string suitToString(Suit var){
    return suitToStringMap.at(var);
}

/*  
Oppgave 1 e)
To fordeler med å bruke symboler(enum class) framfor f.eks heltall og strenger i koden er:
    - Kompilatoren vil ikke fange opp feil hvis man skriver feil, men man vil da få kode som ikke oppfører 
    seg som forventet, der det er veldig vanskelig å finne feilen
    - Det øker lesbarheten av koden 

*/


Card::Card(Suit suit, Rank rank): s(suit), r(rank) 
{}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    return rankToStringMap.at(r) +" of " + suitToStringMap.at(s);
}

string Card::toStringShort(){
    char suit = suitToString(s)[0];
    string rank = to_string(static_cast<int>(r));
    return suit + rank;
}