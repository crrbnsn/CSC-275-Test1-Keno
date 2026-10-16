#include "Player.h"
#include <iostream>
#include <algorithm>
#include <limits>

void Player::inputPlayerNumbers() {
    bool error;
    int temp = 0;

    for (int i = 0; i < 10; i++) {
        error = false;
        std::cout << "Enter your pick #" << i + 1 << ": ";
        std::cin >> temp;
        if (std::cin.fail()) {
            error = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data input! Try again. ";
        }
        else if (temp < 1 || temp > 80) {
            error = true;
            std::cout << temp << " is out of range! Try again. ";
        }
        else if (std::find(m_playerNumbers.begin(), m_playerNumbers.end(), temp) != m_playerNumbers.end()) {
            error = true;
            std::cout << temp << " was already picked! Try again. ";
        }
        if (error)
            i--;
        else
            m_playerNumbers.push_back(temp);
    }
}

std::vector<int> Player::getPlayerNumbers() const {
    return m_playerNumbers;
}

void Player::printPlayerNumbers() {
    std::sort(m_playerNumbers.begin(), m_playerNumbers.end());
    for (int n : m_playerNumbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void Player::clearPlayerNumbers() {
    m_playerNumbers.clear();
}
