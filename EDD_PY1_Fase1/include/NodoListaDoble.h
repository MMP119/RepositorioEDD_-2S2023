#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include <string>

using namespace std;

class NodoListaDoble
{
    public:
        std::string Codigo;
        std::string Nombre_Tarea;
        std::string Codigo_Encargado;
        NodoListaDoble *Siguiente;
        NodoListaDoble *Anterior;
        NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);

        virtual ~NodoListaDoble();

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
