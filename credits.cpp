#include <iostream>
#include <conio.h>
using namespace std  ;

//Relevant functions to be used in the program
void header();
void colours(string a);
void clearscreen();

void credits() // To show the names of the developers
{
    clearscreen();
    header();
    colours("F1") ;
    cout << endl ;
    cout << "\t\t\tCREDITS" << endl << endl ;
    cout << "\t\tThis Game is developed by" << endl << endl ;
    cout << "\t\t> Waseem Sabir\t22100139" << endl ;
    cout << "\t\t\t  &" << endl ;
    cout << "\t\t> Zain Ayaz\t22100176" << endl ;
    cout << endl << endl << endl ;
    cout << "Any key to return : " ;
    getch(); // Inputs any key to return the function
    return ;
}
