#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
using namespace std;

//Relevant functions to be used in the program
void colours(string a);
void clearscreen();
void header();
void scorefun(int score) ;

int classic() // This is the classic game function
{
    colours("C0") ;
    clearscreen();
    header() ;
    srand(time(0)) ; // For generating random number
    int score=0; // Initial Score
    bool right = true ;
    PlaySound(TEXT("pio.wav"),NULL,SND_ASYNC);
    while(right)
    {
        clearscreen();
        header() ;
        scorefun(score);
        cout << endl << endl << endl ;
        int rand1 = rand() % 101 + 1 ; // Generate first random number (line number of first term)
        int rand2;
        do
        {
            rand2 = rand() % 101 + 1 ; // Generate Second random number (line no of second term)
        }
        while(rand1==rand2); // same terms should not be picked

        ifstream fin;
        fin.open("terms.txt",ios::app); // Opening file "Terms"
        string term1;
        for (int lineno = 1; getline(fin,term1) && lineno < 101; lineno++)
        {
            if (lineno == rand1) // Gets the line and checks whether the term line no is equal to generated random number and breaks the loop if it is
                break;
        }
        fin.close();
        fin.open("terms.txt",ios::app);
        string term2 ;
        for (int lineno = 1; getline(fin,term2) && lineno < 101; lineno++)
        {
            if (lineno == rand2) // Gets the line and checks whether the term line no is equal to generated random number and breaks the loop if it is
                break;
        }
        fin.close(); // Closes the file

        fin.open("searches.txt",ios::app); // Opens the file "Terms"
        int searches1;
        for (int lineno = 1; fin>>searches1 && lineno < 101; lineno++)
        {
            if (lineno == rand1) // Gets the line and checks whether the Search line no is equal to generated random number and breaks the loop if it is
                break;
        }
        fin.close();
        fin.open("searches.txt",ios::app);
        int searches2;
        for (int lineno = 1; fin>>searches2 && lineno < 101; lineno++)
        {
            if (lineno == rand2) // Gets the line and checks whether the term line no is equal to generated random number and breaks the loop if it is
                break;
        }
        fin.close(); // Closes the file

        cout << "If " << "\"" << term1 << "\"" << " Has " << "\"" << searches1 << "\"" << " number of searches, " << endl;
        cout << "THEN" << endl;
        cout << "\"" << term2 << "\"" << " Will have" << endl << "\t1: Greater " << endl << "\t2: Lower" << endl << "Number of searches: " ;
        char ans; // Variable for saving answer
        while(true)
        {
            ans = getch();
            if(ans=='1') // if ans = 1(Higher)
            {
                if(searches2 >= searches1)
                {
                    cout << "\nYou are CORRECT :)" << endl ;
                    cout << "\"" << term2 << " has " << "\"" << searches2 << "\"" << " number of searches, " << endl << endl ;
                    score++;
                }
                else
                {
                    PlaySound(TEXT("tickle.wav"),NULL,SND_ASYNC);
                    cout << "\nYou are WRONG :(" << endl ;
                    cout << "\"" << term2 << "\"" << " has " << "\"" << searches2 << "\"" << " number of searches " << endl << endl ;
                    right = false ;
                }
                break;
            }
            else if(ans=='2') // if ans = 2(Lower)
            {
                if(searches2 <= searches1)
                {
                    cout << "\nYou are CORRECT :)" << endl ;
                    cout << "\"" << term2 << "\"" << " has " << "\"" << searches2 << "\"" << " number of searches " << endl << endl ;
                    score++;
                }
                else
                {
                    PlaySound(TEXT("tickle.wav"),NULL,SND_ASYNC);
                    cout << "\nYou are WRONG :(" << endl ;
                    cout << "\"" << term2 << "\"" << " has " << "\"" << searches2 << "\"" << " number of searches " << endl << endl ;
                    right = false ;
                }
                break;
            }
            else // any input other than greater(1) or lower(2)
            {
                cout << "\nPlease Enter 1 or 2 : " ;
            }
        }
        cout << "\nEnter any key to return : " ;
        getch();
    }
    return score;
}
