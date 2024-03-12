#include "BlackJack.h"

BlackJack::BlackJack(){
    cardDeck.shuffle();
    player.push_back(cardDeck.drawCard());
    dealer.push_back(cardDeck.drawCard());
    player.push_back(cardDeck.drawCard());
    dealer.push_back(cardDeck.drawCard());
    printDealerCards();
    printPlayerCards();
}

void BlackJack::printPlayerCards(){
    cout << "Players cards: "<< endl;
    for(auto c : player){
        cout << "   " << c.toString() << endl;
    }
    cout << "Sum of player cards: " << sum(player) << endl;
}

void BlackJack::printDealerCards(){
    cout << "Dealers cards: " << endl;
    for(unsigned int i = 1; i < dealer.size();i++){
        cout << "   " << dealer.at(i).toString() << endl;
    }
}

void BlackJack::hit(vector<Card>& participant){
    participant.push_back(cardDeck.drawCard());
    //printPlayerCards();
}

int BlackJack::sum(vector<Card> participant){
    int sum = 0;
    for(auto c : participant){
        sum += static_cast<int>(c.getRank());
    }
    return sum;
}



void BlackJack::playRound(){
    while(sum(player)<=21){
        char call;
        cout << "Stand(s) or Hit(h)?" << endl;
        cin >> call;
        if(call == 'h'){
            hit(player);
        }
        if(sum(dealer)<=17){
            hit(dealer);
        }
        if(call == 's'){
            break;
        }
        printPlayerCards();
        printDealerCards();
    }
    cout << "Dealer sum: " << sum(dealer) << endl;
    cout << "Player sum: " << sum(player) << endl; 
    if(sum(player)>21){
        cout << "You lost brah!" << endl;
    }else if(sum(player) <= 21 && sum(dealer) >= sum(player)){
        cout << "You lost brah!" << endl;
    }else if(sum(player) <= 21 && sum(dealer) < sum(player)){
        cout << "You freaking won brah!" << endl;
    }
}