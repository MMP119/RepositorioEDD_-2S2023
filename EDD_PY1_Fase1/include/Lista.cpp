#include "Lista.h"

Lista::Lista()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

Lista::~Lista()
{
    //dtor
}

//Primero se coloca el tipo de la funcion, luego a que clase pertenece, nombre
void Lista::Insertar(std::string nombre, std::string password)
{
    NodoLista *nuevo = new NodoLista(nombre, password);
    int numero_empleado = 1 + this->Tamanio;
    std::string codigo = (numero_empleado < 100 ? (numero_empleado < 10 ? "SC-00"+std::to_string(numero_empleado) : "SC-0"+std::to_string(numero_empleado)): "SC-"+std::to_string(numero_empleado));
    nuevo->EmpleadoSistema->Codigo = codigo;
    if(this->Primero == 0)
    {
        /*------------------*/
        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        /*Nos volamos esto*/
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoLista *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;//No existe en doble enlazada
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo; //No exites ne doble enlazada
        this->Tamanio++;
    }
}

void Lista::VerLista()
{
    NodoLista *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->EmpleadoSistema->Codigo << ". " <<aux->EmpleadoSistema->Nombre<< endl;
        aux = aux->Siguiente;
        contador++;
    }
}


void Lista::VerLista1()
{
    NodoLista *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->EmpleadoSistema->Puesto << ". " <<aux->EmpleadoSistema->Nombre<< endl;
        aux = aux->Siguiente;
        contador++;
    }
}

std::string Lista::BuscarPorCodigo(const std::string& codigo)
{
    if(this->Tamanio == 0)
    {
        return "Lista vacía";
    }

    NodoLista *aux = this->Primero;
    int contador = 0;

    do
    {
        if(aux->EmpleadoSistema->Codigo == codigo)
        {
            return aux->EmpleadoSistema->Nombre;
        }
        aux = aux->Siguiente;
        contador++;
    }
    while(contador < this->Tamanio);

    return "Empleado no encontrado";
}


void Lista::LeerArchivo(std::string nombre_archivo)
{
    try
    {
        ifstream lectura;
        lectura.open(nombre_archivo, ios::in);
        bool encabezado = false;
        for(std::string fila; std::getline(lectura,fila);)
        {
            std::stringstream lineas(fila);
            std::string nombre;
            std::string password;
            if(encabezado)
            {
                getline(lineas, nombre, ',');
                getline(lineas, password, ',');
                this->Insertar(nombre, password);
            }
            else{
                encabezado = true;
            }

        }
        cout <<"Carga Exitosa..."<<endl;
    }
    catch(exception)
    {
        cout << "No se pudo leer el archivo" << endl;
    }
}

void Lista::Graficar()
{
    ofstream archivo;
    std::string nombre_archivo = "lista_circular.dot";
    std::string nombre_imagen = "lista_circular.png";
    NodoLista *aux = this->Primero;

    archivo.open(nombre_archivo, ios::out);
    if (this->Tamanio > 0) {
        archivo << "digraph listaCircularGraph { \n node[shape=box]; \n";

        int contador = 0;
        do {
            archivo << "nodoLista" << contador << "[label=\"" << aux->EmpleadoSistema->Codigo << "\\nNombre: " << aux->EmpleadoSistema->Nombre << "\\nPassword: " << aux->EmpleadoSistema->Password <<"\"]; \n";
            aux = aux->Siguiente;
            contador++;
        } while (aux != this->Primero);

        archivo << "\n";

        aux = this->Primero;
        NodoLista *aux1 = aux->Siguiente;
        contador = 0;
        int contador1 = 1;

        do {
            archivo << "nodoLista" << contador << " -> " << "nodoLista" << contador1 << ";\n";
            archivo << "nodoLista" << contador1 << " -> " << "nodoLista" << contador << ";\n";
            aux = aux->Siguiente;
            aux1 = aux1->Siguiente;
            contador++;
            contador1 = (contador1 + 1) % this->Tamanio;
        } while (aux != this->Primero);

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
