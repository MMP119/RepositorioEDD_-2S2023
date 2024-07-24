#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

ColaPrioridad::~ColaPrioridad()
{
    //dtor
}

void ColaPrioridad::Encolar(std::string Nombre, std::string Tipo_de_Prioridad)
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
    cout <<"PY-"+std::to_string(numero_proyecto)<<endl;
}


void ColaPrioridad::Ordenar(){
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


bool ColaPrioridad::VerProyectos()
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

void ColaPrioridad::Descolar()
{
    if(this->Primero)
    {
        this->Primero = this->Primero->Siguiente;
    }
}

/*
ColaPrioridad* ColaPrioridad::Clonar()
{
    ColaPrioridad *nuevaCola = new ColaPrioridad(); // Crear una nueva cola vacía
    NodoCola *aux = this->Primero; // Comenzar desde el primer elemento de la cola original

    while(aux)
    {
        // Copiar exactamente los mismos datos, incluido el código del proyecto
        Proyecto *nuevoProyecto = new Proyecto(aux->Proyecto_C->Codigo, aux->Proyecto_C->Nombre);
        NodoCola *nuevoNodo = new NodoCola(nuevoProyecto, aux->Prioridad);

        if(nuevaCola->Primero == 0)
        {
            nuevaCola->Primero = nuevoNodo;
            nuevaCola->Tamanio++;
        }
        else
        {
            NodoCola *auxNuevaCola = nuevaCola->Primero;
            while(auxNuevaCola->Siguiente)
            {
                auxNuevaCola = auxNuevaCola->Siguiente;
            }
            auxNuevaCola->Siguiente = nuevoNodo;
            nuevaCola->Tamanio++;
        }

        aux = aux->Siguiente; // Avanzar al siguiente elemento en la cola original
    }

    return nuevaCola; // Devolver la nueva cola
}
*/

void ColaPrioridad::Graficar()
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
