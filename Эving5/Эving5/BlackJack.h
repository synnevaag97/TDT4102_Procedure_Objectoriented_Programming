#pragma once
#include "CardDeck.h"

class BlackJack{
    private:
    CardDeck cardDeck;
    vector<Card> player;
    vector<Card> dealer;
    void printPlayerCards();
    void printDealerCards();
    void hit(vector<Card>& participant);
    void stand();
    int sum(vector<Card> participant);
    
    public:
    BlackJack();
    void playRound();
};