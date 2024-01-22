//Hangman Game
/* Improvement */
/*-Hangman for sentences and not just letters*/
/*- Give multiple sections*/
#include <iostream>
#include <string.h>
#include "hangmanfunc.h"
#include <cstdlib>
#include <conio.h>
void greet();
using namespace std;
int main()
{
    
    char sel='p';
    
    while(sel=='p')
    {
        system("clear");
        greet();
        sel=getch();
        if(sel=='p')
        {
        string aim=pickaword();
        string user(size(aim),'_');
        int misses=0;
        vector <char> incorrect{};
        char inp;

        while(1)
        {
            system("clear");
            displayman(misses);
            displaystatus(aim,user,misses,incorrect);

            cout<<"\n";
            cout<<"Enter your letter\t:";
            cin>>inp;

            misses+=check(aim,user,inp,incorrect);

            if(ifdone(user))
            {
                WON();
                sel=getch();
                break;
            }
            if(misses>6)
            {
                LOST(aim,user,misses,incorrect);
                sel=getch();
                break;
            }
        }
        }
    }
    return 0;
}