#include "Utils.h"
#include <regex>
#include <iostream>
#include <string>

bool validarEmail(const std::string& email){

    const std::regex patron("^[^\\s@]+@[^\\s@]+\\.[^\\s@]{2,}$");
    bool esValido = std::regex_match(email, patron);
    return esValido;
}

/*con la libreria regex podemos verificar si un email ingresado
cumple con la sintaxis propia de un email, validando que se
ingrese una opcion valida.
El texto dentro de los parentesis  es la regla que define como
debe lucir un correo valido.
*/


