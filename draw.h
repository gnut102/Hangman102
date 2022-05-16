#ifndef GUARD_draw
#define GUARD_draw
#include <iostream>
#include <string>

using namespace std;

const int MAX_MISTAKES = 8;

void printScreen(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores);
void playAnimation(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores);
void printStats(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores);

std::string getDrawing(const int i);
std::string getNextHangman();
std::string getNextStandingman();

#endif