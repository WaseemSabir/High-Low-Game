#include <iostream>
#include <conio.h>
using namespace std;

//Relevant functions to be used in the program
void clearscreen();
void header();

void footer()
{
    clearscreen();
    header();
    for(int i=0; i<6; i++)
        cout << endl ;
    cout << "\t\xB1\xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1          \xB1\xB1\xB1\xB1  \xB1   \xB1 \xB1\xB1\xB1\xB1\xB1 \xB1" << endl ;
    cout << "\t\xB1     \xB1  \xB1 \xB1  \xB1 \xB1   \xB1         \xB1   \xB1  \xB1 \xB1  \xB1     \xB1" << endl ;
    cout << "\t\xB1     \xB1  \xB1 \xB1  \xB1 \xB1    \xB1  \xB1\xB1\xB1   \xB1\xB1\xB1\xB1    \xB1   \xB1\xB1\xB1   \xB1" << endl ;
    cout << "\t\xB1   \xB1 \xB1  \xB1 \xB1  \xB1 \xB1   \xB1         \xB1   \xB1   \xB1   \xB1      " << endl ;
    cout << "\t\xB1\xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1 \xB1\xB1\xB1\xB1          \xB1\xB1\xB1\xB1    \xB1   \xB1\xB1\xB1\xB1\xB1 \xB1" << endl ;
    cout << endl << endl ;
    cout << "\t\t\tHOPE TO SEE YOU BACK!" ;
    for(int i=0; i<6; i++)
        cout << endl ;
    cout << "\nEnter any Key to return: " << endl;
    getch();
    return ;
}



