
//* 5) Escreva um algoritmo que dada uma fila padrão F externa passada como
//* parâmetro, inverte o conteúdo de F. Somente utilize as estruturas extras
//* permitidas como armazenamento externo (mais espaço constante)

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_05_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_05_HPP_

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

    // O(N), Passa os elementos da Fila para a Pilha.
    while (f->size()) {
      p.push(f->front());  // Θ(1)
      f->pop();            // Θ(1)
    }

    // O(N), Devolve os elementos da Pilha para a Fila, invertendo a ordem pois
    // a Pilha é FILO e a fila é FIFO.
    while (p.size()) {
      f->push(p.top());  // Θ(1)
      p.pop();           // Θ(1)
    }
  }

  //* b) Duas Filas
  void inverteCom2Filas(std::queue<char>* f) {
    std::queue<char> f1;
    std::queue<char> f2;

    // O(N)
    while (f->size()) {
      // O(N), Move N-1 elementos de f para f1
      while (f->size() > 1) {
        f1.push(f->front());  // O(1)
        f->pop();             // O(1)
      }

      // O(1), Separa o ultimo de f para f2
      f2.push(f->front());
      f->pop();

      // O(N), Devolve f1 para f
      while (f1.size()) {
        f->push(f1.front());  // O(1)
        f1.pop();             // O(1)
      }
    }

    // O(N), devolve f2 para f na ordem inversa
    while (f2.size()) {
      f->push(f2.front());  // O(1)
      f2.pop();             // O(1)
    }
  }

  void teste() {
    this->testeInverte('a');
    this->testeInverte('b');
  }

 private:
  void testeInverte(char letra) {
    std::queue<char> f;
    f.push('A');
    f.push('B');
    f.push('C');
    f.push('D');

    if (letra == 'a') {
      this->inverteCom1Pilha(&f);
    } else if (letra == 'b') {
      this->inverteCom2Filas(&f);
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

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_05_HPP_
