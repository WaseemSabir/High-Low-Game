#include <iostream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

void comments(int score) // In order to comment on the level of Player ! takes in final score of a player
{
    cout << endl << endl ;
    if(score < 5)
     {
         PlaySound(TEXT("vo2.wav"),NULL,SND_ASYNC);
         cout << " ----------------------------------- " << endl ;
         cout << "| Did We make it this hard For you? |" << endl ;
         cout << " ----------------------------------- " << endl ;
     }
    else if(score < 10)
    {
        PlaySound(TEXT("vo3.wav"),NULL,SND_ASYNC);
        cout << " ------------------------------ " << endl ;
        cout << "| You are average! Well played |" << endl ;
        cout << " ------------------------------ " << endl ;

    }
    else
    {
        PlaySound(TEXT("vo1.wav"),NULL,SND_ASYNC);
        cout << " ---------------------------------- " << endl ;
        cout << "| Well done! You fought like a man |" << endl ;
        cout << " ---------------------------------- " << endl ;
    }
    return ;
}
