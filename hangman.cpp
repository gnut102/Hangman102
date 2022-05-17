
#include <iostream>
#include "hangman.h"
#include <cctype>
#include <windows.h>
#include <algorithm>

using namespace std;
using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;
const int MAX_MISTAKES = 8;

//Function: guilde
void guilde()
{
    cout << "Welcome to Hangman!" << endl;
    Sleep(1000);
    cout << "You have 7 chances to guess the word." << endl;
    Sleep(1000);
    cout << "You can guess a letter or a word." << endl;
    Sleep(1000);
    cout << "If you guess a letter, you will get 1 point." << endl;
    Sleep(1000);
    cout << "If you guess a letter wrong, you will lose 1 point." << endl;
    Sleep(1000);

    cout << endl << endl;


}

// Function: select mode
string selectmode(){
    char mode;
    cout << "Select mode \n" ;
    cout << "1. Easy \n";
    cout << "2. Medium \n";
    cout << "3. Hard \n";
  
    cin >> mode;
    
    if(mode == '1'){
        return "data/easy.txt";
    }
    if(mode == '2'){
       return "data/medium.txt";
    }
    if(mode == '3'){
        return "data/hard.txt";
    }
    }


// Function 1: Generate a random integer number between min and max.
int generateRandomNumber(const int min, const int max)
{
    //srand((int)time(0)); // It is a bug if putting this line here.
    return rand() % (max - min + 1) + min;
}

vector<string> readWordListFromFile(const string& filePath)
{
    // Your code here
    vector<string> v;
    ifstream f_in(filePath);
    string word;
    while(f_in >> word)
    {
        v.push_back(word);
    }
    return v;
}


// Function 2: Check if a character is in a string or not.
bool isCharInWord(const char ch, const string& word)
{
    // Your code here
    int n = word.size();
    for(int i=0;i<n;i++)
    {
        if(word[i]==ch) return true;
    }
    return false;
}

// Function 3: Return a lowercase word in a certain position of a list.
string chooseWordFromList(const vector<string>& wordList, int index)
{
    // Your code here
    string word = wordList[index];
    int n = word.length();
    for(int i=0;i<n;i++)
    {
        word[i]= tolower(word[i]);
    }
    return word;
}

// return user's input
char getInputCharacter() {
    // your code here
    char input;
    cin >> input;
    return input;
}

// Function 4: Update the secret word if the character ch is in the answer word.
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // Your code here
    int n = word.size();
    for(int i=0;i<n;i++)
    {
        if(word[i]==ch) secretWord[i]=ch;
    }
}

// Function 5 + 6 +7: processData
// If ch in word:
//     update secretWord
//     update correctChars
// Else:
//     update incorrectGuess
//     update incorrectChars

// Function 5: this function is used to update correctChars and incorrectChars
void updateEnteredChars(const char ch, string& chars){
    // Your code here
    chars = chars + " " + ch;
}

// Function 6: Update incorrectGuess
void updateIncorrectGuess(int& incorrectGuess){
    // Your code here
    incorrectGuess++;
}

// Function 7: processData
void processData(const char ch, const string& word,
                string& secretWord,
                string& correctChars,
                int& incorrectGuess, string& incorrectChars,
                int &scores)
{   
    // Your code here
    if(isCharInWord(ch,word))
    {
        updateSecretWord(secretWord,ch,word);
        updateEnteredChars(ch,correctChars);
    }else{
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch,incorrectChars);
    }
    scores = score(scores, ch, word);
}

// Function 8: Based on secretWord's length, generate hidden characters in form of "---"
string generateHiddenCharacters(string secretWord){
    // Your code here
    int n = secretWord.size();
    for(int i=0;i<n;i++)
    {
        secretWord[i]='_';
    }
    return secretWord;
}

//Function 9: Print score
int score(int & scores, const char ch, const string & word){
    if(isCharInWord(ch,word)){
        scores++;
    }
    else {
        scores--;
    }
    return scores;
}

// Funciotn 10: Top score
vector <int> highscore(const string& scorelist){
    vector <int> v;
    ifstream f_in(scorelist);
    int score;
    while(f_in >> score)
    {   
        v.push_back(score);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
    
}

void showHighscore(const vector <int> & v){
    cout << "Highscore: " << endl;
    for(int i=0;i<5;i++){
        cout << i+1 << ": " << v[i] << endl;
    }
    cout << endl;
}

//Function 11: save your score
void saveyourscore(vector <int> &v, int &scores, 
                    const string& word, const string& secretWord,
                    const int incorrectGuess){
      ofstream fileout ("data/score.txt");

    if (secretWord == word) {

        for(int i=0;i<v.size();i++){
            fileout << v[i] << endl;
        }
        fileout << scores << endl;

    } else if (incorrectGuess == MAX_MISTAKES-1) {

        for(int i=0;i<v.size();i++){
            fileout << v[i] << endl;
        }
        fileout << scores << endl;
    }

    fileout.close();

}

// Funcion 12: select game type
int chossetype(){
    int typemode;
    cout << "Select game type \n" ;
    cout << "1. You guess a word\n";
    cout << "2. You think a word \n";
    cout << "3. Exit \n";
    cin >> typemode;
    return typemode;
}

char gethelp(const int& incorrectGuess, const string& secretWord, const string& word){
    int i;
    int n = word.size();
    char helpletter=' ';
    for(int i=0;i<n;i++){
        if(secretWord[i]!=word[i]){
            helpletter = word[i];
            break;
        }
    }
    return helpletter;
}
