//
// Created by danilo on 06/04/17.
//

#ifndef ARVOREBINARIA_ARVORE_H
#define ARVOREBINARIA_ARVORE_H


#include "node.h"

class Arvore {
private:
    node *raiz;
    int nodos;
    void InsereRecursivo(node **raiz,int elemento);
    void printRecursivo(node *raiz,int nivel);
    int PesquisaReq(node* raiz, int chave);
    int RetiraMaiorReq(node *, node*);
    int AlturaReq(node *);
    bool excluirReq(node **raiz, int elemento);
    int maior(int,int);
    int contaFolhasReq(node *raiz);
    char *setw(int);
    void DestroyR(node **raiz);
    node *minimo(node *raiz);

public:
    bool excluir(int elemento);
    int RetiraMaior();
    Arvore();
    void Insere(int elemento);
    int pesquisa(int chave);
    void print();
    int Altura();
    int Tamanho();
    int contaFolhas();
    int nosInternos();
    void Destroy();
};


#endif //ARVOREBINARIA_ARVORE_H
