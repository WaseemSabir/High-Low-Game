#include <iostream>
using namespace std;

void scorefun(int score) // In order to show the score in the closed box in the program
{
    cout << "\t\t ____________" << endl ;
    cout << "\t\t|            |"<< endl ;
    if(score < 10 )
    {
        cout << "\t\t| SCORE : "<< score << "  |"<< endl ;
    }
    else
    {
        cout << "\t\t| SCORE : "<< score << " |"<< endl ;
    }
    cout << "\t\t|____________|"<< endl ;
    return ;
}
