#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <windows.h>
#include "util.h"
#include "guesser.h"
#include "drawai.h"

#define MAX_GUESSES 7
using namespace std;

int getUserWordLength()
{
    int wordLength;
    cout << endl << "Enter your word length: ";
    cin >> wordLength;
    return wordLength;
}

void initialize(int& wordLength, string& secretWord,
                int& incorrectGuess, set<char>& previousGuesses,
                bool& stop)
{
    wordLength = getUserWordLength();
    secretWord = string(wordLength, '-');
    incorrectGuess = 0;
    previousGuesses = set<char>();
    stop = false;
}

string getUserAnswer(char guess)
{
    string answer;
    cout << endl << "I guess " << guess << ", please enter your mask: ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer;
}

bool isGoodMask(char guess, const string& mask, const string& secretWord)
{
    if (mask.length() != secretWord.length()) return false;
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-') {
            if (mask[i] != guess)
                return false;
            if (secretWord[i] != '-' && secretWord[i] != mask[i])
                return false;
        }
    return true;
}

void updateSecretWordai(const string& mask, string& secretWord)
{
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-')
            secretWord[i] = mask[i];
}

void update(char guess, const string& mask,
            int& incorrectGuess, set<char>& previousGuesses,
            string& secretWord, bool& stop)
{
    if (!isGoodMask(guess, mask, secretWord))
        throw invalid_argument("mistake entering answer");

    previousGuesses.insert(guess);
    if (isAllDash(mask)) {
        incorrectGuess ++;
        if (incorrectGuess == MAX_GUESSES) stop = true;
    } else {
        updateSecretWordai(mask, secretWord);
        if (isAllNotDash(secretWord)) stop = true;
    }
}

void render(int incorrectGuess, const set<char>& previousGuesses,
            const string& secretWord)
{
    clearScreen();
    cout << endl << "Incorrect guess = " << incorrectGuess
         << "   previous guesses = ";
    for (char c : previousGuesses)
        cout << c;
    cout << "   secretWord = " << secretWord << endl;
    cout << getDrawingai(incorrectGuess) << endl;
}

void playAnimationai(bool isLosing, const string& word)
{
    for(int i=0;i<21;i++){
        clearScreen();
        if (isLosing)
            cout << endl << "I lost :(. My best word is: " << word << endl;
        else
            cout << endl << "I win :D. The word is: " << word << endl;
        cout << (isLosing ? getNextHangmanai() : getNextStandingmanai());
        Sleep(500);
        
    }
}

void guidleai(){
    char a;
    cout << "Wellcome to Hangman!"<<endl;
    Sleep(1000);
    cout << "I am the computer, you are the player"<<endl;
    Sleep(1000);
    cout << "You will guess a word for me"<<endl;
    Sleep(1000);
    cout << "You will give me number of letters in the word"<<endl;
    Sleep(1000);
    cout << "I will guess a letter and you will give me a mask"<<endl;
    Sleep(1000);
    cout << "For example, if the word is 'apple' I will guess 'a' and you will give me 'a----'"<<endl;
    Sleep(1000);
    cout << "If I guess wrong, you will win"<<endl;
    Sleep(1000);
    cout << "If I guess right, you will lose"<<endl;
    Sleep(1000);
    cout << "_______________________________________________"<<endl;
    cout << "Press any key to start"<<endl;
    cin >> a;
    system("cls");
}