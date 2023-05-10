#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "Persona.h"
#include <string>

using namespace std;
class Cliente : Persona {
	//atributos
private: string nit;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string date, string n) : Persona(nom, ape, dir, tel, date) {
		nit = n;
	};
	//Metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFechaNacimiento(string date) { fecha_nacimiento = date; }
	//get (obtener)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	//metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(telefono);
			string insert = "INSERT INTO CLIENTES(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + fecha_nacimiento + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert got problems";
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT *FROM clientes";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "id_cliente: " << fila[0] << endl;
					cout << "nit: " << fila[1] << endl;
					cout << "nombres: " << fila[2] << endl;
					cout << "apellidos: " << fila[3] << endl;
					cout << "direccion: " << fila[4] << endl;
					cout << "telefono :" << fila[5] << endl;
					cout << "fecha_nacimiento: " << fila[6] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
};