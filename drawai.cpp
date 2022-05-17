#include <string>
#include <cstdlib>

using namespace std;

string getDrawingai(int incorrectGuess)
{
    static const string figure[] = {
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

    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    return figure[incorrectGuess % NUMBER_OF_FIGURES];
}

string getNextHangmanai()
{
    static string figure[] =  {
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
    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

string getNextStandingmanai()
{
    static string figure[] = {
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
    i = (i + 1) % 8;

    return  figure[i];
}

void clearScreen()
{
#ifdef __WIN32__
    system("cls");
#else
    for (int i = 0; i < 30; i++) cout << endl;
#endif
}
