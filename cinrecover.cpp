#include <iostream>
using namespace std;

void cinrecover() // In order to recover the input
{
    if(cin.fail())
    {
        cin.clear();
        string dummy; // Dummy string
        getline(cin,dummy);
    }
}
