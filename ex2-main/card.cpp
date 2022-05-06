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
    if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
    if(m_effect == CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal); 
        }
    }
    if(m_effect == CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
        player.buff(m_stats.force); 
        }
    } 
    // must be battle:
    if(m_effect == CardType::Battle)
    {
        if(m_stats.force > player.getAttackStrength())
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        } else {
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        } 
    }  

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

