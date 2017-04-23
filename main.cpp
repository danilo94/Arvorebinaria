#include <iostream>
#include "Arvore.h"
#include "Buscabinaria.h"

using namespace std;

void menu();
void menuArvore();
void menuBuscaBinaria();

int main() {
    srand(time(nullptr));
 //   menu();
    Buscabinaria b1(10);
    b1.populaVetor();
    cout << b1.Riddle();

    return 0;
}



void menu(){
    Arvore *arvore1;
    cout << "Trabalho Prático de implementação 2 " << " Danilo Damião de Almeida " << " Matrícula: 94932 " << endl;
    cout << "Por Favor, Selecione o código do trabalho que deseja testar"<< endl <<"1 - Árvore Binária "<<endl<<"2 - Busca Binária"<<endl;
    int sel;
    cin >> sel;

    switch(sel){
        case 1:
            menuArvore();
            break;
        case 2:
            menuBuscaBinaria();
            break;
        default:
            cout << "Opção Inválida !!!" << endl;
            break;
    }
}


void menuArvore(){
    Arvore *arvore = new Arvore();
    do {
        cout << "Selecione a Operação Desejada:" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover Item" << endl;
        cout << "3 - Pesquisar Item" << endl;
        cout << "4 - Altura" << endl;
        cout << "5 - Folhas" << endl;
        cout << "6 - Remover Maior" << endl;
        cout << "7 - Tamanho" << endl;
        cout << "8 - Destruir Árvore" << endl;
        cout << "9 - Mostrar Árvore" << endl;
        cout << "10 - Fechar Programa" << endl;
        int sel;
        int dado;
        cin >> sel;
        switch (sel) {
            case 1:
                cout << "Digite o item que deseja Inserir na árvore";
                cin >> dado;
                arvore->Insere(dado);
                break;
            case 2:
                cout << "Digite o item que deseja Remover na árvore";
                cin >> dado;
                arvore->excluir(dado);
                break;
            case 3:
                cout << "Digite o item que deseja Pesquisar na árvore";
                cin >> dado;
                arvore->pesquisa(dado);
                break;
            case 4:
                cout << "A altura da árvore é: " << arvore->Altura() << endl;
                break;
            case 5:
                cout << "A quantidade de folhas da árvore é: " << arvore->contaFolhas() << endl;
                break;
            case 6:
                cout << "O maior elemento removido foi: " << arvore->RetiraMaior() << endl;
                break;
            case 7:
                cout << "O Tamanho da árvore é: " << arvore->Tamanho() << endl;
                break;
            case 8:
                arvore->Destroy();
                cout << "Arvore Destruida" << endl;
                break;
            case 9:
                arvore->print();
                break;
            case 10:
                exit(0);
                break;
        }
    }while(1);


}

void menuBuscaBinaria(){
    cout << "Digite a Quantidade de Elementos no vetor:";
    int elementos;
    cin >> elementos;
    Buscabinaria *estrutura = new Buscabinaria(elementos);

    do{
        cout << "Selecione a Operação Desejada:" << endl;
        cout << "1 - Popular Vetor" << endl;
        cout << "2 - Executar Busca Binária Recursiva" << endl;
        cout << "3 - Executar Busca Binária Iterativa" << endl;
        cout << "4 - Mostrar Vetor" << endl;
        cout << "5 - Ordenar Vetor" << endl;
        cout << "6 - Sair" << endl;
        int opt;
        cin >> opt;

        switch (opt){
            case 1:
                estrutura->populaVetor();
                break;
            case 2:
                cout << "Digite o valor do elemento" << endl;
                cin >> elementos;
                cout << "A chave de saida é: " << estrutura->Busca(elementos,1)<< endl;
                break;
            case 3:
                cout << "Digite o valor do elemento" << endl;
                cin >> elementos;
                cout << "A chave de saida é: " << estrutura->Busca(elementos,2)<< endl;
                break;
            case 4:
                estrutura->printVetor();
                break;
            case 5:
                estrutura->ordenaVetor();
                break;
            case 6:
                exit(0);
                break;
        }


    }while(1);


}