#include "Card.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;


    // Card ctor
    // EFFECTS: initializes card to Two of Spades
Card::Card() {
    rank = RANK_TWO;
    suit = SUIT_SPADES;
}
    
    // REQUIRES: valid rank, valid suit
    // EFFECTS: Initializes card to inputted rank and suit
Card::Card(const string &rank_in, const string &suit_in) {
    rank = rank_in;
    suit = suit_in;
}
    
    // EFFECTS: returns rank
string Card::get_rank() const {
    return rank;
}
    
    // EFFECTS: returns suit
string Card::get_suit() const {
    return suit;
}
    
    // EFFECTS: returns true if card is a non-ace face card (Jack, Queen, or King)
bool Card::is_face() const {
	if (get_rank() == RANK_JACK || get_rank() == RANK_QUEEN || get_rank() == RANK_KING) {
		return true;
    }
	return false;
}
    
    // EFFECTS: return true if card is an ace card
bool Card::is_ace() const {
    if (get_rank() == RANK_ACE) {
        return true;
    }
    return false;
}

    // EFFECTS: prints name of Card to os
ostream & operator<<(ostream &os, const Card &card) {
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}
 
