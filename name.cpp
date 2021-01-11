#include <iostream>
#include <fstream>

using namespace std ;

//Relevant functions to be used in the program
void colours(string a);

void name(string& curr_player) // To save the name of Current Player
{
    colours("F0");
    bool notunique_name = true ; // Bool in order to confirm that the user enters a Different name
    cout << endl << endl << endl ;
    cout << "\t\t\t\tPlease Enter Your First Name: " ;
    string line, player;
    while(notunique_name)
    {
        notunique_name = false ;
        cin >> line ;
        ifstream fin ;
        fin.open("players.txt",ios::app); // Opens the file "Players"
        for(int i=0; fin >> player && player != "" ; i++)
        {
            if( player == line ) // Gets the line and checks whether player name is equal to the previous players' name
            {
                colours("FC");
                notunique_name = true ;
                cout << "This user already Exists. Please choose a unique name: " ;
            }
        }
        fin.close(); // Closes the file
    }

    ofstream fout ;
    fout.open("players.txt",ios::app); // Opens the file "Players"
    curr_player = line ;
    fout << line << endl; // Saves the Current Player's name in the file
    fout.close() ; // Closes the file
    return ;
}
