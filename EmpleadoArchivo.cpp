#include "EmpleadoArchivo.h"
#include "Empleado.h"
#include <cstring>

EmpleadoArchivo::EmpleadoArchivo()
{
    strcpy(_nombreArchivo, "archivoEmpleado.dat");
}

Empleado EmpleadoArchivo::leer(int pos){
    Empleado empl;
    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        cout << "Error: no se pudo abrir el archivo de empleados." << endl;
        return empl;
    }
    fseek(pEm, pos * sizeof empl, SEEK_SET);
    fread(&empl, sizeof empl, 1, pEm);
    fclose(pEm);
    return empl;
}

void EmpleadoArchivo::listar(){
    Empleado empl;

    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        cout << "Error: No se pudo abrir el archivo de empleados." << endl;
        return;
    }

    cout << "_______ LISTADO DE EMPLEADOS _______" << endl;
    while(fread(&empl, sizeof empl, 1, pEm) == 1){
        empl.Mostrar();
        cout << "____________________________________" << endl;
    }
    fclose(pEm);
}

void EmpleadoArchivo::listarActivos(){
    Empleado empl;

    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        cout << "Error: No se pudo abrir el archivo de empleados." << endl;
        return;
    }
    cout << "_______ LISTADO DE EMPLEADOS ACTIVOS _______" << endl;

    while (fread(&empl, sizeof empl, 1, pEm) == 1){
        if(empl.getEstado() == true){
            empl.Mostrar();
            cout << "____________________________________________" << endl;
        }
    }
    fclose(pEm);
}

void EmpleadoArchivo::listarPorTurno(string turno){
    Empleado empl;

    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        cout << "Error: No se pudo abrir el archivo de empleados." << endl;
        return;
    }

    while(fread(&empl, sizeof empl, 1, pEm) == 1){
        if(empl.getTurno() == turno){
            empl.Mostrar();
            cout << "______________________________" << endl;
        }
    }
    fclose(pEm);


}

int EmpleadoArchivo::buscarPorID(int id){
    Empleado empl;

    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        return -1;
    }

    int pos = 0;

    while(fread(&empl, sizeof empl, 1, pEm) == 1){
        if(empl.getIdEmpleado() == id){
            fclose(pEm);
            return pos;
        }
        pos++;
    }
    fclose(pEm);
    return -1;
}

bool EmpleadoArchivo::existeEmpleado(int id){
    return buscarPorID(id) != -1;
}

int EmpleadoArchivo::contarRegistros(){
    FILE *pEm = fopen(_nombreArchivo, "rb");
    if(pEm == nullptr){
        return 0;
    }
    fseek(pEm, 0, SEEK_END);
    long tamArch = ftell(pEm);
    fclose(pEm);

    if(tamArch <= 0){return 0;}
    return (int)(tamArch / sizeof(Empleado));
}
