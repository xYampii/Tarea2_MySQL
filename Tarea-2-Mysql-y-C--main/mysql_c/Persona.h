#pragma once
#include <iostream>
using namespace std;
class Persona
{
	//atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0;
		 //constructor
protected:
	Persona() {

	};
	Persona(string nom, string ape, string dir, int tel, string date) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = date;
	}
};