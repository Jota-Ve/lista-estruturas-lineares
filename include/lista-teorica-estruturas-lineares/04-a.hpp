
#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_04_A_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_04_A_HPP_

// * 4) Escreva um algoritmo que dada uma pilha padrão P externa passada como
// * parâmetro, inverte o conteúdo de P. Somente utilize as estruturas extras
// * permitidas como armazenamento externo(mais espaço constante)
// * a) Uma Fila

#include <fmt/core.h>

#include <cassert>
#include <queue>
#include <stack>

void inverte(std::stack<char>* p) {
  std::queue<char> f;  // somente essa fila e mais espaço auxiliar constante

  // Passa todos os elementos da Pilha para a Fila
  while (p->size()) {  // Θ(N)
    f.push(p->top());  // Θ(1)
    p->pop();          // Θ(1)
  }

  // Devolve todos os elementos da FIla para a PIlha
  while (f.size()) {     // Θ(N)
    p->push(f.front());  // Θ(1)
    f.pop();             // Θ(1)
  }
}

void testeInvertePilhaComFila() {
  std::stack<char> pilha;
  pilha.push('A');
  pilha.push('B');
  pilha.push('C');
  pilha.push('D');

  inverte(&pilha);

  assert(pilha.top() == 'A');
  pilha.pop();
  assert(pilha.top() == 'B');
  pilha.pop();
  assert(pilha.top() == 'C');
  pilha.pop();
  assert(pilha.top() == 'D');
  pilha.pop();

  print("Todos os testes 04-a passaram!\n");
}
#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_04_A_HPP_
