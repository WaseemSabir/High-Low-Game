#include <iostream>
#include <conio.h>
using namespace std;

//Relevant Functions to be used in the program
void header();
void colours(string a);
void clearscreen();

void about() // This function contains the Info about the Games
{
    clearscreen();
    header();
    colours("F5");// Command for Changing the Background and Text Color
    cout << endl << endl ;
    // Stuff about the game
    cout<<"\n\tHow much do you know about the Internet? Can you figure out which one of these things";
    cout<<"\n\tgets the greater number of Google searches in this insanely addictive quiz game? You ";
    cout<<"\n\twill get +1 credit for each correct guess. Failure to do so will result the game over.";
    cout<<endl<<endl;
    cout<<"\tPress any key to return : ";
    getch(); // Inputs any key to return the function
    return;
}
