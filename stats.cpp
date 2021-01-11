#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std ;

//Relevant functions to be used in the program
void header();
void colours(string a);
void clearscreen();

void stats(string curr_player) // In order to view previous scores ! takes in name of current player as argument
{
    clearscreen();
    header();
    colours("F6");
    cout << endl << "\tPLAYER NAME\t\tSCORE" << endl ;

    ifstream fin ;
    fin.open("players.txt",ios::app); // Opens the file "Players"
    string line ;
    int lineno ;
    for (lineno = 1; getline (fin,line) ; lineno++) // To get the number of lines
        if (line == curr_player)
            break ;
    fin.close(); // Closes the file

    for(int i=1 ; i<=lineno ; i++)
    {
        ifstream fin ;
        fin.open("players.txt",ios::app); // Opens the file "Players"
        string player ;
        for (int j = 1; getline (fin,player) && j <= lineno ; j++)
            if (j == i)
            {
                cout <<"\t" << player ; // Displays the name of each of the player
                break ;
            }
        fin.close(); // Closes the file

        fin.open("scores.txt",ios::app); // Opens the file "Scores"
        int score ;
        for (int j = 1; fin>>score && j <= lineno ; j++)
            if (j == i)
            {
                int len = player.length() ;
                if(len<8)
                {
                    cout << "\t\t\t" << score << endl ; // Displays the score of each of the player
                }
                else
                {
                    cout << "\t\t" << score << endl ; // Displays the score of each of the player
                }

                break ;
            }
        fin.close();
    }
    cout << "\n\n\nEnter any key to Return : " ;
    getch(); // Inputs any key to return the function
    return ;
}
