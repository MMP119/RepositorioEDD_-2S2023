#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "NodoListaDoble.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include "json.hpp"


using namespace std;

class ListaDoble
{
    public:
        NodoListaDoble *Primero;
        int Tamanio;
        void Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado);
        void Asignar(std::string codigo, std::string nombre_tarea, std::string encargado);
        void MostrarTareasPorProyecto(std::string codigo_proyecto);
        void Graficar();
        std::vector<std::pair<std::string, std::string>> buscarTareasPorProyecto(std::string codigoProyecto);
        ListaDoble();
        virtual ~ListaDoble();

    protected:

    private:
};

#endif // LISTADOBLE_H
