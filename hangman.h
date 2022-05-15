#ifndef GUARD_util
#define GUARD_util

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include<cctype>


using std::string;
using std::vector;

void guilde();
string selectmode();

void updateEnteredChars(const char ch, string& correctChars);
void updateIncorrectGuess(int& incorrectGuess);

string chooseWordFromList(const vector<string>& wordList, int index);
string generateHiddenCharacters(string word);
char getInputCharacter();
void updateSecretWord(string& secretWord, const char ch, const string& word);
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars,
                int &scores);

int generateRandomNumber(const int min, const int max);
bool isCharInWord(const char ch, const string& word);
vector<string> readWordListFromFile(const string& filePath);
int score(int & scores, const char ch, const string & word);
#endif