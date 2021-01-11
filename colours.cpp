#include <iostream>
#include <windows.h>
using namespace std;

void colours(string a) // n order to change the color of background and text
{
    //Functions argument is string of two words containing color code for background and words in format "BW"
    string b = "COLOR " + a; // string b is the combination of "COLOUR" and the string a
    system(b.c_str()) ; // c_str() in order to tell that the input is string
}
