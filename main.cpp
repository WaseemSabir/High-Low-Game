#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
using namespace std;

string curr_player; //Global Variable as it is needed in multiple functions and it is same for a single game!

//all functions used in this program
void colours(string a); //Changes the Color of Background and Text!
void clearscreen(); //Clears the Screen
void header(); //Header of Program
bool quit(); //For quiting the program
void about(); //Info About the Game
char  mainscreen(); //MainScreen of the Program
void footer(); //Used in Quit as GoodBye Message
void cinrecover(); //To recover input
void name(string& curr_player); //For saving Player's name for future references
void stats(string curr_player) ; //Previous stats of Game
void game(string& curr_player) ; //Game
int classic() ; // Classic Mode of Game
int beattheclock() ; // Beat the Clock Mode of Game
void credits() ; // Developer Credits
void comments(int score) ; // Comments on Score
void scorefun(int score); //To show score in Game
void savescore(int score); //To save scores for future references

int main()
{
    char inp;
    bool q=true;
    colours("0B");
    int initial = clock() ; // Clock reference
    int i = 1;
    bool musicon= true ; // boolean variable for enabling sound effect
    do
    {
        if(musicon)
        {
            PlaySound(TEXT("pio.wav"),NULL,SND_ASYNC);
        }
        int fin = clock() ;
        if((fin-initial)/1000 >= 180*i) // Our music is 3 minutes long so this enables the music to restart after every 3 minutes
        {
            PlaySound(TEXT("pio.wav"),NULL,SND_ASYNC);
            i++;
        }
        clearscreen();
        header();
        inp = mainscreen();
        if(inp=='1')
        {
            game(curr_player);
            musicon = true;
        }
        else if(inp=='2')
        {
            stats(curr_player);
            musicon = false;
        }
        else if(inp=='3')
        {
            about();
            musicon = false;
        }
        else if(inp=='4')
        {
            credits();
            musicon = false;
        }
        else if(inp=='5')
        {
            q = quit();
            musicon = false;
        }
        else
            musicon = false;
        colours("0E") ;
    }
    while(q);
    footer();
    return 0;
}
