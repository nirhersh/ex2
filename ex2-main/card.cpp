#include "Card.h"
#include "utilities.h"
#include <iostream>
#include "player.h"
using std::cout;
using std::endl;


Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    if(this->m_effect == CardType::Treasure)
        player.addCoins(this->m_stats.loot);
    if(this->m_effect == CardType::Heal)
        player.heal(this->m_stats.hpLossOnDefeat);
    if(this->m_effect == CardType::Buff)
        player.buff(this->m_stats.force);    
        
}

void Card::printInfo() const
{
    if(this->m_effect == CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
    }
    if(this->m_effect == CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
    }
    if(this->m_effect == CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }
    printTreasureCardInfo(this->m_stats);
}

