
//* 6) Criar uma implementação do TAD Pilha para o tipo ‘int’, chamada PilhaMin,
//* que oferece os métodos do TAD e também o método obterMinimo(), que retorna o
//* menor elemento da pilha. O método obterMinimo() deve operar em tempo
//* constante.

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_

#include <cstdint>
#include <lista-teorica-estruturas-lineares/PilhaTAD.hpp>
#include <vector>  //NOLINT

class No {
 public:
  int dado;
  No* prox;
};

class PilhaMin {
 public:
  // incluir variáveis necessárias
  No* ultimo;
  std::vector<int8_t> dados;
  int N;

  int topo() { return this->ultimo->dado; }

  int tamanho() { return this->N; }

  int desempilha();
  void empilha(int t) {
    No* novoNo = new No{.dado = t, .prox = this->ultimo};
    this->ultimo = novoNo;
    this->N++;
  }
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

  void insereDado(int dado) {
    if (dado <= this->dados.back()) {
      this->dados.push_back(dado);
      return;
    }

    for (int8_t i = 0; i < this->dados.size(); i++) {
      if (this->dados.at(i) < dado) {
        this->dados.insert(this->dados.begin() + i, dado);
        return;
      }
    }
  }
};
static_assert(
    PilhaTAD<PilhaMin, int>);  // testa de PilhaMin está de acordo com o TAD

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_
