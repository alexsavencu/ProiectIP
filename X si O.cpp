// X si O.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void primul()
{
	cout << "Player 1 = X" << endl << "Player 2 = O" << endl;
	cout << "Cine este primul? (X sau O) " << endl;
	while (1)
	{
		char x;
		cin >> x;
		if (x == 'X' || x == 'x')
		{
			alegere = 1;
			break;
		}
		else if (x == 'O' || x == 'o' || x == '0')
		{
			alegere = 2;
			break;
		}
		else
			cout << "Input invalid, incearca din nou" << endl;;
	}
}
