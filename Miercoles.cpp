#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;
//provisiona una matrix de tamano nxn
char** createMatrix(int);
//libera la memoria de una matrix nxn
void deleteMatrix(char**,int);

//imprime la matriz
void printMatrix(char**,int);

int main(){
  
  srand(time(NULL));

  int random=rand()%255;
  cout<<random<<endl;
  char** charMatrix;
  int size;
  cout<< "Ingrese el tamano de la matriz:";
  cin>> size; 

  charMatrix = createMatrix(size);

  deleteMatrix(charMatrix,size);
  
  return 0;

}

void printMatrix(char** matrix,int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<" "<< matrix[i][j];
    }
    cout<<endl;
  }
}

void deleteMatrix(char** matrix,int size){
  for(int i=0;i<size;i++){
    delete[] matrix[i];
    matrix[i]=NULL;
  }

  delete[] matrix;

}
//probando
char**createMatrix(int size){
  char** retVal= new char*[size];

  for(int i=0;i<size;i++)
    retVal[i]=new char[size];

  return retVal;
}
