//
// Created by danilo on 08/04/17.
//

#include <iostream>
#include "Buscabinaria.h"

Buscabinaria::Buscabinaria(int size) {
    vetor = new int[size];
    this->tam = size;
    isOrdenado=false;
    isCheio=false;
}

void Buscabinaria::populaVetor() {
    srand(time(nullptr));
    vetor[0]=20;
    for (int i=1; i<tam; i++){
        vetor[i] = rand()%tam*2+30;
    }
    isCheio=true;
    isOrdenado=false;
}


int Buscabinaria::Particiona(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int j,valor;
    j = inicio;

    for (int i= inicio; i<fim; i++){
        if (vetor[i]<pivo){
            valor = vetor[i];
            vetor[i] = vetor[j];
            vetor[j]=valor;
            j++;
        }
    }
    if (pivo <=vetor[j]){
        vetor[fim]=vetor[j];
        vetor[j] = pivo;
    }
    return j;
}
void Buscabinaria::QuicksortTotal(int *vetor,int inicio,int fim){
    if (inicio>=fim){
        isOrdenado=true;
        return;
    }
    else {
        int Pivo = Particiona(vetor,inicio,fim);
        QuicksortTotal(vetor,inicio,Pivo-1);
        QuicksortTotal(vetor,Pivo+1,fim);
    }
}

void Buscabinaria::ordenaVetor() {
    if (!isOrdenado){
        QuicksortTotal(vetor,0,tam);
    }
}

void Buscabinaria::printVetor(){
    if (isCheio){
        for (int i=0; i<tam; i++) {
            std::cout << vetor[i] << " ";
        }
        cout << endl;
    }

}

int Buscabinaria::BuscaIt(int elemento) {
    if (!isOrdenado)
        return -1;
    int limiteInferior = 0;
    int limiteSup = tam-1;
    int meio;
    while (limiteInferior<=limiteSup){
        meio = (limiteInferior+limiteSup)/2;
        if (elemento == vetor[meio])
            return meio;
        if (elemento<vetor[meio])
            limiteSup=meio-1;
        else
            limiteInferior = meio+1;
    }
    return -1;
}

int Buscabinaria::BuscaBinReq(int *vetor, int elemento,int inicio,int tam) {
    if (!isOrdenado){
        return -1;
    }
    int meio = (inicio + tam)/2;
    if (elemento == vetor[meio]){
        return meio;
    }

    if (elemento>vetor[meio]){
        BuscaBinReq(vetor,elemento,meio+1,tam);
    }
    else{
        BuscaBinReq(vetor,elemento,inicio,meio-1);
    }

}

int Buscabinaria::Busca(int elemento,int tipoBusca) {
    switch (tipoBusca){
        case 1:
            cout << "Busca Binária Recursiva Selecionada" << endl;
            return BuscaBinReq(vetor,elemento,0,tam);
            break;
        case 2:
            cout << "Busca Binária Iterativa Selecionada" << endl;
           return BuscaIt(elemento);
            break;
        default:
            cout << "Opção Inválida" << endl;
            return -1;
            break;
    }
}
