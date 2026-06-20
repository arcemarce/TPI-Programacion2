#include "MenuEmpleados.h"
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include <iostream>


using namespace std;

MenuEmpleados::MenuEmpleados() {}

void MenuEmpleados::ejecutarMenu()
{
    int opcion;
    do
    {
        system("cls");
        mostrarOpciones();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);

        if(opcion != 0)
        {
            system("pause");
        }
    }
    while(opcion != 0);
}

void MenuEmpleados::mostrarOpciones()
{
    cout << "-------------------------------------" << endl;
    cout << "1. CONSULTA POR ID" << endl;
    cout << "2. LISTADO EMPLEADOS" << endl;
    cout << "3. VISUALIZACION DE EMPLEADOS ACTIVOS" <<endl;
    cout << "4. LISTADO POR TURNO (MAÑANA O TARDE)" << endl,
    cout << "0. SALIR" << endl;
    cout << "-------------------------------------" << endl;
}
int MenuEmpleados::seleccionarOpcion()
{
    int opcion;

    do
    {
        cout << "Ingrese opcion: ";
        cin >> opcion;
        if(opcion < 0 || opcion >4)
        {
            cout << "Opcion incorrecta..." << endl;
        }
    }
    while(opcion < 0 || opcion >4);
    return opcion;
}


void MenuEmpleados::ejecutarOpcion(int opcion)
{
    int idBuscar, pos;
    Empleado empl;
    string opcionTurno;

    switch(opcion)
    {
    case 1:
        cout << "Ingrese ID del empleado: ";
        cin >> idBuscar;
        pos = _repoEmpleado.buscarPorID(idBuscar);

        if(pos >=0)
        {
            Empleado empl = _repoEmpleado.leer(pos);
            cout << "-------------------------------------" << endl;
            cout << "         EMPLEADO ENCONTRADO         " << endl;
            cout << "-------------------------------------" << endl;
            empl.Mostrar();
        }
        else
        {
            cout << "El empleado con el ID " << idBuscar << " no existe en el sistema." << endl;
        }
        break;

    case 2:
        _repoEmpleado.listar();
        break;

    case 3:
        _repoEmpleado.listarActivos();
        break;

    case 4:
        cout << "Ingrese el turno a buscar (MAÑANA o TARDE): ";
        cin >> opcionTurno;

        _repoEmpleado.listarPorTurno(opcionTurno);
        break;
    case 0:
        cout << "Saliendo del programa..." << endl;
        break;
    }
}
