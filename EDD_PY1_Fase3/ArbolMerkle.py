from nodos import *
import hashlib
import os

class ArbolMerkle():
    def __init__(self):
        self.raiz_merkle = None
        self.bloque_datos = None #[]
        self.cantidad_bloques_datos = 0

    def AgregarBloque(self, empleado, pago, proyecto):
        nuevoRegistro = InformacionBloque(empleado, pago, proyecto)
        nuevoBloque = BloqueDeDatos(nuevoRegistro)
        if self.bloque_datos is None:
            self.bloque_datos = nuevoBloque
            self.cantidad_bloques_datos += 1
        else:
            aux = self.bloque_datos
            while aux.siguiente is not None:
                aux = aux.siguiente
            nuevoBloque.anterior = aux
            aux.siguiente = nuevoBloque
            self.cantidad_bloques_datos += 1
    
    def GenerarArbol(self):
        nivel = 1
        while 2**nivel < self.cantidad_bloques_datos:
            nivel += 1
        
        for i in range(self.cantidad_bloques_datos, 2**nivel):
            self.AgregarBloque(str(-i), 0, str(-i)) #3 - 4 (-3, 0, -3)

        self._GeneraHash()
        return self.raiz_merkle
    
    def _GeneraHash(self):
        arrayNodos = []
        aux = self.bloque_datos
        while aux is not None:
            encriptacion = self._encriptacionSHA3(aux.valor.empleado + aux.valor.fecha + str(aux.valor.pago) + aux.valor.proyecto)
            nodo_hoja = NodoMerkle(encriptacion)
            nodo_hoja.izquierda = aux
            arrayNodos.append(nodo_hoja)
            aux = aux.siguiente
        self.raiz_merkle = self._crearArbol(arrayNodos)

    def _crearArbol(self, arrayNodos):
        auxNodos = []
        root = None
        try:
            if len(arrayNodos) == 2:
                encrypt = self._encriptacionSHA3(arrayNodos[0].valor + arrayNodos[1].valor)
                root = NodoMerkle(encrypt)
                root.izquierda = arrayNodos[0]
                root.derecha = arrayNodos[1]  
                return root
            else:
                for i in range(0, len(arrayNodos), 2):
                    encrypt = self._encriptacionSHA3(arrayNodos[i].valor + arrayNodos[i+1].valor)
                    nodoRoot = NodoMerkle(encrypt)
                    nodoRoot.izquierda = arrayNodos[i]
                    nodoRoot.derecha = arrayNodos[i+1]
                    auxNodos.append(nodoRoot)
                return self._crearArbol(auxNodos)
        except:
            print("Me mori")

    def graficar(self, nombre):
        cadena = ''
        archivo = "arbolMerkle-" + nombre+".jpg"
        a = open("arbolMerkle.dot","w")
        if self.raiz_merkle is not None:
            cadena += "digraph arbol { node [shape=box];"
            cadena += self._retornarValoresArbol(self.raiz_merkle, 0)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg arbolMerkle.dot -o " + archivo)

    def _retornarValoresArbol(self, raiz, id):
        cadena = ''
        numero = id + 1
        if raiz is not None and isinstance(raiz, NodoMerkle):
            cadena += "\""
            cadena += raiz.valor[:20]
            cadena += "\" [dir=back];\n"
            if(raiz.izquierda is not None and raiz.derecha is not None):
                cadena += "\"{}\" -> {} \"{}\" -> {} ".format(raiz.valor[:20], self._retornarValoresArbol(raiz.izquierda, numero), raiz.valor[:20], self._retornarValoresArbol(raiz.derecha, numero))
                cadena += "{" + "rank=same" + "\"{}\" -> \"{}\" [style=invis]; ".format(raiz.izquierda.valor[:20], raiz.derecha.valor[:20]) + "} \n"
            elif(raiz.izquierda is not None and raiz.derecha is None and isinstance(raiz.izquierda, BloqueDeDatos)):
                cadena += "\"{}\" -> {}".format(raiz.valor[:20], self._retornarValoresArbol(raiz.izquierda, numero))
        elif raiz is not None and isinstance(raiz, BloqueDeDatos):
            cadena += "\""
            cadena += "{} \n {} \n {} \n {}".format(raiz.valor.fecha, raiz.valor.empleado, raiz.valor.pago, raiz.valor.proyecto)
            cadena += "\" [dir=back];\n"
        return cadena
    
    def _encriptacionSHA3(self, cadena):
        obj = hashlib.sha3_256()
        obj.update(cadena.encode('utf-8'))
        resultado = obj.hexdigest()
        return resultado #a15387bc