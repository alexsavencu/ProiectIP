// X si O v1.0.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;
int randuljucatorului;
int OK;
int alegererand;
int tabla[3][3];
char nume[3][25];

void VerificaCastigator()
{
	OK = randuljucatorului;
	for (int i = 0; i < 3; i++)
		if (tabla[i][i] != randuljucatorului)
			OK = 0;
	if (OK == 0)
	{
		OK = randuljucatorului;
		for (int i = 0; i < 3; i++)
			if (tabla[i][2 - i] != randuljucatorului)
				OK = 0;
	}
	if (OK == 0)
	{
		if ((tabla[0][0] == randuljucatorului) && (tabla[1][0] == randuljucatorului) && (tabla[2][0] == randuljucatorului))
			OK = randuljucatorului;
		else
			if ((tabla[0][1] == randuljucatorului) && (tabla[1][1] == randuljucatorului) && (tabla[2][1] == randuljucatorului))
				OK = randuljucatorului;
			else
				if ((tabla[0][2] == randuljucatorului) && (tabla[1][2] == randuljucatorului) && (tabla[2][2] == randuljucatorului))
					OK = randuljucatorului;
				else
					if ((tabla[0][0] == randuljucatorului) && (tabla[0][1] == randuljucatorului) && (tabla[0][2] == randuljucatorului))
						OK = randuljucatorului;
					else
						if ((tabla[1][0] == randuljucatorului) && (tabla[1][1] == randuljucatorului) && (tabla[1][2] == randuljucatorului))
							OK = randuljucatorului;
						else
							if ((tabla[2][0] == randuljucatorului) && (tabla[2][1] == randuljucatorului) && (tabla[2][2] == randuljucatorului))
								OK = randuljucatorului;
	}
}

void VerificaEgal()
{
	if ((tabla[0][0]) && (tabla[0][1]) && (tabla[0][2]) && (tabla[1][0]) && (tabla[1][1]) && (tabla[1][2]) && (tabla[2][0]) && (tabla[2][1]) && (tabla[2][2]))
		OK = 3;
}

void UrmatorulJucator()
{
	if (randuljucatorului == 1)
		randuljucatorului = 2;
	else
		randuljucatorului = 1;
}

void AfisareTabla()
{
	char aux[9];
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (tabla[i][j] == 0)
				aux[k] = k + 49;
			else
			{
				if (tabla[i][j] == 1)
					aux[k] = 'X';
				else
					aux[k] = 'O';
			}
			k++;
		}

	cout << "             \n";
	cout << "  " << aux[0] << " | " << aux[1] << " | " << aux[2] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << aux[3] << " | " << aux[4] << " | " << aux[5] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << aux[6] << " | " << aux[7] << " | " << aux[8] << "   \n";
	cout << "             \n";

}

void Mutare(int i)
{
	int x = (i - 1) / 3;
	int y = ((i + 2) % 3);
	int returnVal = tabla[x][y];
	if (returnVal == 0 && i <= 9 && i >= 1)
	{
		tabla[x][y] = randuljucatorului;
		VerificaCastigator();
		VerificaEgal();
		if (!OK)
			UrmatorulJucator();
		system("cls");
	}
	else
	{
		system("cls");
		cout << "Mutare invalida, incearca din nou\n";
	}
	AfisareTabla();
}

void Joc()
{
	int i;
	while (OK != randuljucatorului&&OK != 3)
	{
		cout << nume[randuljucatorului] << " Alege o miscare: ";
		cin >> i;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		Mutare(i);
	}
	if (OK != 3)
		cout << nume[randuljucatorului] << " este catigator! \n";
	else
		cout << "Niciun castigator" << endl;
}

void AlegereNume()
{
	cout << "Numele primului jucator: ";
	cin.getline(nume[1], 25);
	cout << "\n";
	cout << "Numele celui de-al doilea jucator: ";
	cin.getline(nume[2], 25);
}

void Primul()
{
	cout << nume[1] << " = X \n";
	cout << nume[2] << " = O \n";
	cout << "Cine este primul? (X sau O) \n";
	while (1)
	{
		char x;
		cin >> x;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (x == 'X' || x == 'x')
		{
			alegererand = 1;
			break;
		}
		else if (x == 'O' || x == 'o' || x == '0')
		{
			alegererand = 2;
			break;
		}
		else
			system("cls");
		cout << "Input invalid, incearca din nou \n";
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tabla[i][j] = 0;
	OK = 0;
	AlegereNume();
	system("cls");
	Primul();
	system("cls");
	randuljucatorului = alegererand;
	AfisareTabla();
	Joc();
}