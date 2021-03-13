# Blackjack
### Basic rules:
Each participant (including the dealer) tries to get as close to 21 as possible without exceeding 21. \
Cards 2-10 are worth their number value. Face cards are worth 10 points. Aces can be worth either 1 or 11 points. \
To win, your score must either be 1. equal to 21 or 2. less than 21 but greater than the score of the dealer. 
# Running Program
Navigate to the folder where the Blackjack files are stored. In Terminal, use the below function to compile the files:\

**g++ Card.cpp Pack.cpp Human.cpp Game.cpp -o Blackjackgame -std=c++11** \
*Note: 'Blackjackgame' can be replaced with your preferred title.*

Next, run the following line after filling in your preferred names:\
./Blackjackgame NAME1 Player NAME2 Dealer 

# TO DO 
- Implement unique way to count and print Dealer's cards. Currently, Dealer and Player use the same implementations of functions in the Human interface. The Dealer, however, should only uncover the first card in their hand until their turn, with special cases to uncover the 'hidden' second card if the first card is a ten card or ace.

- Implement way for player to choose whether ace is worth 1 or 11. Currently, aces count as 11 when the current score is less than or equal to 10 and count as 1 when the score is greater than 10. 

- Add compatibility for more than 1 player.

- Clean up end messages declaring the winners and losers of the game.

- Add betting system.
