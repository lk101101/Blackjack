#include "Human.hpp"
#include "Card.hpp"
#include "Pack.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <array>
using namespace std;


class Game {
private:
    Pack pack;
    vector<Human*> players;
    
    // Dealer variables
    int dealer_index;
    int dealer_score;
    string dealer_type;

    // keeps track of how many players have taken their turn
    int num_players;
    
public:
    // Game ctor
    // REQUIRES: correct command line arguments
    // EFFECTS: initializes and creates pointers to players and dealer and updates number of players
    Game(int argc, char* argv[]) {
        // initialize players (including dealer) and add them to the Player vector
        string name;
        string type;
        for (int i = 1; i < argc; i+=2) {
            name = argv[i];
            type = argv[i+1];
            players.push_back(Human_factory(name, type));
        }
        
        // calculate number of players in vector (including dealer)
        num_players = (int)(players.size());
        
        // initialize Dealer variables
        dealer_index = num_players - 1;
        dealer_type = players[dealer_index]->get_type();
    }
    
    // EFFECTS: returns Cards in player's hand + total score of hand
    void print_player_hand(int player_num) {
        cout << endl;
        cout << *players[player_num] << ", your cards are: " << endl;
        players[player_num]->print_hand();
        cout << "Your hand's total score is ";
        cout << players[player_num]->total_score();
    }
    
    // EFFECTS: will deal cards to players as long as they choose to hit and/or their score is below 21
    void pass_or_hit(int player_num) {
        string answer;
        cout << "*** " << *players[player_num] << "'s turn ***" << endl;
        
        // will give player option to continue hitting until their total score is either equal to or above 21 or they decide to pass
        while (!players[player_num]->is_equal_to_21() && !players[player_num]->is_above_21() && answer != "pass") {
            print_player_hand(player_num);
            // ask player if they will pass or hit
            cout << " which is below 21. Will you pass or hit? (type 'pass' or 'hit')" << endl;

            cin >> answer;
            if (answer == "hit") {
                cout << "*** ADDING CARD ***" << endl;
                players[player_num]->hit(pack.deal());
                pack.remove_card();
                pack.shuffle_pack();
            }
        }
        
        print_player_hand(player_num);
        
        // score equal to 21
        if (players[player_num]->is_equal_to_21()) {
            cout << " which is equal to 21. Your turn is over." << endl;
        // score above 21
        } else if (players[player_num]->is_above_21()) {
            cout << " which is above 21. Your turn is over." << endl;
        // answer == "pass"
        } else {
            cout << ". You have chosen to pass. Your turn is over." << endl;
        }
        cout << "*** END OF TURN ***" << endl;
    
        // reset answer
        answer = " ";
        
        // update dealer_score if index is equal to current index
        if (dealer_index == player_num) {
            dealer_score = players[player_num]->total_score();
        }
    }
    
    // EFFECTS: determines winners of game by comparing player's and dealer's scores to 21 and to each other
    void compare_player_to_dealer (int player_num) {
        int player_score = players[player_num]->total_score();
        string player_type = players[player_num]->get_type();
        
        cout << "Player's score: " << player_score << endl;
        cout << "Dealer's score: " << dealer_score << endl;
        cout << endl;
        cout << "*** RESULTS ***" << endl;
        
        // Case 1: at least one score over 21
        // both player and dealer scores are over 21
        if (player_score > 21 || dealer_score > 21) {
            if (player_score > 21 && dealer_score > 21) {
                // losing message
                cout << player_type << " " << *players[player_num] << " and " << dealer_type << " " << *players[dealer_index] << ", your scores are over 21. You both lose. :(" << endl;
                // player score over 21
            } else if (player_score > 21 && dealer_score <= 21) {
                // losing message
                cout << player_type << " " << *players[player_num] << ", your score is above 21. You lose. :(" << endl;
                // winning message
                cout << dealer_type << " " << *players[dealer_index] << ", you win! :)" << endl;
                // dealer score over 21
            } else if (player_score <= 21 && dealer_score > 21) {
                // losing message
                cout << dealer_type << " " << *players[dealer_index] << ", your score is above 21. You lose. :(" << endl;
                // winning message
                cout << player_type << " " << *players[player_num] << ", you win! :)" << endl;
            }
        }

        // Case 2: at least one score equal to 21
        if (player_score == 21 || dealer_score == 21) {
            // both player and dealer scores are equal to 21
            if (player_score == 21 && dealer_score == 21) {
                // winning message
                cout << player_type << " " << *players[player_num] << " and " << dealer_type << " " << *players[dealer_index] << ", your scores are equal to 21. You both win! :)" << endl;
                // dealer score equal to 21
            } else if (player_score != 21 && dealer_score == 21) {
                // winning
                cout << dealer_type << " " << *players[dealer_index] << ", your score is equal to 21. You win! :)" << endl;
                // losing
                cout << player_type << " " << *players[player_num] << ", you lose :(" << endl;
            
            } else if (player_score == 21 && dealer_score != 21) {
                // winning message
                cout << player_type << " " << *players[player_num] << ", your score is equal to 21. You win! :)" << endl;
                // losing message
                cout << dealer_type << " " << *players[dealer_index] << ", you lose :(" << endl;
            }
        }
            
        // Case 3: both scores below 21
        if (player_score < 21 && dealer_score < 21) {
            // if player's score is equal to dealer's score (doesn't compare dealer to itself)
            if (player_score == dealer_score) {
                // winning message
                cout << player_type << " " << *players[player_num] << " and " << dealer_type << " " << *players[dealer_index] << ", you have tied!" << endl;
                
            // player's score is greater than dealer's score
            } else if (player_score > dealer_score) {
                // winning message
                cout << player_type << " " << *players[player_num] << ", your score is above the dealer's score. You win!" << endl;
                // losing message
                cout << dealer_type << " " << *players[dealer_index] << ", your score is below the player's score. You lose :(" << endl;
            
                // player's score is less than dealer's score
            } else if (player_score < dealer_score) {
                // winning message
                cout << dealer_type << " " << *players[dealer_index] << ", your score is above the player's score. You win!" << endl;
                // losing message
                cout << player_type << " " << *players[player_num] << ", your score is below the dealer's score. You lose :(" << endl;
            }
        }
    }
    
    // EFFECTS: starts scoring process for every player
    void check_winners() {
        cout << endl;
        cout << "*** SCORING ***" << endl;
        for (int i = 0; i < num_players - 1; ++i) {
                compare_player_to_dealer(i);
        }
    }
    
    // EFFECTS: deletes player pointers
    void delete_player_pointers() {
        for (int i = 0; i < (int)(players.size()); ++i) {
          delete players[i];
        }
    }

    // EFFECTS: prints all players' hands
    void print_every_hand() const {
        cout << endl;
        for (int i = 0; i < num_players; ++i) {
            cout << *players[i] << "'s hand: " << endl;
            players[i]->print_hand();
        }
    }
    
    // MODIFIES: cards in players' hands
    // EFFECTS: deals twice to each player at the start of the game, shuffling in between
    void deal_twice() {
        for (int i = 0; i < num_players; i++) {
            int dealtwice = 0;
            while (dealtwice != 2) {
                pack.shuffle_pack();
                
                players[i]->hit(pack.deal());
                pack.remove_card();
                dealtwice++;
            }
        }
    }

    // EFFECTS: starts game by dealing cards, taking turns, and checking winners
    void play_game(int argc, char *argv[]) {
        deal_twice();
        print_every_hand();
        for (int player_num = 0; player_num < num_players; player_num++) {
            pass_or_hit(player_num);
        }
        check_winners();
        delete_player_pointers();
    }
};

// EFFECTS: prints correct way to input arguments if error occurs
static int error_message() {
    cout << "USAGE: Blackjack.exe NAME1 Player NAME2 Dealer" << endl;
    return 1;
}
    
// main function
// EFFECTS: creates Game objects and starts game. returns error messages if command line arguments are inputted incorrectly
int main(int argc, char* argv[]) {
        // error if there aren't 5 arguments
        if (argc != 5) {
            return error_message();
        }
    
    // if types do not match Player or Dealer
    for (int j = 2; j < argc; j += 2) {
        if ((!strcmp(argv[j], "Player")) && (!strcmp(argv[j], "Dealer"))) {
            return error_message();
        }
    }
    
    // if last type (index 3) is not 'Dealer'
    if (!strcmp(argv[3], "Dealer")) {
        return error_message();
    }
    
    // constructs and plays Game
    Game game(argc,argv);
    game.play_game(argc, argv);
    return 0;
}
