from dataTareas import *

class nodoListaSimple():
    def __init__(self, dato = None, siguiente = None):
        self.dato = dato
        self.siguiente = siguiente

class ListaSimple():
    def __init__(self):
        self.primero = None
        self.ultimo = None
        self.contador = 0

    def vaciar(self):
        return self.primero == None
    

    def agregar(self, dato):
        if self.vaciar():
            self.primero = self.ultimo = nodoListaSimple(dato = dato)
        else:
            aux = nodoListaSimple(dato)
            aux.siguiente = self.primero
            self.primero.anterior = aux
            self.primero = aux
        self.contador += 1


    def recorrer(self):
        aux = self.primero
        while aux != None:
            print(aux.dato)
            aux = aux.siguiente

    def size(self):
        return(self.contador)
    

    def limpiar(self):
        self.primero = None
        self.ultimo = None
        self.contador = 0


    def filtrar(self, empleado):
        aux = self.primero
        while aux != None:
            if aux.dato.getCodigoEncargado() == empleado:
                print(aux.dato.getIDTarea(),aux.dato.getIDProyecto(),aux.dato.getNombreTarea())
            aux = aux.siguiente