#include "ListaDoble.h"
#include <iostream>
#include "json.hpp"

ListaDoble::ListaDoble()
{
    //ctor
    this ->Primero = 0;
    this->Tamanio =0;
}

ListaDoble::~ListaDoble()
{
    //dtor
}

void ListaDoble::Insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado){
    NodoListaDoble *nuevo = new NodoListaDoble(codigo, nombre_tarea, codigo_encargado);
    if(this->Primero==0){
        this->Primero = nuevo;
        this->Tamanio++;
    }else{
        NodoListaDoble *aux = this->Primero;
        while (aux->Siguiente){
            aux = aux->Siguiente;
        }
        nuevo->Anterior = aux;
        aux->Siguiente = nuevo;
        this->Tamanio++;
    }
}

void ListaDoble::Asignar(std::string codigo, std::string nombre_tarea, std::string encargado){
    if(this->Primero){
        NodoListaDoble *aux = this->Primero;
        while (aux){
            if(aux->Codigo.compare(codigo)== 0 && aux->Nombre_Tarea.compare(nombre_tarea)==0){
                aux->Codigo_Encargado = encargado;
                break;
            }
            aux = aux->Siguiente;
        }
    }

}


void ListaDoble::Graficar()
{
    ofstream archivo;
    std::string nombre_archivo = "lista_doble.dot";
    std::string nombre_imagen = "lista_doble.png";
    NodoListaDoble *aux = this->Primero;

    archivo.open(nombre_archivo, ios::out);
    if (this->Tamanio > 0) {
        archivo << "digraph listaDobleGraph { \n node[shape=box]; \n";

        int contador = 0;
        while (aux) {
            archivo << "nodoListaDoble" << contador << "[label=\"" << aux->Codigo << "\\nTarea: " << aux->Nombre_Tarea << "\\nEncargado: " << aux->Codigo_Encargado << "\"];\n";
            aux = aux->Siguiente;
            contador++;
        }

        archivo << "\n";

        aux = this->Primero;
        NodoListaDoble *aux1 = aux->Siguiente;
        contador = 0;
        int contador1 = 1;

        while (aux) {
            if (aux1) {
                archivo << "nodoListaDoble" << contador << " -> " << "nodoListaDoble" << contador1 << ";\n";
                archivo << "nodoListaDoble" << contador1 << " -> " << "nodoListaDoble" << contador << ";\n";
            }
            aux = aux->Siguiente;
            aux1 = aux ? aux->Siguiente : nullptr;
            contador++;
            contador1++;
        }

        archivo << "} \n";
    } else {
        archivo << "Lista vacía \n";
    }

    archivo.close();
    std::string codigo_cmd="dot -Tjpg ";
    codigo_cmd+=nombre_archivo;
    codigo_cmd+=" -o ";
    codigo_cmd+=nombre_imagen;
    char j[codigo_cmd.size()+1];
    strcpy(j,codigo_cmd.c_str());
    cout << j << endl;
    system(j);
}

void ListaDoble::MostrarTareasPorProyecto(std::string codigo_proyecto) {
    if (this->Primero == nullptr) {
        return;
    }

    NodoListaDoble *aux = this->Primero;
    bool proyectoEncontrado = false;

    while (aux) {
        if (aux->Codigo == codigo_proyecto) {
            proyectoEncontrado = true;
            cout << aux->Nombre_Tarea<<endl;
        }
        aux = aux->Siguiente;
    }

    if (!proyectoEncontrado) {
        cout << "No se encontraron tareas para el proyecto con código: " << codigo_proyecto <<endl;
    }
}


#include <vector>
#include <utility>

std::vector<std::pair<std::string, std::string>> ListaDoble::buscarTareasPorProyecto(std::string codigoProyecto) {
  std::vector<std::pair<std::string, std::string>> tareas;
  NodoListaDoble *aux = this->Primero;
  while (aux) {
    if (aux->Codigo == codigoProyecto) {
      tareas.push_back(std::make_pair(aux->Nombre_Tarea, aux->Codigo_Encargado));
    }
    aux = aux->Siguiente;
  }
  return tareas;
}
