//
// Created by danilo on 06/04/17.
//

#include "node.h"

node *node::getEsq() const {
    return esq;
}

void node::setEsq(node *esq) {
    node::esq = esq;
}

node *node::getDir() const {
    return dir;
}

void node::setDir(node *dir) {
    node::dir = dir;
}

int node::getElemento() const {
    return elemento;
}

void node::setElemento(int elemento) {
    node::elemento = elemento;
}

node::node() {

}


