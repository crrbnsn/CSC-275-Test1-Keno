#ifndef KENONUMBERS_H
#define KENONUMBERS_H

#include <vector>

// KenoNumbers class
// Encapsulation: the 20 winning numbers (m_numbers) are private, so nothing
// outside tjat class can alter them by accident and access is through getKenoNumbers()
// Abstarction: callers just call generateNumbers(), the random engine, seed, and
// duplicate-checking details are hidden inside the class

class KenoNumbers {
private:
    std::vector<int> m_numbers;         // hidden data (encapsulated)

public:
    void generateNumbers();                     // pick 20 unique numbers in 1-80
    std::vector<int> getKenoNumbers() const;    // controlled read access
    void printKenoNumbers();                    // print numbers in sorted order
    void clearKenoNumbers();                    // reset for next round
};

#endif
