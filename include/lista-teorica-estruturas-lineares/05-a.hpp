
//* 5) Escreva um algoritmo que dada uma fila padrão F externa passada como
//* parâmetro, inverte o conteúdo de F. Somente utilize as estruturas extras
//* permitidas como armazenamento externo (mais espaço constante)

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_05_A_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_05_A_HPP_

#include <cassert>
#include <functional>
#include <queue>
#include <stack>

#include "fmt/core.h"

class InversorDeFila {
 public:
  //* a) Uma Pilha
  void inverteCom1Pilha(std::queue<char>* f) {
    std::stack<char> p;  // somente essa pilha e mais espaço auxiliar constante

    while (f->size()) {
      p.push(f->front());
      f->pop();
    }

    while (p.size()) {
      f->push(p.top());
      p.pop();
    }
  }

  void teste() { this->testeInverte('a'); }

 private:
  void testeInverte(char letra) {
    std::queue<char> f;
    f.push('A');
    f.push('B');
    f.push('C');
    f.push('D');

    if (letra == 'a') {
      this->inverteCom1Pilha(&f);
    } else {
      fmt::print("Letra da questão 5 não reconhecida: {}", letra);
      assert(false);
    }

    assert(f.front() == 'D');
    f.pop();
    assert(f.front() == 'C');
    f.pop();
    assert(f.front() == 'B');
    f.pop();
    assert(f.front() == 'A');
    f.pop();

    fmt::print("Todos os testes 05-{} passaram!\n", letra);
  }
};

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_05_A_HPP_
