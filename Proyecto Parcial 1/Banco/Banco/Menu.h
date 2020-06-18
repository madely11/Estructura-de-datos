#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
#include "TipoCuenta.h"
using namespace std;

class Menu {
public:
	void menuTeclas();
	void ocultarCursor();
	void submenu1();
	void submenu2();
	int suma(int a, int b);
};

int Menu::suma(int a, int b) {
	return a + b;
}

void Menu::ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Menu::menuTeclas()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Crear Cuenta              ",
					  "Realizar Transaccion      ",
					  "Registro de transacciones ",
					  "Salir                     " };
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 4; i++)
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		ocultarCursor();

		for (;;)
		{
			tecla = _getch();
			if (tecla == 80)
			{
				cursor++;
				if (cursor == 4)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72)
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 3;
				}
				break;
			}
			if (tecla == 13)
			{
				switch (cursor)
				{
				case 0:
					submenu1();
					break;
				case 1:
					submenu2();
					break;
				case 2:
					menuTeclas();
					break;
				case 3:
					system("cls");
					cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
					Sleep(1000);
					exit(1);
					break;	
				}
			}
		}
	}
}

void Menu::submenu1()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Ahorros      ",
					  "Credito      ",
					  "Cancelar     "};

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 3; i++)
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		ocultarCursor();

		for (;;)
		{
			tecla = _getch();
			if (tecla == 80)
			{
				cursor++;
				if (cursor == 3)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72)
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 2;
				}
				break;
			}
			if (tecla == 13)
			{
				switch (cursor)
				{
				case 0:
					if(true)
						TipoCuenta tipo1(1);
					break;
				case 1:
					if(true)
						TipoCuenta tipo2(2);
					break;
				case 2:
					system("cls");
					cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
					Sleep(1000);
					menuTeclas();
					break;
				}
			}
		}
	}
}

void Menu::submenu2()
{
	int cursor = 0;
	char tecla;
	//int opcion;
	int cont = 1;
	system("cls");
	string menu[] = { "Deposito      ",
					  "Retiro        ",
					  "Cancelar      " };

	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 3; i++)
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		ocultarCursor();

		for (;;)
		{
			tecla = _getch();
			if (tecla == 80)
			{
				cursor++;
				if (cursor == 3)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72)
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 2;
				}
				break;
			}
			if (tecla == 13)
			{
				switch (cursor)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					system("cls");
					cout << endl << "<<<<<<<<<Proceso Cancelado>>>>>>>>>" << endl;
					Sleep(1000);
					menuTeclas();
					break;
				}
			}
		}
	}
}