
//* 6) Criar uma implementação do TAD Pilha para o tipo ‘int’, chamada PilhaMin,
//* que oferece os métodos do TAD e também o método obterMinimo(), que retorna o
//* menor elemento da pilha. O método obterMinimo() deve operar em tempo
//* constante.

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_

#include <lista-teorica-estruturas-lineares/PilhaTAD.hpp>

class No {
 public:
  int dado;
  No* prox;
};

class PilhaMin {
 public:
  // incluir variáveis necessárias
  No* ultimo;
  int N;

  int topo() { return this->ultimo->dado; }
  int tamanho();
  int desempilha();
  void empilha(int t);
  int obterMinimo();

  // mais métodos auxiliares
  void cria() {
    this->ultimo = 0;
    this->N = 0;
  }

  void libera() {
    while (this->N) {
      this->desempilha();
    }
  }
};
static_assert(
    PilhaTAD<PilhaMin, int>);  // testa de PilhaMin está de acordo com o TAD

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_