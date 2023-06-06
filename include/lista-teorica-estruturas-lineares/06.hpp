
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
    /*Insere o dado em um Vetor em ordem decrescente. Desta forma, o menor valor
     * sempre pode ser obtido em O(1) lendo o último elemento do Vetor.*/

    /*Se o Vetor estiver vazio ou 'dado' for <= o último (menor) dado, insere no
     * final e retorna.*/
    if (this->dados.empty() || dado <= this->dados.back()) {  // O(1)
      this->dados.push_back(dado);                            // O(1)
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
