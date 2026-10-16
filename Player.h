#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

// Player Class
// Encaosulation: the player's picks (m_playerNumbers) are private
// the program can only read or change them through the public functions
// Abstraction: callers just say inputPlayerNumbers(); they do not need to know
// how the prompting and validation work

class Player {
private:
    std::vector<int> m_playerNumbers;   // hidden data (encapsulated)

public:
    void inputPlayerNumbers();                  // prompt for and validate 10 picks
    std::vector<int> getPlayerNumbers() const;  // controlled read access
    void printPlayerNumbers();                  // print picks in sorted order
    void clearPlayerNumbers();                  // reset for next round
};

#endif
