#pragma once
#include "ClienteArchivo.h"
#include "Cliente.h"

class MenuClientes
{
public:
    MenuClientes();
    void ejecutarMenu();
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

private:
    ClienteArchivo _repoCliente;
};
