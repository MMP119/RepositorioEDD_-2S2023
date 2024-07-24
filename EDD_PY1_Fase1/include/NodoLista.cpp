#include "NodoLista.h"

NodoLista::NodoLista(std::string nombre, std::string password)
{
    //this.Codigo == JAVA
    // self.Codigo == Python
    this->Siguiente = 0;
    this->Anterior = 0;
    this->EmpleadoSistema = new Empleado(nombre, password);
}

NodoLista::~NodoLista()
{
    //dtor
}
