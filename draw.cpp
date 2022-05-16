#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "hangman.h"
#include <string.h>
#include <fstream>

using namespace std;
const int MAX_MISTAKES = 8;

string getDrawing(const int i) 
{
    static int LEN = 8;
    static string FIGURES[] = {
                "   -------------    \n" 
                "   |                \n" 
                "   |                \n" 
                "   |                \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |                \n" 
                "   |                \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |                \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |           |    \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |          /|    \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |          /|\\  \n" 
                "   |                \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |          /|\\  \n" 
                "   |          /     \n" 
                "   |     \n" 
                " -----   \n",
                "   -------------    \n" 
                "   |           |    \n" 
                "   |           O    \n" 
                "   |          /|\\  \n" 
                "   |          / \\  \n" 
                "   |     \n" 
                " -----   \n",
    };
    return FIGURES[i % LEN];
}

string getNextHangman() 
{
    static int LEN = 4;
    static string FIGURES[] = {
          "   ------------+    \n" 
          "   |          /     \n"     
          "   |         O      \n"      
          "   |        /|\\    \n" 
          "   |        / \\    \n" 
          "   |        \n" 
          " -----      \n" ,
          "   ------------+     \n" 
          "   |           |     \n"     
          "   |           O     \n"      
          "   |          /|\\   \n" 
          "   |          / \\   \n" 
          "   |        \n" 
          " -----      \n",  
          "   ------------+      \n" 
          "   |            \\    \n"     
          "   |            O     \n"      
          "   |           /|\\   \n" 
          "   |           / \\   \n" 
          "   |      \n" 
          " -----    \n",   
          "   ------------+     \n" 
          "   |           |     \n"     
          "   |           O     \n"      
          "   |          /|\\   \n" 
          "   |          / \\   \n" 
          "   |        \n" 
          " -----      \n",  
          };
    static int i = 0;
    i = (i + 1) % LEN;

    return FIGURES[i];
}

string getNextStandingman() 
{
    static int LEN = 8;
    static string FIGURES[] = {
          "     O     \n"    
          "    /|\\   \n" 
          "    | |    \n", 
          "     O     \n"    
          "    /|\\   \n" 
          "    / \\   \n", 
          "   __O__   \n"    
          "     |     \n" 
          "    / \\   \n", 
          "    \\O/   \n" 
          "     |     \n" 
          "    / \\   \n", 
          "   __O__   \n"     
          "     |     \n" 
          "    / \\   \n", 
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "    O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "      O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          };
    static int i = 0;
    i = (i + 1) % LEN;

    return FIGURES[i];
}

void printStats(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores)
{       
        cout << "Your score: "<< scores<<endl;
        cout << "Current word: " << secretWord;
        cout << endl << "Correct guesses: " << correctChars;
        cout << "    " << "Incorrect guesses: " << incorrectChars;

        if (secretWord == word) {
            cout << endl << "Well done :D   The word is: " << word << endl;
 
        } else if (incorrectGuess == MAX_MISTAKES-1) {
            cout << endl << "You lose :(   The word is: " << word << endl;

        } else {
            cout << endl << "Choose a character: ";
        }
}

void printScreen(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores)
{
    system("cls");
        
    cout << getDrawing(incorrectGuess);
    printStats(word, secretWord, correctChars, incorrectGuess, incorrectChars, scores); 

}

void playAnimation(const string& word, const string& secretWord,
                 const string& correctChars,
                 const int incorrectGuess, const string& incorrectChars,
                 const int scores)
{
    for (int i = 0; i < 21; ++i) {
       system("cls");
            
        if (secretWord == word) {
            cout << getNextStandingman();
        } else if (incorrectGuess == MAX_MISTAKES-1) {
            cout << getNextHangman();
        }
        printStats(word, secretWord, correctChars, incorrectGuess, incorrectChars, scores); 

        std::this_thread::sleep_for (std::chrono::milliseconds(1000/2));
    }
} 