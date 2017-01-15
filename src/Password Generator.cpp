//============================================================================
// Name        : Password.cpp
// Author      : Ethan Elliott
// Version     :
// Copyright   : (c) Ethan Elliott 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <limits>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void Cls()
{
    system("cls");
}//Cls

void Pause(string text)
{
    cout << "\n" << text;
    getch();
}//Pause

int rnd(int seed, int max, int min)
{
	time_t now = time(0);
	tm * ltm = localtime(&now);
	Sleep(5);
	srand((rand() % 100) * ltm->tm_sec * (seed + (rand() % 1000 + 1) * (ltm->tm_sec + rand())));
	return ((rand() % max) + min);
}//RND

class Timer
{
	//Timer class
	//Allows for timing of events, without stopping the program
	//Uses ETime differences to calculate elapsed time to thousandth of a second.
private:
	bool Running;		//Clock is running
	double start;		//Start Time
	double stopTime;	//Stop Time
	double accumulatedTime;
	double ETime(){return (clock() * 0.001);}
public:
	Timer(void){Running = false;start = 0;stopTime = 0;accumulatedTime = 0;}
	void Start(){if (!Running){start = ETime();Running = true;}}
	void Stop(){double temp = Get();if(Running){accumulatedTime = temp;Running = false;}}
	void Reset(){start = ETime();accumulatedTime = 0;}
	double Get(){double result;double currentTime = ETime();if (Running){result = ((currentTime - start) + accumulatedTime);}else{result = accumulatedTime;}return result;}
	bool isRunning(){return Running;}
};

char Upper[27];
char Lower[27];
char num[11];
char car[30];

void fill_array()
{
	Lower[0] = 'a';
	Lower[1] = 'b';
	Lower[2] = 'c';
	Lower[3] = 'd';
	Lower[4] = 'e';
	Lower[5] = 'f';
	Lower[6] = 'g';
	Lower[7] = 'h';
	Lower[8] = 'i';
	Lower[9] = 'j';
	Lower[10] = 'k';
	Lower[11] = 'l';
	Lower[12] = 'm';
	Lower[13] = 'n';
	Lower[14] = 'o';
	Lower[15] = 'p';
	Lower[16] = 'q';
	Lower[17] = 'r';
	Lower[18] = 's';
	Lower[19] = 't';
	Lower[20] = 'u';
	Lower[21] = 'v';
	Lower[22] = 'w';
	Lower[23] = 'x';
	Lower[24] = 'y';
	Lower[25] = 'z';

	Upper[0] = 'A';
	Upper[1] = 'B';
	Upper[2] = 'C';
	Upper[3] = 'D';
	Upper[4] = 'E';
	Upper[5] = 'F';
	Upper[6] = 'G';
	Upper[7] = 'H';
	Upper[8] = 'I';
	Upper[9] = 'J';
	Upper[10] = 'K';
	Upper[11] = 'L';
	Upper[12] = 'M';
	Upper[13] = 'N';
	Upper[14] = 'O';
	Upper[15] = 'P';
	Upper[16] = 'Q';
	Upper[17] = 'R';
	Upper[18] = 'S';
	Upper[19] = 'T';
	Upper[20] = 'U';
	Upper[21] = 'V';
	Upper[22] = 'W';
	Upper[23] = 'X';
	Upper[24] = 'Y';
	Upper[25] = 'Z';

	num[0] = '1';
	num[1] = '2';
	num[2] = '3';
	num[3] = '4';
	num[4] = '5';
	num[5] = '6';
	num[6] = '7';
	num[7] = '8';
	num[8] = '9';
	num[9] = '0';

	car[0] = '~';
	car[1] = '!';
	car[2] = '@';
	car[3] = '#';
	car[4] = '$';
	car[5] = '%';
	car[6] = '^';
	car[7] = '&';
	car[8] = '*';
	car[9] = '(';
	car[10] = ')';
	car[11] = '-';
	car[12] = '_';
	car[13] = '=';
	car[14] = '+';
	car[15] = '[';
	car[16] = '{';
	car[17] = ']';
	car[18] = '}';
	car[19] = '\\';
	car[20] = '|';
	car[21] = ':';
	car[22] = ';';
	car[23] = '<';
	car[24] = ',';
	car[25] = '>';
	car[26] = '.';
	car[27] = '?';
	car[28] = '/';


}

int maxChars = 0;
int maxPass = 0;

int main()
{
	Timer* x;
	x = new Timer();

	x->Start();

	fill_array();
	cout << "How many Passwords? ";
	cin >> maxPass;
	cout << "How many characters? ";
	cin >> maxChars;
	for (int z = 1;z <= maxPass; z++)
	{
		stringstream pass;
		for (int a = 1; a <= maxChars; a++)
		{
			switch (rnd(x->Get(),4,1))
			{
			case 1:
				pass << Upper[rnd((x->Get() * (a+z)), 25, 0)];
				break;
			case 2:
				pass << Lower[rnd((x->Get() * (a+z)),25,0)];
				break;
			case 3:
				pass << num[rnd((x->Get() * (a+z)),9,0)];
				break;
			case 4:
				pass << car[rnd((x->Get() * (a+z)),28,0)];
				break;
			}
		}
		cout << pass.str() << "\n";
		pass.str("");
	}

	Pause("");
	return 0;
}
