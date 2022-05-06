#include "Card.h"
#include "utilities.h"
#include <iostream>
#include "player.h"
#include "Mtmchkin.h"
using std::cout;
using std::endl;
using std::string;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
     m_player(string(playerName)),
     m_cardsArray(new Card[numOfCards]),
     m_numOfCards(numOfCards),
     m_currentCard(0),
     m_gameStatus(GameStatus::MidGame)
{
     for (int i = 0; i < numOfCards; i++)
     {
          m_cardsArray[i] = cardsArray[i];
     }  
}

Mtmchkin::Mtmchkin(const Mtmchkin& other) :
     m_player(other.m_player),
     m_cardsArray(new Card[other.m_numOfCards]),
     m_numOfCards(other.m_numOfCards),
     m_currentCard(other.m_currentCard),
     m_gameStatus(other.m_gameStatus)
{
     for (int i = 0; i < other.m_numOfCards; i++)
     {
          m_cardsArray[i] = other.m_cardsArray[i];
     }  
}

Mtmchkin::~Mtmchkin(){
     delete[] m_cardsArray;
}


GameStatus Mtmchkin::getGameStatus() const{
     return m_gameStatus;
}

void Mtmchkin::playNextCard(){
     m_cardsArray[m_currentCard].printInfo();
     m_cardsArray[m_currentCard].applyEncounter(m_player);
     m_player.printInfo();
     ++m_currentCard;
     // if last card go back to the start of the card array
     if(m_currentCard >= m_numOfCards){
          m_currentCard = 0;
     }
}

bool Mtmchkin::isOver(){
     if(m_gameStatus == GameStatus::Win || m_gameStatus == GameStatus::Loss){
          return true;
     }else{
          return false;
     }
}