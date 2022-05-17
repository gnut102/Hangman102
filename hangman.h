#ifndef GUARD_util
#define GUARD_util

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cctype>


using namespace std;

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
int score(int & scores, const char ch, const string& word);
vector <int> highscore(const string & scorelist);
void showHighscore(const vector <int> & v);
void saveyourscore(vector <int> &v, int &scores, 
                    const string& word, const string& secretWord,
                    const int incorrectGuess);
int chossetype();
char gethelp(const int& incorrectGuess, const string& secretWord, const string& word);
#endif