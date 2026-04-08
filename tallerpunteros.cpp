#include <iostream>
using namespace std;
//1.funcion de intercambio 
void intercambiar(double *a,double *b){
    double temp =*a;
    *a =*b;
    *b =temp;
}
//2.suma de arreglo
int sumaArreglo(int *arreglo,int n){
    int suma =0;
    for(int i=0;i<n;i++){
        suma +=*(arreglo+i);
    }
    return suma;
}
//3. encontrar el mayor
int mayor(int *arreglo,int n){
    if(n == 0){
        cout << "Arreglo vacio\n";
        return 0;
    }
    int max =*arreglo;
    for(int i=0;i<n;i++){
        if(*(arreglo + i) > max){
            max = *(arreglo + i);
        }
    }
    return max;
}
//4. aplicacion de funcion al arreglo
int duplicar(int x){
    return x*2;
}
int triplicar(int x){
    return x*3;
}
// funcion con puntero a la funcion
void aplicar(int *arreglo, int n, int (*func)(int)){
    for(int i = 0; i < n; i++){
        *(arreglo + i) = func(*(arreglo + i));
    }
}
//5. matriz dinamica y punteros
void llenarMatriz(int **matriz,int filas,int columnas){
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<"elemento numero ["<<i<<"]["<<j<<"]:";
            cin>>matriz[i][j];
        }
    }
}
void sumaFilas(int **matriz,int filas,int columnas){
    for(int i=0;i<filas;i++){
        int suma=0;
        for(int j=0;j<columnas;j++){
            suma +=matriz[i][j];
        }
        cout<<"la suma de la fila es: "<<i<<" es: "<<suma<<endl;
    }
}
//5. casting de punteros o memoria
void verEntero(int *p){
    cout<<"Valor como entero: "<<*p<<endl;
}
void verBytes(char *p){
    cout<<"Bytes: ";
    for(int i=0;i<sizeof(float);i++){
        cout<<(int)*(p+i)<<" ";
    }
    cout<<endl;
}
//el main
int main(){
    //1. intercambio 
    double x,y;
    cout<<"Ingrese dos numeros: ";
    cin >>x>>y;
    intercambiar(&x, &y);
    cout << "Intercambiados: " << x << " " << y << endl;
    //2. suma de arreglo
    cout<<"\nPunto 2\n";
    int n;
    cout<<"Tamano del arreglo: ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n;i++){
        cout<<"Dato "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"Suma: "<<sumaArreglo(arr, n)<<endl;
    //3. mayor del arreglo
    cout<<"\nPunto 3\n";
    cout<<"Mayor: "<<mayor(arr, n)<<endl;
    //4. aplicar funcion al arreglo
    cout<<"\nPunto 4\n";
    aplicar(arr,n,duplicar);
    cout << "Duplicado:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //5. matriz dinamica
    cout<<"\nPunto 5 (matriz)\n";
    int filas,columnas;
    cout<<"Filas: ";
    cin>>filas;
    cout<<"Columnas: ";
    cin>>columnas;
    int **mat=new int*[filas];
    for(int i=0;i<filas;i++){
        mat[i]=new int[columnas];
    }
    llenarMatriz(mat,filas,columnas);
    sumaFilas(mat,filas,columnas);
    // liberar memoria
    for(int i=0;i<filas;i++){
        delete[] mat[i];
    }
    delete[] mat;
    //5. casting de punteros
    cout<<"\nPunto 5 (casting)\n";
    float num;
    cout<<"Ingrese un float: ";
    cin>>num;
    int *pInt=(int*)&num;
    char *pChar=(char*)&num;
    cout<<"Direccion float: "<<&num<<endl;
    cout<<"Direccion int*: "<<pInt<<endl;
    verEntero(pInt);
    verBytes(pChar);
    // liberar arreglo
    delete[] arr;
    return 0;
}
