#include <cstring>
#include <string>
#include <iostream>
#include "Empleado.h"
#include "Persona.h"

using namespace std;

Empleado::Empleado()
{

}

int Empleado::getIdEmpleado() const
{
    return _idEmpleado;
}

const char* Empleado::getPuesto() const
{
    return _puesto;
}

const char* Empleado::getTurno() const
{
    return _turno;
}

void Empleado::setIdEmpleado(int idEmpleado)
{
    _idEmpleado = idEmpleado;
}

void Empleado::setPuesto(const std::string& puesto)
{
    strcpy(_puesto, puesto.c_str());
}

void Empleado::setTurno(const std::string& turno)
{
    strcpy(_turno, turno.c_str());
}

void Empleado::Cargar()
{
    Persona::Cargar();
    cout << "ID Empleado: ";
    cin >> _idEmpleado;
    cout << "Puesto: ";
    cin >> _puesto;
    cout << "Turno: ";
    cin >> _turno;
}

void Empleado::Mostrar()
{
    if(getEstado() == true)
    {
        Persona::Mostrar();
        cout << "ID Empleado: " << _idEmpleado << endl;
        cout << "Puesto: " << _puesto << endl;
        cout << "Turno: " << _turno << endl;
    }
}

