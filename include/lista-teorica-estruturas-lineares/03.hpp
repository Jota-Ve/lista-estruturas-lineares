
#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_03_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_03_HPP_

// * 3) Implemente uma estrutura que satisfaz o TAD Fila para o tipo ‘char’ e
// somente utiliza duas Pilhas como armazenamento interno (mais espaço
// constante):

#include <lista-teorica-estruturas-lineares/01-c.hpp>
#include <stack>  // Pilha genérica em C++ //NOLINT

class Fila2P {
 public:
  std::stack<char> p1;  // Pilha para ‘char’
  std::stack<char> p2;  // Pilha para ‘char’
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Fila

  char frente() {
    if (this->p2.empty()) this->transfereP1ParaP2();
    return this->p2.top();
  }

  void enfileira(char dado) { this->p1.push(dado); }

  void transfereP1ParaP2() {
    while (!this->p1.empty()) {
      p2.push(p1.top());
      p1.pop();
    }
  }

  char desenfileira() {
    if (this->p2.empty()) this->transfereP1ParaP2();
    char dado = p2.top();
    p2.pop();
    return dado;
  }

  int tamanho() { return this->p1.size() + this->p2.size(); }

  void teste() {
    while (this->tamanho()) this->desenfileira();
    assert(this->tamanho() == 0);

    this->enfileira('a');
    assert(this->tamanho() == 1);
    assert(this->frente() == 'a');

    this->enfileira('b');
    assert(this->frente() == 'a');
    assert(this->tamanho() == 2);

    this->enfileira('c');
    assert(this->frente() == 'a');
    assert(this->tamanho() == 3);

    assert(this->desenfileira() == 'a');
    assert(this->tamanho() == 2);
    assert(this->frente() == 'b');

    assert(this->desenfileira() == 'b');
    assert(this->tamanho() == 1);
    assert(this->frente() == 'c');

    assert(this->desenfileira() == 'c');
    assert(this->tamanho() == 0);

    this->enfileira('d');
    assert(this->tamanho() == 1);
    assert(this->frente() == 'd');

    while (this->tamanho()) this->desenfileira();
    assert(this->tamanho() == 0);
    print("Todos os testes 03 passaram!\n");
  }
};
static_assert(FilaTAD<Fila2P, char>);  // testa se Fila está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_03_HPP_
