//
//  NV_linAlg.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 11/04/18.
//
#include <iostream>
using namespace std;
double** matrix_product(double** Matrix_A,double** Matrix_B,int* Dim_A,int* Dim_B){
    double **Producto = new double*[Dim_A[0]];
    for(int i=0;i<Dim_A[0];i++){
        Producto[i] = new double[Dim_B[1]];
    }
    for(int i=0; i<Dim_A[0];i++){
        for(int j=0;j<Dim_B[1];j++){
            int Element=0;
            for(int k=0;k<Dim_B[0];k++){
                Element+=Matrix_A[i][k]*Matrix_B[k][j];
            }
            Producto[i][j]=Element;
            cout<<Producto[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    return Producto;
}
double** get_Matrix(int Filas, int Columnas){
    double **Matrix = new double*[Filas];
    for(int i=0;i<Filas;i++){
        Matrix[i] = new double[Columnas];
    }
    for(int i=0; i<Filas;i++){
        for(int j=0;j<Columnas;j++){
            cout<<"Ingrese el Elemento"<<i<<","<<j<<endl;
            double var;
            cin>>var;
            Matrix[i][j]=var;
        }
    }
    cout<<"La matriz ingresada fue:"<<endl;
    for(int i=0; i<Filas;i++){
        for(int j=0;j<Columnas;j++){
            cout<<Matrix[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    return Matrix;
}
int* Dimensions(){
    int *Dim = new int[2];
    cout<<"Ingrese el Número de filas"<<endl;
    int Filas;
    cin>>Filas;
    cout<<"Ingrese el Número de columnas"<<endl;
    int Columnas;
    cin>>Columnas;
    Dim[0]=Filas;
    Dim[1]=Columnas;
    return Dim;
}
int main(){
    // matriz
    cout<<"Ingrese la Dimensiones de la Matriz A"<<endl;
    int* DimA=Dimensions();
    cout<<"Ingrese los elementoss de la Matriz A"<<endl;
    double **A=get_Matrix(DimA[0], DimA[1]);
    cout<<"Ingrese la Dimensiones de la Matriz B"<<endl;
    int*DimB=Dimensions();
    cout<<"Ingrese los elementoss de la Matriz B"<<endl;
    double **B=get_Matrix(DimA[0], DimA[1]);
    cout<<"El producto entre A y B es:"<<endl;
    double **P=matrix_product(A,B,DimA,DimB);
    return 0;
}
