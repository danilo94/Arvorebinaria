//
// Created by danilo on 06/04/17.
//

#ifndef ARVOREBINARIA_NODE_H
#define ARVOREBINARIA_NODE_H


class node {
private:
    int elemento;

public:
    node *esq;
    node *dir;
    node();
    int getElemento() const;



    void setElemento(int elemento);

    node *getEsq() const;

    void setEsq(node *esq);

    node *getDir() const;

    void setDir(node *dir);
};


#endif //ARVOREBINARIA_NODE_H
