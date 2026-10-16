#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cctype>

Game::Game() {
    // m_keno, m_player and m_matches start empty via their default constructors
}

// Finds the numbers in both lists, stores them in m_matches, and prints them.
void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {
    m_matches.clear();
    for (int p : playerPicks) {
        if (std::find(kenoNumbers.begin(), kenoNumbers.end(), p) != kenoNumbers.end()) {
            m_matches.push_back(p);
        }
    }
    std::sort(m_matches.begin(), m_matches.end());
    std::cout << "You matched: ";
    for (int m : m_matches) {
        std::cout << m << " ";
    }
    std::cout << std::endl;
}

void Game::displayResults() {
    std::cout << "\n----------------------------------Results----------------------------------\n";
    std::cout << "Keno Numbers: ";
    m_keno.printKenoNumbers();
    std::cout << "Player Picks: ";
    m_player.printPlayerNumbers();
    printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());

    if (m_matches.size() > 0) {
        std::cout << "Matching " << m_matches.size() << " of 20 numbers wins ";
        switch (m_matches.size()) {
            case 10: std::cout << "$25,000"; break;
            case 9:  std::cout << "$2,500";  break;
            case 8:  std::cout << "$250";    break;
            case 7:  std::cout << "$50";     break;
            case 6:  std::cout << "$10";     break;
            case 5:  std::cout << "$5";      break;
            default: std::cout << "$0. Sorry, better luck next time.";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Sorry, you didn't have any matches." << std::endl;
    }
}

void Game::playGame() {
    char again = 'y';
    do {
        std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";

        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();
        displayResults();

        std::cout << "\nPlay another round? (y/n): ";
        std::cin >> again;

        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();
    } while (std::tolower(static_cast<unsigned char>(again)) == 'y');
    std::cout << "\nTHANKS FOR PLAYING!!\n";
}
