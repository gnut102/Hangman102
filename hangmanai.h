#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <windows.h>
#include <string>
#include "util.h"
#include "guesser.h"
#include "drawai.h"

using namespace std;

int getUserWordLength();
void initialize(int& wordLength, string& secretWord,
                int& incorrectGuess, set<char>& previousGuesses,
                bool& stop);
string getUserAnswer(char guess);
bool isGoodMask(char guess, const string& mask, const string& secretWord);
void updateSecretWordai(const string& mask, string& secretWord);
void update(char guess, const string& mask,
            int& incorrectGuess, set<char>& previousGuesses,
            string& secretWord, bool& stop);
void render(int incorrectGuess, const set<char>& previousGuesses,
            const string& secretWord);
void playAnimationai(bool isLosing, const string& word);
void guidleai();
