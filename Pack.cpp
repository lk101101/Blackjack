#include "Pack.hpp"
using namespace std;

// MODIFIES: Pack vector
// EFFECTS: initializes Pack vector with 52 Cards
Pack::Pack() {
    pack.clear();
    
    string current_suit;
    string current_rank;
    
    // put every card of every suit + rank into pack
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            current_suit = SUIT_ARRAY[suit];
            current_rank = RANK_ARRAY[rank];
            
            pack.push_back(Card(current_rank, current_suit));
        }
    }
}

// EFFECTS: returns true if Pack size is equal to 52; returns false otherwise
bool Pack::is_full() {
    return pack.size() == FULL_PACK_SIZE;
}

// EFFECTS: returns true if Pack size is equal to 0; returns false otherwise
bool Pack::is_empty() {
    return pack.empty();
}

// MODIFIES: order of Cards within Pack vector
// EFFECTS: shuffles Cards in a random order
void Pack::shuffle_pack() {
    default_random_engine rng (static_cast<unsigned> (chrono::system_clock::now().time_since_epoch().count()));
    shuffle(pack.begin(), pack.end(), default_random_engine(rng));
}

// EFFECTS: returns last card in Pack
Card Pack::deal() {
    return pack.back();
}

// REQUIRES: non-empty pack
// MODIFIES: Pack vector (decreases size + removes last card)
// EFFECTS: removes last card in Pack
void Pack::remove_card() {
    pack.pop_back();
}

// EFFECTS: prints all cards in Pack
void Pack::print_pack() {
    for (int i = 0; i < FULL_PACK_SIZE; i++) {
        cout << pack[i] << endl;
    }
}
