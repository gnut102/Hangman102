#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include "hangman.h"
#include "draw.h"
using namespace std;

int playerguess(){
    
    guilde();
    srand((int)time(0));

    // danh sach diem cao
    vector <int> highscorelist;
    string filescore = "data/score.txt";
        try {
        highscorelist = highscore(filescore);
        
    } catch (domain_error) {
        cout << endl << "Error: in reading vocabulary file: " << "data/score.txt" << endl;
        return 1;
    }
    
    int choice;
    char back;
    string vocabularyFile;

    // chon xem diem hay chon man choi 
    do{

        cout <<" ___________________________________________"<<endl;
        cout << "1. High score" << endl;
        cout << "2. New game" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2)
        {
            cout << "Please enter 1 or 2" << endl;
            cin >> choice;
        }
            switch(choice)
            {
                case 1:
                    showHighscore(highscorelist);
                    cout << "Press P to play" << endl;
                    cin >> back;
                    system("cls");
                    vocabularyFile = selectmode();
                    break;
                case 2:
                    vocabularyFile = selectmode();
                    break;
            
        }
    }while(choice != 1 && choice != 2);

    
    

    // vector wordList la danh sach cac tu ngau nhien 
    vector<string> wordList;


    // nhap cac tu ngau nhien tu file 
    try {
        wordList = readWordListFromFile(vocabularyFile);
        
    } catch (domain_error) {
        cout << endl << "Error: in reading vocabulary file: " << vocabularyFile << endl;
        return 1;
    }


    // tao so ngau nhien 
    // index la gia tri random tu 0 den wordList.size - 1
    int index = generateRandomNumber(0, wordList.size()-1);
    

    // chon tu ngau nhien tu so ngau nhien da random o tren
    //word la tu ngau nhien co so thu tu index trong danh sach cac tu trong vector wordList
    string word = chooseWordFromList(wordList, index);
    // loi thi in ra loi khong tim duoc chu
    if (word.empty()) {
        cout << "Error: Coud not choose a random word." << endl;
        return 1;
    }

    // test o day:  cout<<index<<endl<< word; return 0;
    // cout<<index<<endl<< word<<endl;



    string secretWord = generateHiddenCharacters(word);

    // cout << secretWord;
    //return 0;

    int incorrectGuess = 0;
    string correctChars = "";
    string incorrectChars = "";
    int scores=0;
    printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars, scores); 
    
    do {
        char ch = getInputCharacter();
        processData(ch, word, secretWord, 
                    correctChars, incorrectGuess, incorrectChars,scores);
        printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars, scores); 
        if(incorrectGuess == 5 && scores < -3){
            cout <<"\n\nHave '"<< gethelp(incorrectGuess, secretWord, word) << "' in the word"<<endl;
        }   
        saveyourscore(highscorelist, scores, word, secretWord, incorrectGuess);
        
    } while (secretWord != word && incorrectGuess != MAX_MISTAKES-1);
       
    playAnimation(word, secretWord, correctChars, incorrectGuess, incorrectChars, scores);
    

    return 0;

    }
    
    
int computerguess(){
    
}


int main()
{
    char typemode = 0;
    char replay = 'y';
    do{
    do{
    typemode = chossetype();
    if(typemode != 1 && typemode != 2 && typemode != 3){
        cout << "Please enter 1, 2 or 3" << endl;
        typemode = chossetype();
    }
    }while(typemode != 1 && typemode != 2 && typemode != 3);
    switch(typemode){
        case 1:
            system("cls");
            playerguess();
            break;
        case 2:
            system("cls");
            computerguess();
            break;
        case 3: 
            return 0;
    }
    cout << "Play again?\n"<<"  [Y/N]?\n";
    cin>>replay;
    }while(replay == 'y');
}