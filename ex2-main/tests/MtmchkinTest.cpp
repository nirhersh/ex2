#include <functional>
#include <string>
#include <iostream>
#include "../Player.h"
#include "../Card.h"
#include "../Mtmchkin.h"

using std::cout;
using std::endl;

bool testMtmchkinConstructors(){
    Card cards[4];
    CardStats stats {1, 20, 10, 5, 5, 40};
    cards[0] = Card(CardType::Treasure, stats);
    cards[1] = Card(CardType::Buff, stats);
    cards[2] = Card(CardType::Battle, stats);
    cards[3] = Card(CardType::Heal, stats);
    Mtmchkin game1("Nir", cards, 4);

    bool copyCtor = false, assignmentOp = false;
    cout << "\n--------------Checking copy constructor--------------" << endl;
    Mtmchkin game2 = game1;
    while(!game1.isOver() && !game2.isOver()){
        cout << "\n--------------game1--------------" << "\n";
        game1.playNextCard();
        cout << "\n--------------game2--------------" << "\n";
        game2.playNextCard();
    }
    if (game1.getGameStatus()==game2.getGameStatus()){
        copyCtor = true;
    }

    Mtmchkin game3("Nir", cards, 4);
    Card otherCards[2];
    CardStats stats2 {1, 2, 14, 15, 25, 20};
    cards[0] = Card(CardType::Treasure, stats2);
    cards[1] = Card(CardType::Buff, stats2);
    Mtmchkin game4("Not Nir", otherCards, 2);
    game4 = game3;
    cout << "\n--------------Checking Assignment Operator--------------" << endl;
    while(!game3.isOver() && !game4.isOver()){
        cout << "\n--------------game3--------------" << "\n";
        game3.playNextCard();
        cout << "--------------game4--------------" << "\n";
        game4.playNextCard();
    }
    if (game3.getGameStatus()==game4.getGameStatus()){
        assignmentOp = true;
    }
    return (assignmentOp && copyCtor);
}

int main(int argc, char *argv[]) {
    if(testMtmchkinConstructors()){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }

    return 0;
}
