#include "CardDeck.h"


CardDeck::CardDeck()
{
    // fill up cards with correct combination of ruits and ranks. 
    for(const auto& r : rankToStringMap){
        for(const auto& s : suitToStringMap){
            Card c(s.first,r.first);
            cards.push_back(c);
        }
    }
}

void CardDeck::swap(int a, int b){
    Card c = cards.at(a);
    cards.at(a) = cards.at(b);
    cards.at(b) = c;
}

void CardDeck::print(){
    for(auto c : cards){
        cout << c.toString() << endl;
    }
}
// What is const auto& vs just auto?

void CardDeck::printShort(){
    for(auto c : cards){
        cout << c.toStringShort() << endl;
    }
}

void CardDeck::shuffle(){
    for(unsigned int i = 0; i < cards.size(); i++){
        int b = rand()%cards.size();
        swap(i,b);
    }
}

Card CardDeck::drawCard(){
    Card c = cards.back();
    cards.pop_back();
    return c;
}