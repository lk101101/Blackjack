#include "Human.hpp"
#include "Card.hpp"
#include "Pack.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
    
class Player : public Human {
public:
    // initializes Player with name + type
    Player(const string name, const string type) : name(name), type(type) {}
    
    // EFFECTS: returns name of Player
    const string& get_name() const {
        return name;
    }
    
    // EFFECTS: returns type of Player
    const string& get_type() const {
        return type;
    }
    
    // MODIFIES: hand vector (increases size by 1 + adds a new Card to end of hand)
    // EFFECTS: adds card to Player's hand to 'hit'
    void hit(const Card &c) {
        hand.push_back(c);
    }
    
    // EFFECTS: returns Player's total score of current hand
    int total_score() {
        return hand_score(hand);
    }
    
    // EFFECTS: returns true if Player's total score is equal to 21
    bool is_equal_to_21() {
        if (total_score() == 21 ) {
            return true;
        }
        return false;
    }
    
    // EFFECTS: returns true if Player's total score is above 21
    bool is_above_21() {
        if (total_score() > 21) {
            return true;
        }
        return false;
    }
    
    // EFFECTS: prints Cards in Player's hand
    void print_hand() {
        for (int i = 0; i < (int)(hand.size()); ++i) {
            cout << hand[i] << endl;
        }
        cout << endl;
    }

    
private:
    vector<Card> hand;
    string name;
    string type;
    
    // EFFECTS: returns score of Player's hand
    static int hand_score(const vector<Card>& hand) {
        int score = 0;
        for (int i = 0; i < (int)hand.size(); ++i) {
            // face cards = 10 points
            if (hand[i].is_face()) {
                score += 10;
            }

            // ace case
            if (hand[i].is_ace()) {
                // if score is more than 10, count ace as 1
                if (score > 10) {
                    score += 1;
                    // cout << "Ace counts as 1." << endl;
                }
                // if score is equal to or less than 10, count ace as 11
                else {
                    score += 11;
                    // cout << "Ace counts as 11." << endl;;
                }
            }
            
            // regulars Cards (2 - 10) are worth their respective values
            if (hand[i].get_rank() == "Two") {
                score += 2;
            }
            if (hand[i].get_rank() == "Three") {
                score += 3;
            }
            if (hand[i].get_rank() == "Four") {
                score += 4;
            }
            if (hand[i].get_rank() == "Five") {
                score += 5;
            }
            if (hand[i].get_rank() == "Six") {
                score += 6;
            }
            if (hand[i].get_rank() == "Seven") {
                score += 7;
            }
            if (hand[i].get_rank() == "Eight") {
                score += 8;
            }
            if (hand[i].get_rank() == "Nine") {
                score += 9;
            }
            if (hand[i].get_rank() == "Ten") {
                score += 10;
            }
            
        }
        return score;
    }
};



class Dealer : public Human {
public:
     // Dealer initializer list
    Dealer(const string name, const string type) : name(name), type(type) {}
    
    // EFFECTS: returns name of Dealer
    const string& get_name() const {
        return name;
    }
    
    // EFFECTS: returns type of Dealer
    const string& get_type() const {
        return type;
    }
    
    // EFFECTS: adds card to Player's hand to 'hit'
    void hit(const Card &c) {
        dealer_hand.push_back(c);
    }
    
    // EFFECTS: returns total score of the cards in Dealer's hand
    int total_score() {
        return dealer_hand_score(dealer_hand);
    }
    
    // EFFECTS: returns true if total score is equal to 21
     bool is_equal_to_21() {
        if (total_score() == 21 ) {
            return true;
        }
        return false;
    }
    
    // EFFECTS: returns true if total score is above 21
    bool is_above_21() {
        if (total_score() > 21) {
            return true;
        }
        return false;
    }
    
    // EFFECTS: prints all cards in hand
    void print_hand() {
        for (int i = 0; i < (int)(dealer_hand.size()); ++i) {
            cout << dealer_hand[i] << endl;
        }
        cout << endl;
    }
    
    
private:
    string name;
    vector<Card> dealer_hand;
    string type;
    
    // TO DO: implement unique way to count + print Dealer's hand (only revealing first card unless first card is a ten-card or ace)
    
    // EFFECTS: returns score of Dlayer's hand
   static int dealer_hand_score(const vector<Card>& dealer_hand) {
        int score = 0;
    
        for (int i = 0; i < (int)dealer_hand.size(); ++i) {
            // face cards = 10 points
            if (dealer_hand[i].is_face()) {
                score += 10;
            }

            // ace case
            if (dealer_hand[i].is_ace()) {
                // if score is more than 10, count ace as 1
                if (score > 10) {
                    score += 1;
                    // cout << "Ace counts as 1." << endl;
                }
                // if score is equal to or less than 10, count ace as 11
                else {
                    score += 11;
                    // cout << "Ace counts as 11." << endl;;
                }
            }
                
            if (dealer_hand[i].get_rank() == "Two") {
                score += 2;
            }
            if (dealer_hand[i].get_rank() == "Three") {
                score += 3;
            }
            if (dealer_hand[i].get_rank() == "Four") {
                score += 4;
            }
            if (dealer_hand[i].get_rank() == "Five") {
                score += 5;
            }
            if (dealer_hand[i].get_rank() == "Six") {
                score += 6;
            }
            if (dealer_hand[i].get_rank() == "Seven") {
                score += 7;
            }
            if (dealer_hand[i].get_rank() == "Eight") {
                score += 8;
            }
            if (dealer_hand[i].get_rank() == "Nine") {
                score += 9;
            }
            if (dealer_hand[i].get_rank() == "Ten") {
                score += 10;
            }
            
        }
        return score;
    }
};

// EFFECTS: creates pointers for Player/Dealer using name and type
Human* Human_factory(const string& name, const string& type) {
    if (type == "Player") {
        return new Player(name, type);
    }
    if (type == "Dealer") {
        return new Dealer(name, type);
    }
    return nullptr;
}

//EFFECTS: Prints player's name to os
ostream& operator<<(ostream& os, const Human& h) {
    os << h.get_name();
    return os;
}
