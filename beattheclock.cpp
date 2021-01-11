#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
using namespace std;

//Relevant functions to be used in the program
void colours(string a);
void header();
void scorefun(int score) ;
void clearscreen();

int beattheclock() // This is the beat the clock mode of the function
{
    colours("E1") ;
    clearscreen();
    header() ;
    srand( time(0) ) ; // For generating random number
    int score = 0; // Initial Score
    bool right = true;
    while(right)
    {
        clearscreen();
        header() ;
        scorefun(score) ;
        cout << endl << endl << endl ;
        int rand1 = (rand() % 101) + 1 ; // Generate First random number (line no of first term)
        int rand2;
        do
        {
            rand2 = (rand() % 101) + 1 ; // Generate Second random number (line no of second term)
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
        fin.close(); // Closes the file
        fin.open("terms.txt",ios::app); // Opening file "Terms"
        string term2 ;
        for (int lineno = 1; getline(fin,term2) && lineno < 101; lineno++)
        {
            if (lineno == rand2)
                break;
        }
        fin.close(); // Closes the file

        fin.open("searches.txt",ios::app); // Opening file "Searches"
        int searches1;
        for (int lineno = 1; fin>>searches1 && lineno < 101; lineno++)
        {
            if (lineno == rand1) // Gets the line and checks whether the Search line no is equal to generated random number and breaks the loop if it is
                break;
        }
        fin.close(); // Closes the file
        fin.open("searches.txt",ios::app); // Opening file "Searches"
        int searches2;
        for (int lineno = 1; fin >> searches2 && lineno < 101; lineno++)
        {
            if (lineno == rand2)
                break;
        }
        fin.close(); // Closes the file

        cout << "If " << "\"" << term1 << "\"" << " Has " << "\"" << searches1 << "\"" << " number of searches, " << endl;
        cout << "THEN" << endl;
        cout << "\"" << term2 << "\"" << " Will have" << endl << "\t1: Greater " << endl << "\t2: Lower" << endl << "Number of searches: " ;
        cout << endl << endl << "You have 10 seconds to answer!" << endl << "Clock is ticking ....." << endl ;

        char ans; // variable for saving answer
        while(true)
        {
            PlaySound(TEXT("10secm.wav"),NULL,SND_ASYNC); // Sound of the timer
            const int intial = clock() ; // Initial time
            int seconds = 10;
            ans = getch();
            const int fin = clock() ; // Final time
            cout << "Time Taken to answer: " << "\"" << (fin-intial)/1000 << "\"" << " seconds " << endl ; // divided by 1000 as time is 4 digits ( MiliSeconds)
            if( (fin-intial)/1000 >= seconds ) // If time taken to answer is greater than time allowed
            {
                cout << "Time up!" << endl ;
                cout << "Enter any key to move on : " ;
                getch();
                return score;
            }
            else // If answered in given time
            {
                PlaySound(TEXT("Silent.wav"),NULL,SND_ASYNC); // Silent sound
                if(ans=='1') // if ans = 1(Greater)
                {
                    if(searches2 >= searches1)
                    {
                        cout << "\nYou are CORRECT :)" << endl ;
                        cout << "\"" << term2 << "\"" << " has " << "\"" << searches2 << "\"" << " number of searches " << endl << endl ;
                        score++;
                    }
                    else
                    {
                        PlaySound(TEXT("tickle.wav"),NULL,SND_ASYNC); // sound if answer is wrong
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
                        cout << "\"" << term2 << "\"" << "has " << "\"" << searches2 << "\"" << " number of searches " << endl << endl ;
                        score++;
                    }
                    else
                    {
                        PlaySound(TEXT("tickle.wav"),NULL,SND_ASYNC); // sound if answer is wrong
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
        }
        cout << "\nEnter any key to return : " ;
        getch();
    }
    return score;
}
