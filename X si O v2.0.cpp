// X si O v2.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;
int tabla[3][3];
int randuljucatorului;
int OK;
int alegererand;
int alegerejoc;
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
	int aux[9];
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
	cout << "  " << (char)aux[0] << " | " << (char)aux[1] << " | " << (char)aux[2] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << (char)aux[3] << " | " << (char)aux[4] << " | " << (char)aux[5] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << (char)aux[6] << " | " << (char)aux[7] << " | " << (char)aux[8] << "   \n";
	cout << "             \n";

}
void Mutare(int i)
{
	int x, y;
	x = (i - 1) / 3;
	y = ((i + 2) % 3);
	if (tabla[x][y] == 0 && i <= 9 && i >= 1)
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

void Joc1()
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

void Joc2()
{
	int i, xa, ya;
	while (OK != randuljucatorului && OK != 3)
	{

		if (randuljucatorului == 1)
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
		else if (randuljucatorului == 2)
		{
			do
			{
				i = rand() % 10 + 1;
				xa = (i - 1) / 3;
				ya = (i + 2) % 3;
			} while (tabla[xa][ya]);
			Mutare(i);
		}
	}
	if (OK != 3)
		if (randuljucatorului == 1)
			cout << nume[1] << " este catigator! \n";
		else
			cout << "AI te-a invins! \n";
	else
		cout << "Niciun castigator" << endl;
}

void AlegeJocul()
{
	int x;
	while (1)
	{
		cout << "Alege modul de joc: \n";
		cout << "1.Player vs Player \n";
		cout << "2.Player vs AI \n";
		cout << "Aleg: ";
		cin >> x;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (x == 1)
		{
			alegerejoc = 1;
			break;
		}
		else if (x == 2)
		{
			alegerejoc = 2;
			break;
		}
		else
		{
			system("cls");
			cout << "Input invalid, incearca din nou \n \n";
		}
	}

}

void Primul1()
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
		{
			system("cls");
			cout << "Input invalid, incearca din nou \n";
		}
	}
}

void Primul2()
{
	cout << nume[1] << "= X \n";
	cout << "AI = O \n";
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
		{
			system("cls");
			cout << "Input invalid, incearca din nou \n";
		}
	}
}

void AlegereNume1()
{
	cout << "Numele primului jucator: ";
	cin.getline(nume[1], 25);
	cout << "\n";
	cout << "Numele celui de-al doilea jucator: ";
	cin.getline(nume[2], 25);
}

void AlegereNume2()
{
	cout << "Numele jucatorului: ";
	cin.getline(nume[1], 25);
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tabla[i][j] = 0;
	OK = 0;
	AlegeJocul();
	system("cls");
	if (alegerejoc == 1)
	{
		cin.get();
		AlegereNume1();
		system("cls");
		Primul1();
		system("cls");
		randuljucatorului = alegererand;
		AfisareTabla();
		Joc1();
	}
	else
	{
		cin.get();
		AlegereNume2();
		system("cls");
		Primul2();
		system("cls");
		AfisareTabla();
		randuljucatorului = alegererand;
		Joc2();
	}
}