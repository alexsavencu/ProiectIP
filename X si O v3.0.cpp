// X si O v1.0.cpp : Defines the entry point for the console application.
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
int retrygame;
int scorp1, scorp2;
int play;
char nume[3][25];

void AfisareTitlu()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 12);
	cout << "\t\tXXXXXXX       XXXXXXX                        iiii            OOOOOOOOO      \n";
	cout << "\t\tX:::::X       X:::::X                       i::::i         OO:::::::::OO    \n";
	cout << "\t\tX:::::X       X:::::X                        iiii        OO:::::::::::::OO  \n";
	cout << "\t\tX::::::X     X::::::X                                   O:::::::OOO:::::::O \n";
	cout << "\t\tXXX:::::X   X:::::XXX         ssssssssss   iiiiiii      O::::::O   O::::::O \n";
	cout << "\t\t   X:::::X X:::::X          ss::::::::::s  i:::::i      O:::::O     O:::::O \n";
	cout << "\t\t    X:::::X:::::X         ss:::::::::::::s  i::::i      O:::::O     O:::::O \n";
	cout << "\t\t     X:::::::::X          s::::::ssss:::::s i::::i      O:::::O     O:::::O \n";
	cout << "\t\t     X:::::::::X           s:::::s  ssssss  i::::i      O:::::O     O:::::O \n";
	cout << "\t\t    X:::::X:::::X            s::::::s       i::::i      O:::::O     O:::::O \n";
	cout << "\t\t   X:::::X X:::::X              s::::::s    i::::i      O:::::O     O:::::O \n";
	cout << "\t\tXXX:::::X   X:::::XXX     ssssss   s:::::s  i::::i      O::::::O   O::::::O \n";
	cout << "\t\tX::::::X     X::::::X     s:::::ssss::::::si::::::i     O:::::::OOO:::::::O \n";
	cout << "\t\tX:::::X       X:::::X     s::::::::::::::s i::::::i      OO:::::::::::::OO  \n";
	cout << "\t\tX:::::X       X:::::X      s:::::::::::ss  i::::::i        OO:::::::::OO    \n";
	cout << "\t\tXXXXXXX       XXXXXXX       sssssssssss    iiiiiiii          OOOOOOOOO  \n\n";
	SetConsoleTextAttribute(consoleHandle, 15);
	
	while (1)
	{
		char x;
		cout << "Doriti sa jucati?(D/N) :";
		cin >> x;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (x == 'D' || x == 'd')
		{
			play = 1;
			break;
		}
		else if (x == 'N' || x == 'n')
		{
			play = 2;
			break;
		}
		else
		{
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << "Input invalid, incearca din nou \n";
			SetConsoleTextAttribute(consoleHandle, 15);
		}
	}
}

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
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 14);
	cout << "Scor: \n";
	cout << nume[1] << ": " << scorp1 << "\n";
	cout << nume[2] << ": " << scorp2 << "\n";
	SetConsoleTextAttribute(consoleHandle, 11);
	cout << "             \n";
	cout << "  " << aux[0] << " | " << aux[1] << " | " << aux[2] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << aux[3] << " | " << aux[4] << " | " << aux[5] << "   \n";
	cout << " ---+---+--- \n";
	cout << "  " << aux[6] << " | " << aux[7] << " | " << aux[8] << "   \n";
	cout << "             \n";
	SetConsoleTextAttribute(consoleHandle, 15);
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
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleHandle, 12);
		cout << "Mutare invalida, incearca din nou\n";
		SetConsoleTextAttribute(consoleHandle, 15);
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
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleHandle, 12);
		cout << nume[randuljucatorului] << " este catigator! \n";
		SetConsoleTextAttribute(consoleHandle, 15);
		if (OK == 1)
			scorp1++;
		else if (OK == 2)
			scorp2++;
	}
	else
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consoleHandle, 12);
		cout << "Niciun castigator \n" << endl;
		SetConsoleTextAttribute(consoleHandle, 15);
	}
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
		{
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << nume[1] << " este catigator! \n";
			SetConsoleTextAttribute(consoleHandle, 15);
			scorp1++;
		}
		else
		{
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << nume[2] << " este castigator! \n";
			SetConsoleTextAttribute(consoleHandle, 15);
			scorp2++;
		}
	else
		cout << "Niciun castigator \n" << endl;
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
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << "Input invalid, incearca din nou \n \n";
			SetConsoleTextAttribute(consoleHandle, 15);
		}
	}

}

void Primul()
{
	char x;
	while(1)
	{ 
	cout << nume[1] << " = X \n";
	cout << nume[2] << " = O \n";
	cout << "Cine este primul? (X sau O) \n";
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
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << "Input invalid, incearca din nou \n \n";
			SetConsoleTextAttribute(consoleHandle, 15);
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
	nume[2][0] = 'A';
	nume[2][1] = 'I';
}

void Retry()
{
	while (1)
	{
		char x;
		cout << "Doriti sa jucati din nou?(D/N) :";
		cin >> x;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (x == 'D' || x == 'd')
		{
			retrygame = 1;
			break;
		}
		else if (x == 'N' || x == 'n')
		{
			retrygame = 2;
			break;
		}
		else
		{
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consoleHandle, 12);
			cout << "Input invalid, incearca din nou \n";
			SetConsoleTextAttribute(consoleHandle, 15);
		}
	}
}

void CuratareTabla()
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			tabla[i][j] = 0;
	OK = 0;
}

void SfarsitulJocului()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, 12);
	cout << "Sfarsitul jocului \n";
	SetConsoleTextAttribute(consoleHandle, 14);
	cout << "Scor final: \n";
	cout << nume[1] << ": " << scorp1 << "\n";
	cout << nume[2] << ": " << scorp2 << "\n";
	SetConsoleTextAttribute(consoleHandle, 15);
}

int main()
{
	AfisareTitlu();
	system("cls");
	if (play == 1)
	{
	CuratareTabla();
	AlegeJocul();
	system("cls");
		if (alegerejoc == 1)
		{
			cin.get();
			AlegereNume1();
			system("cls");
			Primul();
			system("cls");
			randuljucatorului = alegererand;
		repetare1:
			AfisareTabla();
			Joc1();
			Retry();
			system("cls");
			if (retrygame == 1)
			{
				CuratareTabla();
				goto repetare1;
			}
			else
			{
				SfarsitulJocului();
			}
		}
		else
		{

			cin.get();
			AlegereNume2();
			system("cls");
			Primul();
			system("cls");
			AfisareTabla();
			randuljucatorului = alegererand;
		repetare2:
			Joc2();
			Retry();
			system("cls");
			if (retrygame == 1)
			{
				CuratareTabla();
				goto repetare2;
			}
			else
			{
				SfarsitulJocului();
			}
		}
	}
	else
		exit(0);
	return 0;
}