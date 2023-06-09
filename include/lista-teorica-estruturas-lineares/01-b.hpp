
//* 1.b) Implemente uma estrutura PilhaDeque para tipo ‘char’, utilizando
//* somente um Deque como armazenamento interno e mais espaço auxiliar
//* constante:

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_01_B_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_01_B_HPP_

#include <fmt/core.h>

#include <cassert>

#include "lista-teorica-estruturas-lineares/01-a.hpp"
#include "lista-teorica-estruturas-lineares/PilhaTAD.hpp"

using fmt::print;

class PilhaDeque {
 public:
  Deque d;  // Deque para ‘char’ (veja exercício anterior)
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Pilha

  void cria() { this->d.inicio(); }

  void libera() { this->d.fim(); }

  char topo() { return this->d.ultimo->dado; }

  void empilha(char dado) { this->d.insereFim(dado); }

  char desempilha() { return this->d.removeFim(); }

  int tamanho() { return this->d.N; }

  void teste() {
    this->cria();
    assert(this->tamanho() == 0);

    this->empilha('C');
    this->empilha('B');
    this->empilha('A');
    assert(this->tamanho() == 3);

    assert(this->desempilha() == 'A');
    assert(this->tamanho() == 2);
    assert(this->desempilha() == 'B');
    assert(this->tamanho() == 1);
    assert(this->desempilha() == 'C');
    assert(this->tamanho() == 0);

    this->empilha('C');
    this->empilha('B');
    this->empilha('A');
    assert(this->topo() == 'A');
    assert(this->topo() == 'A');
    assert(this->topo() == 'A');
    assert(this->tamanho() == 3);

    this->libera();
    assert(this->tamanho() == 0);

    print("Todos os testes 01-b passaram!\n");
  }
};

static_assert(DequeTAD<Deque, char>);       // testa se Deque está correto
static_assert(PilhaTAD<PilhaDeque, char>);  // testa se Pilha está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_01_B_HPP_
