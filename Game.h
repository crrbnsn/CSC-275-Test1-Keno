#ifndef GAME_H
#define GAME_H

#include <vector>
#include "KenoNumbers.h"
#include "Player.h"

// Game class
// Composition: a Game "has a" KenoNumbers and "has a" Player the filled diamonds in the UML file
// Encapsulation: all game state (m_keno, m_player, m_matches) is private
// Abstraction: main() only needs Game and playGame(), all the game rules are
// matching, and prize logic are hidden behind tge one public function

class Game {
private:
    KenoNumbers m_keno;
    Player m_player;
    std::vector<int> m_matches;

public:
    Game();
    void printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers);
    void displayResults();
    void playGame();
};

#endif
