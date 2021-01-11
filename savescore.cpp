#include <iostream>
#include <fstream>
using namespace std ;

void savescore(int score) // In order to save the score in file for future needs
{
    ofstream fout ;
    fout.open("scores.txt",ios::app); // Opens the file "Scores"
    fout << score << endl; // Saves the score
    fout.close() ; // Closes the file
    return ;
}
