#include "Matriz.h"
#include "json.hpp"



Matriz::Matriz()
{
    //ctor
    this->Raiz = new NodoMatriz(new Proyecto("CABEZA",""),new Empleado("",""),-1,-1);
    this->CoordenadaX = 0;
    this->CoordenadaY = 0;
    this->lista = nullptr;
}

Matriz::~Matriz()
{
    //dtor
}

NodoMatriz* Matriz::buscarF(int y)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosY == y)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}

NodoMatriz* Matriz::buscarC(int x)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosX == x)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

NodoMatriz* Matriz::insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna)
{
    NodoMatriz *temp = cabeza_columna;
    bool piv = false;
    while(true)
    {
        if(temp->PosX==nuevo->PosX){
            temp->PosY = nuevo->PosY;
            temp->Encargado_c = nuevo->Encargado_c;
            temp->Proyecto_c = nuevo->Proyecto_c;
            return temp;
        }else if(temp->PosX > nuevo->PosX){
            piv=true;
            break;
        }
        if(temp->Siguiente){
            temp = temp->Siguiente;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Siguiente = temp;
        temp->Anterior->Siguiente = nuevo;
        nuevo->Anterior=temp->Anterior;
        temp->Anterior=nuevo;
    }
    else
    {
        temp->Siguiente=nuevo;
        nuevo->Anterior=temp;
    }
    return nuevo;
}

NodoMatriz* Matriz::insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila)
{
    NodoMatriz *temp = cabeza_fila;
    bool piv = false;
    while(true)
    {
        if(temp->PosY==nuevo->PosY){
            temp->PosX = nuevo->PosX;
            temp->Encargado_c = nuevo->Encargado_c;
            temp->Proyecto_c = nuevo->Proyecto_c;
            return temp;
        }else if(temp->PosY > nuevo->PosY){
            piv=true;
            break;
        }
        if(temp->Abajo){
            temp = temp->Abajo;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Abajo = temp;
        temp->Arriba->Abajo = nuevo;
        nuevo->Arriba = temp->Arriba;
        temp->Arriba = nuevo;
    }
    else
    {
        temp->Abajo = nuevo;
        nuevo->Arriba = temp;
    }
    return nuevo;
}

/** NUEVAS FUNCIONES */
NodoMatriz* Matriz::nueva_columna_1(int x, Proyecto *proyecto)
{
    NodoMatriz *columna = this->insertar_columna(new NodoMatriz(proyecto, 0, x, -1), this->Raiz);
    return columna;
}

void Matriz::insertar_proyecto(ColaPrioridad *cola)
{
    NodoMatriz *nodo_Columna = this->nueva_columna_1(this->CoordenadaX, cola->Primero->Proyecto_C);
    this->CoordenadaX++;
}

NodoMatriz* Matriz::nueva_fila_1(int y, Empleado *encargado)
{
    NodoMatriz *fila = this->insertar_fila(new NodoMatriz(0, encargado, -1, y), this->Raiz);
    return fila;
}

void Matriz::insertar_empleado(Lista *lista)
{
    NodoLista *aux = lista->Primero;
    int contador = 0;
    while(lista->Tamanio > contador)
    {
        // Verificar si el empleado ya existe en la matriz
        NodoMatriz *empleadoExistente = this->buscarF_1(aux->EmpleadoSistema->Nombre);

        if (empleadoExistente == 0)  // Si el empleado no existe
        {
            this->nueva_fila_1(this->CoordenadaY, aux->EmpleadoSistema);
            this->CoordenadaY++;
        }
        else
        {
        }

        aux = aux->Siguiente;
        contador++;
    }
}


void Matriz::asignarProyecto(std::string nombre_empleado, std::string codigo_proyecto, std::string puesto)
{
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo_proyecto);
    NodoMatriz *nodo_Fila = this->buscarF_1(nombre_empleado);

    // Crear un nuevo objeto Empleado con los mismos atributos que el empleado original,
    // pero con el nuevo puesto.
    Empleado* nuevoEmpleado = new Empleado(nodo_Fila->Encargado_c->Nombre, nodo_Fila->Encargado_c->Password);
    nuevoEmpleado->Puesto = puesto;

    // Crear un nuevo nodo con el nuevo objeto Empleado.
    NodoMatriz *nuevo = new NodoMatriz(nodo_Columna->Proyecto_c, nuevoEmpleado, nodo_Columna->PosX, nodo_Fila->PosY);

    if(nodo_Columna != 0 && nodo_Fila !=0 )
    {
        nuevo = this->insertar_columna(nuevo, nodo_Fila);
        nuevo = this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
    else
    {
        cout << "Se produjo un error al insertar el nuevo nodo" << endl;
    }
}


NodoMatriz* Matriz::buscarF_1(std::string nombre)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->Encargado_c->Nombre.compare(nombre) == 0)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}

NodoMatriz* Matriz::buscarC_1(std::string codigo)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->Proyecto_c->Codigo.compare(codigo) == 0)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

void Matriz::BuscarProyecto(std::string codigo, std::string nombre_tarea){
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo);
    nodo_Columna->Tareas->Insertar(codigo,nombre_tarea,"");

}

void Matriz::BuscarEmpleado(std::string codigo, std::string nombre_tarea, std::string nombre_empleado){
    NodoMatriz *nodo_Columna =  this->buscarC_1(codigo);
    NodoMatriz *nodo_Fila = this->buscarF_1(nombre_empleado);
    if(nodo_Fila != 0){
        nodo_Columna->Tareas->Asignar(nodo_Columna->Proyecto_c->Codigo, nombre_tarea, nodo_Fila->Encargado_c->Codigo);
    }else{
        cout<<"No hay empleado con ese nombre"<<endl;
    }
}

void Matriz::Graficar()
{
    ofstream archivo;
    std::string texto = "";
	std::string nombre_archivo = "matriz.dot";
	std::string nombre_imagen = "matriz.jpg";
	NodoMatriz *aux1 = this->Raiz;
	NodoMatriz *aux2 = this->Raiz;
	NodoMatriz *aux3 = this->Raiz;
	archivo.open(nombre_archivo, ios::out);
	if ( aux1 != 0 ) {
		archivo << "digraph MatrizCapa{ \n node[shape=box] \n rankdir=UD;\n";
        /** Creacion de los nodos actuales */
        /*while( aux1 != 0 ) {
            archivo << "nodo" << (aux1->PosX+1) << (aux1->PosY+1) << "[label=\"" << aux1->Proyecto << "\" ,rankdir=LR,group=" << (aux1->PosX+1) << "]; \n";
            aux1 = aux1->Siguiente;
        }
        archivo << "}";*/
        while( aux2 != 0 ) {
            aux1 = aux2;
            archivo << "{rank=same; \n";
            while( aux1 != 0 ) {
                if(aux1->Proyecto_c)
                {
                    if(aux1->Encargado_c)
                    {
                        archivo << "nodo" << aux1 << "[label=\"" << aux1->Proyecto_c->Codigo << "\\n" << aux1->Encargado_c->Puesto << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                    }else{
                        archivo << "nodo" << aux1 << "[label=\"" << aux1->Proyecto_c->Nombre << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                    }
                }else if(aux1->Encargado_c)
                {
                    archivo << "nodo" << aux1 << "[label=\"" << aux1->Encargado_c->Nombre << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                }
                aux1 = aux1->Siguiente;
            }
            archivo << "} \n";
            aux2 = aux2->Abajo;
        }
        /** Conexiones entre los nodos de la matriz */
        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Siguiente != 0 ) {
                archivo << "nodo" << aux1 << " -> " << "nodo" << aux1->Siguiente << " [dir=both];\n";
                aux1 = aux1->Siguiente;
            }
            aux2 = aux2->Abajo;
        }
        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Abajo != 0 ) {
                archivo << "nodo" << aux1 << " -> " << "nodo" << aux1->Abajo << " [dir=both];\n";
                aux1 = aux1->Abajo;
            }
            aux2 = aux2->Siguiente;
        }
        archivo << "} \n";
	} else {
		texto = "No hay elementos en la matriz";
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


using json = nlohmann::json;

#include <iomanip>  // std::setw
#include <fstream>  // std::ofstream
#include <vector>  // std::vector
#include <utility>  // std::pair

void Matriz::generarJSON(Cola1 *cola, ListaDoble *lista)
{
  json j;
  j["Proyectos"] = json::array();

  NodoCola *colaAux = cola->Primero;

  while (colaAux) {
    json proyecto;
    proyecto["id"] = colaAux->Proyecto_C->Codigo;
    proyecto["nombre"] = colaAux->Proyecto_C->Nombre;
    proyecto["tareas"] = json::array();

    std::vector<std::pair<std::string, std::string>> tareas = lista->buscarTareasPorProyecto(colaAux->Proyecto_C->Codigo);
    for (const auto& tarea : tareas) {
      json tareaJson;
      tareaJson["nombre"] = tarea.first;
      tareaJson["empleado"] = tarea.second;
      proyecto["tareas"].push_back(tareaJson);
    }

    proyecto["prioridad"] = colaAux->Prioridad;
    j["Proyectos"].push_back(proyecto);
    colaAux = colaAux->Siguiente;
  }

  std::ofstream o("proyectos.json");
  o << std::setw(4) << j << std::endl;
  cout<<"JSON generado correctamente"<<endl;
}
