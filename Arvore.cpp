//
// Created by danilo on 06/04/17.
//

#include <cstdlib>
#include <iostream>
#include "Arvore.h"

Arvore::Arvore() {
    raiz= nullptr;
    nodos=0;
}

void Arvore::InsereRecursivo(node **raiz,int elemento) {
    if ((*raiz)== nullptr){
        (*raiz) = new node();
        (*raiz)->setElemento(elemento);
        (*raiz)->setDir(nullptr);
        (*raiz)->setEsq(nullptr);
        nodos++;
    }
    else {

        if ((*raiz)->getElemento()==elemento){
            return;
        }

        if ((*raiz)->getElemento()>elemento){
            InsereRecursivo(&((*(*raiz)).esq), elemento );
        }
        else {
            InsereRecursivo(&((*(*raiz)).dir), elemento );
        }
    }
}

void Arvore::Insere(int elemento) {
    InsereRecursivo(&raiz, elemento);
}

void Arvore::print() {
    printRecursivo(raiz,0);
}

void Arvore::printRecursivo(node *raiz,int nivel) {
    if (raiz!= nullptr){
        printRecursivo(raiz->esq,nivel+1);
        std::cout <<  (raiz->getElemento()) <<std::endl;
        printRecursivo(raiz->dir,nivel+1);
    }
}

int Arvore::Tamanho()  {
    return nodos;
}
int Arvore::pesquisa(int chave) {
    PesquisaReq(raiz,chave);

}

int Arvore::PesquisaReq(node *raiz, int chave) {
        if (raiz== nullptr){
            return -1;
        } else{
            if (raiz->getElemento()==chave){
                return  raiz->getElemento();
            }
            else{
                if (chave < raiz->getElemento()){
                    PesquisaReq(raiz->esq,chave);
                }
                else{
                    PesquisaReq(raiz->dir,chave);
                }
            }
        }
}

int Arvore::RetiraMaior() {
    node *anterior;
    return RetiraMaiorReq(raiz,anterior);
}

int Arvore::RetiraMaiorReq(node *raiz, node *anterior) {
    if (raiz==nullptr){
        return -1;
    }else{
        if (raiz->dir== nullptr){
            int value = raiz->getElemento();
            excluir(value);
            return value;
        }
        else {
            anterior=raiz;
            RetiraMaiorReq(raiz->dir,anterior);
        }
    }
}


int Arvore::maior(int a, int b) {
    if (a>b){
        return a;
    }
    else{
        return b;
    }

}
int Arvore::AlturaReq(node *raiz){
    if( (raiz== nullptr) || (raiz->esq== nullptr && raiz->dir== nullptr)){
        return 0;
    }
    else {
        return 1 + maior(AlturaReq(raiz->esq),AlturaReq(raiz->dir));
    }
}

int Arvore::Altura() {
    return AlturaReq(raiz);
}

bool Arvore::excluir(int elemento) {
    excluirReq(&raiz,elemento);
}

bool Arvore::excluirReq(node **raiz, int elemento) {
    /*
     * A função consiste em basicamente em percorrer a árvore, quando o elemento a ser retirado é encontrado, é verificado se o mesmo se encontra nos casos:
     * Nó folha: Apenas é removido e é retirada a referencia que o seu pai tem dele
     * Nó com um Filho: O nó pai é removido e tem seu nó filho associado ao nó onde o pai estava ligado
     * Nó com dois filhos: é buscado o filho Maior da sub-árvore direita, o mesmo é copiado para o local onde o nó a ser removido está, e o mesmo é removido
     * Já que se trata de um nó folha
    */
    node *aux ;
    if ((*raiz)== nullptr){
        return false;
    } else{
        if (elemento<(*raiz)->getElemento()){
            excluirReq(&(*raiz)->esq,elemento);
        }else{

        }if (elemento>(*raiz)->getElemento()){
            excluirReq(&(*raiz)->dir,elemento);
        }else {
            if ((*raiz)->getElemento()!=elemento)
                return false;
            if ((*raiz)->dir != nullptr && (*raiz)->esq != nullptr){
                aux = minimo((*raiz)->dir);
                //aux = MaiorDireita(&(*raiz)->esq);
                (*raiz)->setElemento(aux->getElemento());
                excluirReq(&(*raiz)->dir,(*raiz)->getElemento());
            }
            else{
                aux = *raiz;
                if ((*raiz)->esq== nullptr){
                    (*raiz) = (*raiz)->dir;
                }
                else{
                    (*raiz) = (*raiz)->esq;
                }
                nodos--;
                delete(aux);
            }
        }
    }
}

char *Arvore::setw(int nivel) {
    char *spaces = new char[nivel + 1];
    for (int i = 0; i < nivel; ++i) {
        spaces[i] = ' ';
    }
    spaces[nivel] = '\0';
    return spaces;
}





int Arvore::contaFolhasReq(node *raiz) {
    // Percorre toda a árvore, e sempre que encontra um elemento que tenha tanto os ponteiros dir quanto esq null incrementa 1
    if (raiz== nullptr){
        return 0;
    }
    if(raiz->esq== nullptr && raiz->dir == nullptr)
        return 1;
    return contaFolhasReq(raiz->dir) + contaFolhasReq(raiz->esq);
}

int Arvore::contaFolhas() {
    return contaFolhasReq(raiz);
}

int Arvore::nosInternos() {
    // Consiste basicamente na subtração da quantidade total de nós menos a quantidade de nós folhas.
    return  nodos - contaFolhasReq(raiz);
}



void Arvore::Destroy() {
    DestroyR(&raiz);
    std::cout << "Árvore Vazia" <<std::endl;
}

void Arvore::DestroyR(node **raiz) {
    if ((*raiz)== nullptr){
        return;
    }else{
        excluirReq(&(*raiz),(*raiz)->getElemento());
        DestroyR(&(*raiz));
    }
}

node *Arvore::minimo(node *raiz) { //Encontra o Menor Valor de uma árvore de entrada

    if (nodos==0){
        return nullptr;
    }else{
        if(raiz->esq== nullptr){
            return  raiz;
        }
        else {
            return minimo(raiz->esq);
        }
    }
}



