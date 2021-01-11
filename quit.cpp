#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

//Relevant functions to be used in the program
void header();
void colours(string a);
void clearscreen();

bool quit() // To quit the game
{
    clearscreen();
    header();
    colours("F4");
    cout << endl << endl ;
    cout << "\tAre you sure that you wanna quit the game(y/n) ? " << endl ;
    char a;
    while(true) // Loop to get the valid answer
    {
        a = getch();
        if     (a=='y' || a=='Y')
        {
            PlaySound(TEXT("vo4.wav"),NULL,SND_ASYNC);
            return false ;
        }
        else if(a=='n' || a=='N')
            return true;
        else
            cout << "\n\tPlease Enter the input(y/n) :" ;
    }
}
