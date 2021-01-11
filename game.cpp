#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

//Relevant functions to be used in the program
void name(string& curr_player);
void clearscreen();
void colours(string a);
void header();
int classic();
int beattheclock();
void scorefun(int score);
void comments(int score);
void savescore(int score);

void game(string& curr_player) // To choose the type of play
{
    clearscreen();
    header();
    name(curr_player) ;
    clearscreen();
    header();
    colours("F0");
    cout << endl ;
    cout << "\t\tWelcome " << curr_player << " , Choose Your Type of Play" << endl ;
    cout << endl << endl ;
    cout << "\t\t1. Classic" << endl ;
    cout << "\t\t2. Beat The Clock." ;
    for(int i=0; i<5; i++) // Generate 5 end lines
        cout << endl ;
    int playtype ; // Variable to choose play type
    int score ; // Variable to save score
    bool choice ; // Boolean Variable for controlling input
    do
    {
        choice = false ;
        cout << "\nPLease Enter Relevant Number : " ;
        playtype = getch();
        if(playtype=='1')
        {
            score = classic();
        }
        else if(playtype=='2')
        {
            score = beattheclock();
        }
        else
        {
            choice = true;
        }
    }
    while(choice) ;

    savescore(score);
    clearscreen();
    header();
    cout << endl << endl << "GameOver" << endl ;
    scorefun(score) ;
    cout << endl ;
    comments(score) ;
    cout << endl << endl << "Press any key to Go back : " ;
    getch();
    return ;
}
