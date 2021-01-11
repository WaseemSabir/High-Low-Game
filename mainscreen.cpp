#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

char mainscreen() // Main Screen of the game
{
    cout << endl << endl ;
    cout << "\t\t\t1. >Start The Game" << endl ;
    cout << "\t\t\t2. >Previous Scores" << endl ;
    cout << "\t\t\t3. >About the Game" << endl ;
    cout << "\t\t\t4. >Credits" << endl ;
    cout << "\t\t\t5. >Quit          " << endl ;

    for(int j=0; j<6; j++) // Generates 6 End lines
        cout << endl ;
    cout << "Enter Relevant Key(1-5) : " ;
    return getch(); // Returned the entered character
}
