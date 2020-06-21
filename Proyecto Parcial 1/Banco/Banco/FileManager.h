#pragma once
#include <fstream>
#include <iostream>
#include <string>
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
	void cerrarLectura();
	void cerrarEscritura();
	int contarLineas();
	string buscarCuenta(int);
	void actualizar(int, string);
	string comparar(int, string);
};



bool FileManager::crearEscritura()
{

	archivoEscritura.open(nombre_archivo, ios::out | ios::app);

	if (archivoEscritura.fail()) {
		cout << "Imposible abrir el archivo: " << nombre_archivo << endl;
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
		cout << "Imposible abrir el archivo: " << nombre_archivo << endl;
		return false;
	}
	else {
		return true;
	}
}

void FileManager::cerrarLectura()
{
	archivoLectura.close();
}

void FileManager::cerrarEscritura()
{
	archivoEscritura.close();
}

void FileManager::agregarLinea(string linea)
{
	crearEscritura();
	archivoEscritura << linea << endl;
	cerrarEscritura();
}


inline int FileManager::contarLineas()
{
	int cuentaLinea=0;
	string texto;
	if (!crearLectura()) {
		cerrarLectura();
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

string FileManager::buscarCuenta(int _id)
{
	crearLectura();
	string texto;
	string texto2 = "salir";
	string id_string;
	while (!archivoLectura.eof())
	{
		getline(archivoLectura, texto);
		texto = comparar(_id, texto);
		if (!texto._Equal("salir")) {
			cerrarLectura();
			return texto;
		}
	}
	cerrarLectura();
	return texto2;
}

inline void FileManager::actualizar(int _id, string dato_nuevo)
{
	ofstream archivoAux;
	string dato;

	archivoAux.open("cuentaAux.txt", ios::out | ios::app);
	if (!crearLectura()) {
		return;
	}

	if (archivoAux.fail()) {
		cout << "No se abre el aux" << endl;
		return;
	}

	while (!archivoLectura.eof()) {

		getline(archivoLectura, dato);
		if (comparar(_id, dato)._Equal("salir")) {
			archivoAux << dato << endl;
		}
		else {
			archivoAux << dato_nuevo << endl;
		}
	}
	archivoAux.close();
	cerrarLectura();
	remove("cuenta.txt");
	rename("cuentaAux.txt", "cuenta.txt");

}

inline string FileManager::comparar(int _id, string dato)
{
	int i = 0;
	int id = 0;
	string texto2 = "salir";
	string id_string;
	id_string = "";
	while (i < dato.length() && dato.at(i) != ',') {
		i++;
	}
	i++;
	while (i < dato.length() && dato.at(i) != ',') {
		id_string += dato.at(i);
		i++;
	}
	id = atoi(id_string.c_str());
	if (id == _id) {
		return dato;
	}
	return texto2;
}

