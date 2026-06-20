#include <cstring>
#include <string>
#include <iostream>
#include <Persona.h>
#include <Cliente.h>

using namespace std;

Cliente::Cliente()
{
    _idCliente = 0;
    _email[0] = '\0';
}

int Cliente::getIdCliente() const
{
    return _idCliente;
}

const char* Cliente::getEmail() const
{
    return _email;
}

void Cliente::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Cliente::setEmail(const std::string& email)//el '&' evita la copia en memoria y el 'const' protege el dato original
{
    strcpy(_email, email.c_str());
}

void Cliente::Cargar()
{
    Persona::Cargar();
    cout << "Email: ";
    cin >> _email;
}

void Cliente::Mostrar()
{
        Persona::Mostrar();
        cout << "ID Cliente: " << _idCliente << endl;
        cout << "Email: " << _email << endl;
}

