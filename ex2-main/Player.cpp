//
// Implementation of Player class
//

#include "Player.h"

using std::string;
using std::cout;

Player::Player(const string name, const int maxHP, const int force) :
m_name(name),
m_maxHP(maxHP),
m_force(force),
m_level(minLevel),
m_healthPoints(maxHP),
m_coins(minCoins)
{}

void Player::printInfo(){
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_healthPoints, m_coins);
}

void Player::levelUp(){
    if(m_level < maxLevel){
        ++m_level;
    }
}

int Player::getLevel(){
    return m_level;
}

void Player::buff(const int forceBuff){
    m_force += forceBuff;
}

void Player::heal(const int hp){
    if(hp + m_healthPoints > m_maxHP){
        m_healthPoints = m_maxHP;
    }else{
        m_healthPoints += hp;
    }
}

void Player::damage(const int damagePoints){
    m_healthPoints -= damagePoints;
    if(m_healthPoints < minHealth){
        m_healthPoints = minHealth;
    }
}

bool Player::isKnockedOut(){
    return minHealth == m_healthPoints;
}

void Player::addCoins(const int coins){
    m_coins += coins;
}

bool Player::pay(const int payment){
    if(m_coins - payment < minCoins){
        return false;
    }else{
        m_coins -= payment;
    }
    return true;
}

int Player::getAttackStrength(){
    return m_force + m_level;
}

