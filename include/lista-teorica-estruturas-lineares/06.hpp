
//* 6) Criar uma implementação do TAD Pilha para o tipo ‘int’, chamada PilhaMin,
//* que oferece os métodos do TAD e também o método obterMinimo(), que retorna o
//* menor elemento da pilha. O método obterMinimo() deve operar em tempo
//* constante.

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_

#include <cassert>
#include <cstdint>
#include <lista-teorica-estruturas-lineares/PilhaTAD.hpp>
#include <vector>  //NOLINT

#include "fmt/core.h"

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

  int desempilha() {
    No* ultimo = this->ultimo;
    int dado = ultimo->dado;

    this->ultimo = this->ultimo->prox;

    this->removeDado(dado);
    delete ultimo;
    this->N--;
    return dado;
  }

  void empilha(int t) {
    No* novoNo = new No{.dado = t, .prox = this->ultimo};
    this->insereDado(t);
    this->ultimo = novoNo;
    this->N++;
  }

  int obterMinimo() { return this->dados.back(); }

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

  void teste() {
    this->cria();

    this->empilha(0);
    assert(this->obterMinimo() == 0);
    this->empilha(1);
    assert(this->obterMinimo() == 0);
    this->empilha(2);
    assert(this->obterMinimo() == 0);
    this->empilha(3);
    assert(this->obterMinimo() == 0);

    assert(this->tamanho() == 4);

    this->desempilha();
    assert(this->obterMinimo() == 0);
    this->desempilha();
    assert(this->obterMinimo() == 0);
    this->desempilha();
    assert(this->obterMinimo() == 0);

    this->empilha(-5);
    assert(this->obterMinimo() == -5);
    this->empilha(-50);
    assert(this->obterMinimo() == -50);
    this->empilha(100);
    this->empilha(200);
    this->empilha(300);
    assert(this->obterMinimo() == -50);

    this->libera();
    assert(this->tamanho() == 0);

    fmt::print("Todos os testes 06 passaram!\n");
  }

 private:
  void insereDado(int dado) {
    /*Insere o dado em um Vetor em ordem decrescente. Desta forma, o menor valor
     * sempre pode ser obtido em O(1) lendo o último elemento do Vetor.*/

    /*Se o Vetor estiver vazio ou 'dado' for <= o último (menor) dado, insere no
     * final e retorna.*/
    if (this->dados.empty() || dado <= this->dados.back()) {  // O(1)
      this->dados.push_back(dado);                            // O(1)
      return;
    }

    /*Percorre o vetor até achar a posição de um elemento <= o dado a ser
     * inserido. Quando ao encontrar, insere o dado nessa posição, deslocando
     * para 'frente' os N-i dados posteriores em 1 posição*/
    for (int8_t i = 0; i < this->dados.size(); i++) {
      if (this->dados.at(i) <= dado) {                      // O(1)
        this->dados.insert(this->dados.begin() + i, dado);  // O(N)
        return;
      }
    }
  }

  void removeDado(int dado) {                          // O(N)
    for (int8_t i = 0; i < this->dados.size(); i++) {  // O(N)
      if (this->dados.at(i) == dado) {
        // Ω(1) quando é o último elemento, do contrário O(N) Remove posição i e
        // desloca N-i elementos
        this->dados.erase(this->dados.begin() + i);
        return;
      }
    }
  }
};
static_assert(
    PilhaTAD<PilhaMin, int>);  // testa de PilhaMin está de acordo com o TAD

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_06_HPP_
