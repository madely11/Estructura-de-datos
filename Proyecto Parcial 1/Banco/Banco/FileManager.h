#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "FileManager.h"
using namespace std;


class FileManager
{
private:
	string nombre_archivo;
	ifstream archivoLectura; //archivo de lectura
	ofstream archivoEscritura; //archivo de escritura

public:
	FileManager(string _nombre_archivo);
	bool crearLectura();
	bool crearEscritura();
	void agregarLinea(string linea);
	string leer(int linea);
	void cerrarLectura();
	void cerrarEscritura();
	int contarLineas(string);

};



bool FileManager::crearEscritura()
{

	archivoEscritura.open(nombre_archivo, ios::out | ios::app);

	if (archivoEscritura.fail()) {
		return false;
	}
	else {
		return true;
	}
}

FileManager::FileManager(string _nombre_archivo)
{
	
	nombre_archivo = _nombre_archivo;
	crearEscritura();
	cerrarEscritura();
}

bool FileManager::crearLectura()
{
	archivoLectura.open(nombre_archivo, ios::in);

	if (archivoLectura.fail()) {
		return false;
	}
	else {
		return true;
	}
}

void FileManager::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}

string FileManager::leer(int linea)
{
	crearLectura();
	int i = 0;
	string texto;
	while (!archivoLectura.eof())
	{
		cout << i << endl;
		//cin >> nombre >> apellido >> 
		getline(archivoLectura, texto);
		cout << texto << endl;
	}
	cerrarLectura();
	return texto;
}

void FileManager::cerrarLectura()
{
	archivoLectura.close();
}

void FileManager::cerrarEscritura()
{
	archivoEscritura.close();
}

inline int FileManager::contarLineas(string file)
{
	int cuentaLinea=0;
	nombre_archivo = file;
	string texto;
	if (!crearLectura()) {
		return -1;
	}
	while (!archivoLectura.eof())
	{
		
		getline(archivoLectura, texto);
		cuentaLinea++;
		
	}
	cerrarLectura();
	return cuentaLinea;
}
