#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Lista
{
    public:
        NodoLista *Primero;
        int Tamanio;
        void Insertar(std::string nombre, std::string password);
        void VerLista();
        void VerLista1();
        void LeerArchivo(std::string nombre_archivo);
        void Graficar();
        std::string BuscarPorCodigo(const std::string& codigo);
        Lista();
        virtual ~Lista();

    protected:

    private:
};

#endif // LISTA_H
