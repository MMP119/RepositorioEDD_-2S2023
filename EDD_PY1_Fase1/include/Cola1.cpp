#include "Cola1.h"

Cola1::Cola1()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

Cola1::~Cola1()
{
    //dtor
}

void Cola1::Encolar(std::string Nombre, std::string Tipo_de_Prioridad)
{
    int numero_proyecto = 100 + this->Tamanio;
    Proyecto *nuevoProyecto = new Proyecto("PY-"+std::to_string(numero_proyecto),Nombre);
    NodoCola *nuevoNodo = new NodoCola(nuevoProyecto,Tipo_de_Prioridad);
    if(this->Primero == 0)
    {
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{
        NodoCola *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }
    //cout <<"PY-"+std::to_string(numero_proyecto)<<endl;
}


void Cola1::Ordenar(){
    if(this->Primero){
        NodoCola *piv = this->Primero;
        NodoCola *actual;
        int  contador = 0;
        while (contador != this->Tamanio){
            actual = piv->Siguiente;
            while(actual){
                if(piv->Prioridad.compare(actual->Prioridad) == 1){
                    Proyecto *tempProyecto = piv->Proyecto_C;
                    std::string tempPrioridad = piv->Prioridad;
                    piv->Proyecto_C = actual ->Proyecto_C;
                    piv->Prioridad = actual->Prioridad;
                    actual->Proyecto_C = tempProyecto;
                    actual->Prioridad = tempPrioridad;
                }
                actual = actual->Siguiente;
            }
            piv = piv->Siguiente;
            contador++;
        }
    }

}


bool Cola1::VerProyectos()
{
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux)
    {
        cout << aux->Proyecto_C->Codigo << ". " << aux->Proyecto_C->Nombre << endl;
        aux = aux->Siguiente;
        contador++;
    }
    return contador > 0;
}

void Cola1::Descolar()
{
    if(this->Primero)
    {
        this->Primero = this->Primero->Siguiente;
    }
}

void Cola1::Graficar()
{
    ofstream archivo;
    std::string texto = "";
    std::string nombre_archivo = "cola.dot";
    std::string nombre_imagen = "cola.png";
    NodoCola *aux = this->Primero;
    NodoCola *aux1 = aux->Siguiente;


    archivo.open(nombre_archivo, ios::out);
    if ( aux != 0 ) {


        archivo << "digraph colaGraph{ \n node[shape=box] \n rankdir=LR;\n";


        while( aux != 0 ) {
            archivo << "nodoCola" << &(aux->Proyecto_C->Codigo ) << "[label=\"" << aux->Proyecto_C->Codigo << "\\nPrioridad: " << aux->Prioridad << "\"]; \n";
            aux = aux->Siguiente;
        }
        archivo << "\n\n";


        /** Conexiones entre los nodos de la matriz */



        //NodoCola *aux = this->Primero;
        aux = this->Primero;
        while( aux != 0  ) {
            archivo << "nodoCola" << &(aux->Proyecto_C->Codigo ) << " -> " << "nodoCola" << &(aux1->Proyecto_C->Codigo ) << "\n";
            aux = aux->Siguiente;


            if (aux1->Siguiente == 0) {
                archivo << "nodoCola" << &(aux->Proyecto_C->Codigo ) << " -> " << "Null \n";
                break;
            }
            aux1 = aux1->Siguiente;


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


std::string Cola1::buscarPrioridadPorID(std::string codigoProyecto) {
  NodoCola *aux = this->Primero;
  while (aux) {
    if (aux->Proyecto_C->Codigo == codigoProyecto) {
      return aux->Prioridad;
    }
    aux = aux->Siguiente;
  }
  return "";  // Return an empty string if the project code is not found
}
