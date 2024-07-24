#ifndef NODOLISTA_H
#define NODOLISTA_H

#include <string>
#include "Empleado.h"
using namespace std;

class NodoLista
{
    public:
        Empleado *EmpleadoSistema;
        NodoLista *Siguiente;
        NodoLista *Anterior;
        NodoLista(std::string nombre, std::string password);
        virtual ~NodoLista();

    protected:

    private:
};

#endif // NODOLISTA_H
