#include <iostream>
using namespace std;

// funcion de intercambio
void intercambiar(int *primerNumero, int *segundoNumero){
    int valorTemporal = *primerNumero;
    *primerNumero = *segundoNumero;
    *segundoNumero = valorTemporal;
}

// suma del arreglo donde estan guardados los punteros
int sumaArreglo(int *punteroArreglo, int cantidadElementos){
    int sumaTotal = 0;
    for(int indice = 0; indice < cantidadElementos; indice++){
        sumaTotal += *(punteroArreglo + indice);
    }
    return sumaTotal;
}

// encontrar el mayor numero guardado en los distintos punteros
int mayor(int *punteroArreglo, int cantidadElementos){
    if(cantidadElementos == 0){
        cout << "Puntero vacio\n";
        return 0;
    }
    int valorMaximo = *punteroArreglo;
    for(int indice = 0; indice < cantidadElementos; indice++){
        if(*(punteroArreglo + indice) > valorMaximo){
            valorMaximo = *(punteroArreglo + indice);
        }
    }
    return valorMaximo;
}

// funciones para el callback (funcion q se ejecutara despues q la tarea se complete)
int duplicar(int valorOriginal){
    return valorOriginal * 2;
}
int triplicar(int valorOriginal){
    return valorOriginal * 3;
}

void aplicar(int *punteroArreglo, int cantidadElementos, int (*operacion)(int)){
    for(int indice = 0; indice < cantidadElementos; indice++){
        *(punteroArreglo + indice) = operacion(*(punteroArreglo + indice));
    }
}

// matriz para mostrar la impresion de los punteros
void llenarMatriz(int **punteroMatriz, int cantidadFilas, int cantidadColumnas){
    for(int indiceFila = 0; indiceFila < cantidadFilas; indiceFila++){
        for(int indiceColumna = 0; indiceColumna < cantidadColumnas; indiceColumna++){
            cout << "elemento [" << indiceFila << "][" << indiceColumna << "]: ";
            cin >> *(*(punteroMatriz + indiceFila) + indiceColumna);
        }
    }
}

void sumaFilas(int **punteroMatriz, int cantidadFilas, int cantidadColumnas){
    for(int indiceFila = 0; indiceFila < cantidadFilas; indiceFila++){
        int sumaPorFila = 0;
        for(int indiceColumna = 0; indiceColumna < cantidadColumnas; indiceColumna++){
            sumaPorFila += *(*(punteroMatriz + indiceFila) + indiceColumna);
        }
        cout << "Suma de la fila " << indiceFila << ": " << sumaPorFila << endl;
    }
}

// Seleccion de punteros
void verEntero(int *punteroEntero){
    cout << "Valor al entero: " << *punteroEntero << endl;
}

void verBytes(char *punteroByte){
    cout << "Bytes: ";
    for(int indiceByte = 0; indiceByte < sizeof(float); indiceByte++){
        cout << (int)*(punteroByte + indiceByte) << " ";
    }
    cout << endl;
}

int main(){
    // intercambio
    int primerValor, segundoValor;
    cout << "Ingrese dos numeros enteros: ";
    cin >> primerValor >> segundoValor;
    intercambiar(&primerValor, &segundoValor);
    cout << "Intercambiados: " << primerValor << " " << segundoValor << endl;

    // suma del arreglo donde estan guardados los punteros
    cout << "\nPunto 2\n";
    int cantidadElementos;
    cout << "Tamano del arreglo: ";
    cin >> cantidadElementos;
    int *arregloDinamico = new int[cantidadElementos];
    for(int indice = 0; indice < cantidadElementos; indice++){
        cout << "Dato " << indice << ": ";
        cin >> *(arregloDinamico + indice);
    }
    cout << "Suma: " << sumaArreglo(arregloDinamico, cantidadElementos) << endl;

    // encontrar el mayor numero guardado en los distintos punteros
    cout << "\nPunto 3\n";
    cout << "Mayor: " << mayor(arregloDinamico, cantidadElementos) << endl;

    // aplicar funcion al arreglo la cual se ejecutara despues q la tarea se complete
    cout << "\nPunto 4\n";
    aplicar(arregloDinamico, cantidadElementos, duplicar);
    cout << "Arreglo duplicado:\n";
    for(int indice = 0; indice < cantidadElementos; indice++){
        cout << *(arregloDinamico + indice) << " ";
    }
    cout << endl;

    // matriz para mostrar la impresion de los punteros
    cout << "\nPunto 5 (matriz)\n";
    int cantidadFilas, cantidadColumnas;
    cout << "Filas: ";
    cin >> cantidadFilas;
    cout << "Columnas: ";
    cin >> cantidadColumnas;
    int **matrizDinamica = new int*[cantidadFilas];
    for(int indiceFila = 0; indiceFila < cantidadFilas; indiceFila++){
        *(matrizDinamica + indiceFila) = new int[cantidadColumnas];
    }
    llenarMatriz(matrizDinamica, cantidadFilas, cantidadColumnas);
    sumaFilas(matrizDinamica, cantidadFilas, cantidadColumnas);
    for(int indiceFila = 0; indiceFila < cantidadFilas; indiceFila++){
        delete[] *(matrizDinamica + indiceFila);
    }
    delete[] matrizDinamica;

    // Seleccion de punteros
    cout << "\nPunto 5 (seleccion )\n";
    float numeroFlotante;
    cout << "Ingrese su numero flotante: ";
    cin >> numeroFlotante;
    int  *punteroComoEntero = (int*)  &numeroFlotante;
    char *punteroComoByte   = (char*) &numeroFlotante;
    cout << "Direccion del numero flotante: " << &numeroFlotante     << endl;
    cout << "Direccion int*:  " << punteroComoEntero   << endl;
    verEntero(punteroComoEntero);
    verBytes(punteroComoByte);

    delete[] arregloDinamico;
    return 0;
}
