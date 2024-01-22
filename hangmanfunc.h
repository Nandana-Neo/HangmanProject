#include <iostream>
#include <vector>
#include <string.h>
#include <windows.h>
using namespace std;
void greet();
void horistick();
void stick();
string pickaword();
void displayman(int misses);
void displaystatus(string aim,string user,int misses,vector <char> incorrect);
int check(string aim,string &user,char e,vector <char> &incorrect);
bool ifdone(string);
void WON();
void LOST(string aim,string user,int misses,vector <char> incorrect);