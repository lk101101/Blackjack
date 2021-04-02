#ifndef Pack_hpp
#define Pack_hpp
#include <stdio.h>
#include "Card.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Pack {
public:
    // EFFECTS: initializes all 52 cards into pack
    Pack();
    
    // EFFECTS: returns true if pack size is equal to 52; returns false otherwise
    bool is_full();
    
    //EFFECTS: returns true if pack size is equal to 0; returns false otherwise
    bool is_empty();
    
    // REQUIRES: non-empty pack
    // EFFECTS: shuffles cards in a random order
    void shuffle_pack();
    
    // REQUIRES: non-empty pack
    // EFFECTS: deals one card randomly from pack
    Card deal();
    
    // REQUIRES: non-empty pack
    // MODIFIES: Pack vector (decreases size + removes last card)
    // EFFECTS: removes last card in Pack
    void remove_card();
    
    // EFFECTS: prints all cards in pack
    void print_pack();
        
private:
    // pack of cards of type Card
    vector<Card> pack;
    static const int FULL_PACK_SIZE = 52;
};
#endif /* Pack_hpp */
