#include <iostream>
#include <fstream>
using namespace std;

//provisiona la matriz de chars para el laberinto
char** provisionalMatrix(int);

//liberar memoria de la matriz
void liberarMatriz(char**,int);

//imprimir la matriz
void printMatriz(char**,int);

//salir del laberinto: lab, size, x, y
bool salir(char**,int,int,int);

int main(){
  //abrir el archivo
  ifstream file("laberinto.txt");

  int size=0;
  char** labMatrix=NULL;
  //si el archivo existe
  if(file.is_open() ){
    //leer el tamano
    file >> size ;
    //inicializa la matriz nxn
    labMatrix=provisionalMatrix(size);
    //leer la matriz del archivo
    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
        file >> labMatrix[i][j];
     
    

    file.close();
    printMatriz(labMatrix,size);

    liberarMatriz(labMatrix,size);

  }
  return 0;
}//end main

void printMatriz(char** matrix,int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<" "<< matrix[i][j];
    }
    cout<<endl;
  }
}

void liberarMatriz(char** matrix,int size){
  for(int i=0;i<size;i++){
    delete[] matrix[i];
    matrix[i]=NULL;
  }
  delete[] matrix;
}

char** provisionalMatrix(int size){
  char** retVal= new char*[size];
  for(int i=0;i<size;i++)
    retVal[i]=new char[size];
  return retVal;
}



