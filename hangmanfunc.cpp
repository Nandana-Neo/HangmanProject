#include <iostream>
#include <vector>
#include <string>
#include "hangmanfunc.h"
#include <windows.h>
using namespace std;
void greet()
{
    system("cls");
    cout<<"\t\t===========================================\n";
    cout<<"\t\t================HANGMAN====================\n";
    cout<<"\t\tSave your friend before it's too late\n";
    cout<<"\t\tPress p to start playing...";
}


string pickaword()
{
    vector <string> K={"WEBSITE","GAMES","TECHNOLOGY","ROBOTICS","ALGORITHM","COMPUTER","INNOVATION","TELECOMMUNICATION","CYBERSECURITY","CRYPTOCURRENCY"};
    string s=K[rand()%K.size()];
    return s;
}
void stick()
{
    COORD pos;
    pos.X=0;
    pos.Y=1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    for(int i=0;i<10;i++)
    {
        cout<<"\t|";
        pos.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
}
void horistick()
{
    COORD pos;
    pos.X=8;
    pos.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"+-------------";
}
void noose()
{
    COORD pos;
    pos.X=20;
    pos.Y=1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"|";
}

void head()
{
    COORD pos;
    pos.X=20;
    pos.Y=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"O";
}
void body()
{
    COORD pos;
    pos.X=20;
    pos.Y=3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"|";
    pos.Y=4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"|";
}

void lhand()
{
    COORD pos;
    pos.X=19;
    pos.Y=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"\\";
}
void rhand()
{
    COORD pos;
    pos.X=21;
    pos.Y=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"/";
}
void lleg()
{
    COORD pos;
    pos.X=19;
    pos.Y=5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"/";
}
void rleg()
{
    COORD pos;
    pos.X=21;
    pos.Y=5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    cout<<"\\";
}


void displayman(int misses)
{
    switch(misses)
    {
        case 0:
            for(int i=0;i<10;i++)
                body();
                head();
                rhand();
                lhand();
                rleg();
                lleg();
                cout<<"\n";
                break;
        case 7:
            rleg();
            lleg();
        case 6:
            rhand();
            lhand();
        case 5:
            body();
        case 4:
            head();
        case 3:
            noose();
        case 2:
            horistick();
        case 1:
            stick();

    }
}


void displaystatus(string aim,string user,int misses,vector <char> incorrect)
{
    cout<<"\n";
    cout<<"======================STATUS=============================\n";
    cout<<"No: of misses\t\t:"<<misses<<"\n";
    cout<<"Characters used up\t:";
    for(char elem:incorrect)
        cout<<elem<<" ";
    cout<<"\nWORD\t\t\t:"<<user<<"\n";
}

int check(string aim,string &user,char e,vector<char> &incorrect)
{
    int ch=1;
    e=(e>='a')?e-'a'+'A':e;
    for(int i=0;i<aim.size();i++)
    {
        if(aim[i]==e)
        {
            user[i]=e;
            ch=0;
        }
    }
    if(ch==1)
        incorrect.emplace_back(e);
    return ch;
}

bool ifdone(string word)
{
    for(char elem: word)
    {
        if(elem=='_')
            return false;
    }
    return true;
}

void WON()
{
    system("clear");
    displayman(0);
    cout<<"=====================CONGRATULATIONS!!=======================\n";
    cout<<"=========================YOU=====WON=========================\n";
    cout<<"\t\tPress t to exit and p to play again:";
}

void LOST(string aim,string user,int misses,vector <char> incorrect)
{
    system("clear");
    displayman(7);
    displaystatus(aim,user,misses,incorrect);
    cout<<"\n===================YOU WERE SO CLOSE=======================\n";
    cout<<"\t\tThe word was:"<<aim;
    cout<<"\n\t\tPress t to exit and p to play again:";
}