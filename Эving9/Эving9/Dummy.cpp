#include "Dummy.h"
#include <iostream>

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
}

// Til slutt når vi endrer c til 5, vil også a og b endres til 5. 
// Dette skjer siden b en en kopi av a og uten en .... vil den har samme
// minneaddresse. Når vi og sette c=a vil c være en kopi av a som gjør 
// at alle instansene nå peker på samme minne adresse. Så når vi gjør siste
// endring på c vil det være denne som bestemmer de andre. Hvis vi fjerner 
// c=5 vil alle være lik 3. 

// For å fikse c = a må vi lage en tilordingsoperator/kopioperatoren. 
// For å fikse b{a} må vi lage en kopikonstruktør

// Dette programmet krasjer til slutt siden vi 
// prøver å kopiere a i variabelen c. 
// Siden vi ikke har laget kopikonstruktøren riktig så lages
// det bare en kopi som peker til samme minne som er allokert i orginalen. 
// Når destruktøren da kjøres vil den frijøre minnet for både
// orginalen og kopien. Dette gjør at programmet krasjer. 


// Med en kopikonstruktør og en kopioperator definert så funket det som det skulle. 