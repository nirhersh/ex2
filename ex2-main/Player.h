//
// Created by Nir Herscovici on 07/04/2022.
//
#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include "utilities.h"

using namespace std;

class Player{
public:
    static const int maxLevel = 10;
    static const int minLevel = 1;
    static const int minHealth = 0;
    static const int minCoins = 0;
    /*
    *
    * C'tor of the Player class
    * 
    * @param name - the name of the new player
    * @param maxHP - the maximum HP the player can have, default value is 100
    * @param force - the initial force of the player, defualt value is 5
    * @param level - the initial level of the player, default value is 1
    * @param coins - the initial amount of coins the player have, default value is 0
    * @return 
    *        A new instance of a player
    */
    Player(const string name, const int maxHP=100, const int force=5, const int level=1, const int coins=0);

    /*
    *
    * Destructor of the Player class
    * 
    */
    ~Player();

    /*
    *
    * Copy C'tor of the Player class
    * 
    */
    Player(const Player& player);

    /*
    *
    * Assignment operator of the Player class
    * 
    */
    Player& Player::operator=(const Player& player);

    /*
    *
    * a function that prints the player info
    * 
    */
    void Player::printInfo();

    /*
    *
    * a function that increments the level of the player by one, unless the player is at the maximum value, than it does nothing
    * 
    */
    void Player::levelUp();
    
    /*
    *
    * a function that returns the current level of the player
    * @return 
    *       The current player level
    */
    int Player::getLevel();

    
    /*
    *
    * a function that adds force to the player
    * 
    * @param forceBuff - the amount of force to add to the player
    * 
    */
    void Player::buff(int forceBuff);

    /*
    *
    * a function that adds HP to the player
    * 
    * @param healthPoints - the amount of HP to add to the player
    * 
    */
    void Player::heal(int healthPoints);

    /*
    *
    * a function that subtracts HP from the player
    * 
    * @param damagePoints - the amount of HP to subtract from the player
    * 
    */
    void Player::damage(int damagePoints);

    /*
    *
    * a function that checks if the player has 0 HP
    * 
    * @return
    *       true if the player has 0 HP, otherwise false
    */
    bool Player::isKnockedOut();

    /*
    *
    * a function that adds coins to the player
    * 
    * @param coins - the amount of coins to add to the player
    * 
    */
    void Player::addCoins(int coins);

    /*
    *
    * a function that subtracts coins from the player
    * 
    * @param payment - the amount of coins to subtract from the player
    * @return 
    *       true if the payment was successfull, false if the player didn't have enough money
    */
    bool Player::pay(int payment);
    
    /*
    *
    * a function that returns the current attack strength of the player: level + force
    * 
    * @return 
    *       the current attack strength of the player
    */
    int Player::getAttackStrength();
private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_healthPoints;
    int m_coins;
};



#endif //EX2_Card_H