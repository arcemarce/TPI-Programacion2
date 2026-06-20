#include "ClienteArchivo.h"
#include <cstring>

ClienteArchivo::ClienteArchivo()
{
    strcpy(_nombreArchivo, "archivoCliente.dat");
}

bool ClienteArchivo::guardar(Cliente clien){
    if(buscarPorDNI(clien.getDni()) != -1){
        cout << "Error: Ya existe un cliente con este DNI." << endl;
        return false;
    }
    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "ab");
    if(pCliente == nullptr){
        cout << "Error: No se pudo abrir el archivo de clientes." << endl;
        return false;
    }
    int escribio = fwrite(&clien, sizeof clien, 1, pCliente);
    fclose(pCliente);

    if(escribio == 1){
        return true; //si escribio vale 1 significa que se guardo correctamente
    }
    else{
        return false; //se produjo una falla
    }
}

Cliente ClienteArchivo::leer(int pos){
    Cliente clien;

    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
        cout << "Error: no se pudo abrir el archivo de clientes." << endl;
        return clien;
    }
    fseek(pCliente, pos * sizeof clien, SEEK_SET);
    fread(&clien, sizeof clien, 1, pCliente);
    fclose(pCliente);
    return clien;

}

bool ClienteArchivo::modificar(Cliente clien, int pos){
    FILE *pCliente = fopen(_nombreArchivo, "rb+");

    if(pCliente ==nullptr){
        cout << "Error: no se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    fseek(pCliente, pos * sizeof clien, SEEK_SET);
    bool cambio = fwrite(&clien, sizeof clien, 1, pCliente);
    fclose(pCliente);
    return cambio;
}

bool ClienteArchivo::bajaLogica(int id){
    Cliente clien;

    int pos = buscarPorID(id);

    if(pos == -1){
        cout << "El Cliente no existe." << endl;
        system("pause");
        return false;
    }

    clien = leer(pos);
    clien.setEstado(false);
    return modificar(clien, pos);
}

void ClienteArchivo::listar(){
    Cliente clien;

    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
        cout << "Error: No se pudo abrir el archivo de clientes." << endl;
        return;
    }

    cout << "_______ LISTADO DE CLIENTES _______" << endl;

    while(fread(&clien, sizeof clien, 1 , pCliente) == 1){
        clien.Mostrar();
        cout << "___________________________________" << endl;
    }
    fclose(pCliente);
}

void ClienteArchivo::listarActivos(){
    Cliente clien;
    int contadorActivos = 0;// si el contador sigue en 0  al cerrar el archivo
                               //mostramos un mensaje que nos da esta informacion
    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
        cout << "Error: No se pudo abrir el archivo de clientes." << endl;
        return;
    }
      cout << "_______ LISTADO DE CLIENTES ACTIVOS _______" << endl;

    while (fread(&clien, sizeof clien, 1, pCliente) == 1){
        if(clien.getEstado() == true){
            clien.Mostrar();
            contadorActivos++;
            cout << "___________________________________________" << endl;
        }
    }
    fclose(pCliente);

    if(contadorActivos == 0){
        cout << "No hay clientes activos para mostrar." << endl;
    }
}

void ClienteArchivo::listarInactivos(){
    Cliente clien;
    int contadorInactivos = 0;

    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
        cout << "Error: No se pudo abrir el archivo de clientes" << endl;
        return;
    }
    cout << "_______ LISTADO DE CLIENTES INACTIVOS _______" << endl;

    while(fread(&clien, sizeof clien, 1, pCliente) == 1){
        if(clien.getEstado() == 0){
            clien.Mostrar();
            contadorInactivos++;
        }
    }
    fclose(pCliente);

    if(contadorInactivos == 0){
        cout << "No hay clientes inactivos para mostrar." << endl;
    }
}

int ClienteArchivo::buscarPorID(int id){
    Cliente clien;
    int pos = 0;

    FILE *pCLiente;
    pCLiente = fopen(_nombreArchivo, "rb");
    if(pCLiente == nullptr){
       return -1;
    }
    while(fread(&clien, sizeof clien, 1, pCLiente) == 1){
        if(id == clien.getIdCliente()){
          fclose(pCLiente)  ;
          return pos;
        }
        pos++;
    }
    fclose(pCLiente);
    return -1;
}

int ClienteArchivo::buscarPorDNI(string dni){
    Cliente clien;
    int pos = 0;

    FILE *pCLiente;
    pCLiente = fopen(_nombreArchivo, "rb");
    if(pCLiente == nullptr){
      return -1;
    }
    while(fread(&clien, sizeof clien, 1, pCLiente) == 1){
        if(dni == clien.getDni()){
            fclose(pCLiente);
            return pos;
        }
        pos++;
    }
    fclose(pCLiente);
    return -1;
}

bool ClienteArchivo::existeDNI(string dni){
    Cliente clien;

    FILE *pCliente;
    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
       return 0;
    }
    while(fread(&clien, sizeof clien, 1, pCliente) == 1){
        if(clien.getDni() == dni){
            fclose(pCliente);
            return true;
        }
    }
    fclose(pCliente);
    return false;
}

int ClienteArchivo::contarRegistros(){
    FILE *pCliente;

    pCliente = fopen(_nombreArchivo, "rb");
    if(pCliente == nullptr){
        return 0;
    }
    fseek(pCliente, 0, SEEK_END);
    int reg = ftell(pCliente);
    fclose(pCliente);
    return reg / sizeof(Cliente);
}
