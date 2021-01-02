#ifndef Human_hpp
#define Human_hpp
#include <stdio.h>
#include "Card.hpp"
#include "Pack.hpp"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Interface for Player and Dealer classes to inherit from
class Human {
public:
    // EFFECTS: returns name of Player/Dealer
    virtual const string& get_name() const = 0;
    
    // EFFECTS: return type of Player/Dealer
    virtual const string& get_type() const = 0;
    
    // EFFECTS: adds card to PLayer's hand to 'hit'
    virtual void hit(const Card &c) = 0;
    
    // EFFECTS: return total score of the cards in player's hand
    virtual int total_score() = 0;
    
    // EFFECTS: prints all cards in hand
    virtual void print_hand() = 0;
    
    // EFFECTS: returns true if total_score is equal to 21
    virtual bool is_equal_to_21() = 0;
    
    // EFFECTS returns true if total_score is above 21
    virtual bool is_above_21() = 0;
            
    // avoid compiler issues
    virtual ~Human() {}
};

// EFFECTS: creates pointers for Player/Dealer using name and type
Human* Human_factory(const string& name, const string& type);

//EFFECTS: Prints player's name to os
ostream& operator<<(ostream& os, const Human& h);

#endif /* Human_hpp */
