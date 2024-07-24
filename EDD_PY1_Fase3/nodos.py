import datetime
def fechaactual():
    fecha_hora_actual = datetime.datetime.now()
    fecha_formato = fecha_hora_actual.strftime("%d-%m-%Y::%H:%M:%S") #27-10-2023::11:30:50
    return fecha_formato

class NodoMerkle():
    def __init__(self, valor):
        self.izquierda = None
        self.derecha = None
        self.valor = valor

class NodoBloque():
    def __init__(self, index, fecha, data, previoushash, hash) -> None:
        self.siguiente = None
        self.anterior = None
        self.valor = {
            'index': index,
            'timestamp': fecha,
            'data': data,
            'previoushash':previoushash,
            'hash': hash
        }


class BloqueDeDatos():
    def __init__(self, valor):
        self.siguiente = None
        self.anterior = None
        self.valor = valor

class InformacionBloque():
    def __init__(self, empleado, pago, proyecto):
        self.empleado = empleado
        self.pago = pago
        self.proyecto = proyecto
        self.fecha = fechaactual()