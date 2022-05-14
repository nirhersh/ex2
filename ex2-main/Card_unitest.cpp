#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "Player.h"
#include "Card.h"
void applyEncounterTest();

//to run this test: g++ --std=c++11 -Wall -Werror -pedantic-errors Player.cpp utilities.cpp  Card.cpp Card_unitest.cpp -o Card_unitest.exe
//and then: ./Card_unitest.exe

int main()
{
    applyEncounterTest();
}

void applyEncounterTest()
{
    Player Roei = Player("roei", 25, 10); // maxHp = 25, force = 10, coins = 0, 
    CardStats stats(5, 3, 10, 10, 8, 10); // force = 5, hploss = 3, cost = 10, heal = 10, buff = 8, loot = 10
    Card cards[4];
    cards[0] = Card(CardType::Buff, stats);
    cards[1] = Card(CardType::Treasure, stats);
    cards[2] = Card(CardType::Battle, stats); //
    

    assert(Roei.getAttackStrength() == 11);
    cards[0].applyEncounter(Roei); //nothing changes
    cards[1].applyEncounter(Roei); //coins = 10
    cards[1].applyEncounter(Roei); //coins = 20
    cards[0].applyEncounter(Roei); //force = 18 coins = 10
    assert(Roei.getAttackStrength() == 19);
    cards[2].applyEncounter(Roei); //coins = 20, level = 2, 
    assert(Roei.getAttackStrength() -Roei.getLevel() == 18);
    assert(Roei.getLevel() == 2);
    CardStats stats1(30, 3, 10, 10, 8, 10); // force = 5, hploss = 3, cost = 10, heal = 10, buff = 8, loot = 10
    cards[3] = Card(CardType::Battle, stats1);
    cards[3].applyEncounter(Roei); //lost, hp == 22
    assert(Roei.getLevel() == 2);
    cards[2].applyEncounter(Roei); //coins = 30, level = 3, 
    assert(Roei.getAttackStrength() -Roei.getLevel() == 18);
    assert(Roei.getLevel() == 3);

    cards[0].applyEncounter(Roei); ////force = 26 coins = 20
    assert(Roei.getAttackStrength() -Roei.getLevel() == 26);
    cards[0].applyEncounter(Roei); ////force = 34 coins = 10
    assert(Roei.getAttackStrength() -Roei.getLevel() == 34);

    assert(Roei.getLevel() == 3);
    
    cards[0].applyEncounter(Roei); ////force = 42 coins = 0
    assert(Roei.getAttackStrength() -Roei.getLevel() == 42);
    cards[0].applyEncounter(Roei); ////force = 42 coins = 0
    assert(Roei.getAttackStrength() -Roei.getLevel() == 42);

    cards[1].applyEncounter(Roei); //coins = 10
    cards[0].applyEncounter(Roei); ////force = 50 coins = 0
    assert(Roei.getAttackStrength() -Roei.getLevel() == 50);
    assert(Roei.getLevel() == 3);
}