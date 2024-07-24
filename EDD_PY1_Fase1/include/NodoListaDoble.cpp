#include "NodoListaDoble.h"

NodoListaDoble::NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado)
{
    //ctor
    this->Codigo = codigo;
    this->Nombre_Tarea = nombre_tarea;
    this->Codigo_Encargado = codigo_encargado;
    this->Siguiente = 0;
    this->Anterior =0;
}

NodoListaDoble::~NodoListaDoble()
{
    //dtor
}
