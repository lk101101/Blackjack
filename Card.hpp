#ifndef Card_hpp
#define Card_hpp
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;


class Card {
public:
    // rank names
    static constexpr const char* const RANK_TWO = "Two";
    static constexpr const char* const RANK_THREE = "Three";
    static constexpr const char* const RANK_FOUR = "Four";
    static constexpr const char* const RANK_FIVE = "Five";
    static constexpr const char* const RANK_SIX = "Six";
    static constexpr const char* const RANK_SEVEN = "Seven";
    static constexpr const char* const RANK_EIGHT = "Eight";
    static constexpr const char* const RANK_NINE = "Nine";
    static constexpr const char* const RANK_TEN = "Ten";
    static constexpr const char* const RANK_JACK = "Jack";
    static constexpr const char* const RANK_QUEEN = "Queen";
    static constexpr const char* const RANK_KING = "King";
    static constexpr const char* const RANK_ACE = "Ace";

    // suit names
    static constexpr const char* const SUIT_SPADES = "Spades";
    static constexpr const char* const SUIT_HEARTS = "Hearts";
    static constexpr const char* const SUIT_CLUBS = "Clubs";
    static constexpr const char* const SUIT_DIAMONDS = "Diamonds";
    
    
    // Card ctor
    // EFFECTS: initializes card to Two of Spades
    Card();
    
    // REQUIRES: valid rank, valid suit
    // Initializes card to inputted rank and suit
    Card(const string &rank_in, const string &suit_in);
    
    // EFFECTS: returns rank
    string get_rank() const;
    
    // EFFECTS: returns suit
    string get_suit() const;
    
    // EFFECTS: returns true if card is a non-ace face card (Jack, Queen or King)
    bool is_face() const;
    
    // EFFECTS: return true if card is an ace card
    bool is_ace() const;
    
    
private:
    string rank;
    string suit;
    
};

// EFFECTS: prints name of Card to os
ostream & operator<<(ostream &os, const Card &card);

// EFFECTS: puts all suits into an array
constexpr const char* const SUIT_ARRAY[] = {
  Card::SUIT_SPADES,
  Card::SUIT_HEARTS,
  Card::SUIT_CLUBS,
  Card::SUIT_DIAMONDS
};

// EFFECTS: puts all ranks into an array
constexpr const char* const RANK_ARRAY[] = {
  Card::RANK_TWO,
  Card::RANK_THREE,
  Card::RANK_FOUR,
  Card::RANK_FIVE,
  Card::RANK_SIX,
  Card::RANK_SEVEN,
  Card::RANK_EIGHT,
  Card::RANK_NINE,
  Card::RANK_TEN,
  Card::RANK_JACK,
  Card::RANK_QUEEN,
  Card::RANK_KING,
  Card::RANK_ACE
};

const int NUM_SUITS = 4;

const int NUM_RANKS = 13;

#endif /* Card_hpp */
