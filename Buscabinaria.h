

#ifndef ARVOREBINARIA_BUSCABINARIA_H
#define ARVOREBINARIA_BUSCABINARIA_H
#include <cstdlib>
#include <time.h>

using namespace std;

class Buscabinaria {
private:
    int *vetor;
    int tam;
    bool isOrdenado;
    bool isCheio;
    int Particiona(int *,int,int);
    void QuicksortTotal (int *,int,int);
    int BuscaBinReq(int *,int elemento,int inicio,int fim);
    int BuscaIt(int elemento);
public:
    Buscabinaria(int size);
    void populaVetor();
    void ordenaVetor();
    void printVetor();
    int Busca(int,int);
};


#endif //ARVOREBINARIA_BUSCABINARIA_H
