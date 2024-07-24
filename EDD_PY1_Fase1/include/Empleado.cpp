#include "Empleado.h"

Empleado::Empleado(std::string nombre, std::string password)
{
    //ctor
    this->Codigo = "";
    this->Nombre = nombre;
    this->Password = password;
    this->Puesto = "";
}

Empleado::~Empleado()
{
    //dtor
}
