from nodoB import NodoB

class RamaB():
    def __init__(self):
        self.primero:NodoB = None
        self.hoja = True
        self.contador = 0

    def insertar(self, nuevo):
        if self.primero is None:
            self.primero = nuevo
            self.contador += 1
        else:
            if nuevo.valor < self.primero.valor:
                nuevo.siguiente = self.primero
                if self.primero is not None:
                    self.primero.anterior = nuevo
                    self.primero.izquierda = nuevo.derecha
                self.primero = nuevo
            else:
                actual = self.primero 
                while actual.siguiente is not None and actual.siguiente.valor < nuevo.valor:
                    actual = actual.siguiente 
                nuevo.siguiente = actual.siguiente
                if actual.siguiente is not None:
                    actual.siguiente.anterior = nuevo
                actual.siguiente = nuevo
                nuevo.anterior = actual
            self.contador += 1