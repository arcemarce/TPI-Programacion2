#include "MenuClientes.h"
#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>

using namespace std;

MenuClientes::MenuClientes() {}


void MenuClientes::ejecutarMenu()
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

void MenuClientes::mostrarOpciones()
{
    cout << "-------------------------------------" << endl;
    cout << "1. ALTA NUEVO CLIENTE" << endl;
    cout << "2. ACTUALIZACION DE DATOS DE CLIENTES" << endl;
    cout << "3. BAJA (DESACTIVAR CLIENTE)" <<endl;
    cout << "4. CONSULTA (POR ID O DNI)" << endl;
    cout << "5. LISTADOS (ACTIVOS O INACTIVOS)" << endl;
    cout << "0. SALIR" << endl;
    cout << "-------------------------------------" << endl;
}

int MenuClientes::seleccionarOpcion()
{
    int opcion;

    do
    {
        cout << "Ingrese opcion: ";
        cin >> opcion;
        if(opcion < 0 || opcion >5)
        {
            cout << "Opcion incorrecta..." << endl;
        }
    }
    while(opcion < 0 || opcion > 5);
    return opcion;
}

void MenuClientes::ejecutarOpcion(int opcion)
{
    ClienteArchivo clien;
    int numConsulta, idAux, pos, proximoID;
    Cliente c;
    string dniAux;

    switch(opcion)
    {
    case 1:
        cout << "---- ALTA NUEVO CLIENTE ----" << endl;
        cin.ignore();
        proximoID = clien.contarRegistros() + 1; // el sistema asigna automaticamente el id al crear un nuevo cliente
        c.Cargar();
        c.setIdCliente(proximoID);

        if(clien.guardar(c) == true){
            cout << "Cliente guardado con exito." << endl;
        }
        else{
            cout << "No se pudo dar de alta al cliente." << endl;
        }
        break;

    case 2:
        cout << "Ingrese el ID del cliente a modificar: ";
        cin >> idAux;
        pos = clien.buscarPorID(idAux);//devuelve la posicion segun el id que le pasamos

        if(pos != -1){
           c = clien.leer(pos);
           cin.ignore();
           c.Cargar();
           clien.modificar(c, pos);
        }
        else{
            cout << "Cliente no encontrado." << endl;
        }
        break;

    case 3:
        cout << "Ingrese ID de cliente a dar de baja: ";
        cin >> idAux;
        pos = clien.buscarPorID(idAux);

        if(pos != -1){
            clien.bajaLogica(idAux);
        }else{
        cout << "Cliente no encontrado." << endl;
        }
        break;

    case 4:
        cout << "CONSULTA POR ID O DNI:" << endl;
        do
        {
            cout << "Ingrese 1 si desea consultar por ID o 2 por DNI: ";
            cin >> numConsulta;

            if(numConsulta < 1 || numConsulta > 2)
            {
                cout << "Opcion no valida" << endl;
            }
        }
        while(numConsulta < 1 || numConsulta > 2);

            if(numConsulta == 1)
            {
                cout << "Ingrese el ID: ";
                cin >> idAux;
                pos = clien.buscarPorID(idAux);
                if(pos != -1){
                    c = clien.leer(pos);
                    c.Mostrar();
                }else{
                    cout << "Cliente no encontrado." << endl;
                }

            }
            else
            {
                cout << "Ingrese el DNI: ";
                cin >> dniAux;
                pos = clien.buscarPorDNI(dniAux);
                if(pos != -1){
                    c = clien.leer(pos);
                    c.Mostrar();
                }
                else{
                    cout << "Cliente no encontrado." << endl;
                }
            }
        break;

    case 5:
        cout << "LISTADO DE CLIENTES" << endl;
        do
        {
            cout << "Ingrese 1 si desea consultar clientes activos o 2 clientes inactivos: ";
            cin >> numConsulta;

            if(numConsulta < 1 || numConsulta > 2)
            {
                cout << "Opcion no valida" << endl;
            }
        }
        while(numConsulta < 1 || numConsulta > 2);
        if(numConsulta == 1)
        {
            clien.listarActivos();
        }
        else
        {
            clien.listarInactivos();
        }

        break;

    case 0:
        cout << "Saliendo..." << endl;
        break;
    }
}
