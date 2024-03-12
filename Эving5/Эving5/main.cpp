#include "std_lib_facilities.h"
#include "BlackJack.h"

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString(r);
    // string suit = suitToString(s);
    // cout << "Rank: " << rank << " Suit: " << suit << '\n';
    
    // Card c{Suit::spades, Rank::ace};
    // cout << c.toString() << '\n';
    // cout << c.toStringShort() << '\n';

    
    char play;
    cout << "Play a game? " << endl;
    cin >> play;
    while(play == 'y'){
        BlackJack game;
        game.playRound();
        cout << "Play again? " << endl;
        cin >> play;
    }
}