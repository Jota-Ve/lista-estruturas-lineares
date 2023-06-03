
// * 4) Escreva um algoritmo que dada uma pilha padrão P externa passada como
// * parâmetro, inverte o conteúdo de P. Somente utilize as estruturas extras
// * permitidas como armazenamento externo(mais espaço constante)
// * b) Dua Pilhas

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_04_B_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_04_B_HPP_

#include <fmt/core.h>

#include <cassert>
#include <queue>
#include <stack>

void invertePilhaCom2Pilhas(std::stack<char>* p) {
  std::stack<char> p1;  // primeira pilha auxiliar
  std::stack<char> p2;  // segunda pilha auxiliar
  // mais espaço auxiliar constante

  // Passa Pilha p para Pilha p1, invertendo a ordem
  while (p->size()) {
    p1.push(p->top());
    p->pop();
  }

  // Passa Pilha p1 para Pilha p2, reestabelecendo a ordem original
  while (p1.size()) {
    p2.push(p1.top());
    p1.pop();
  }

  // Passa Pilha p2 para Pilha p, invertendo novamente a ordem
  while (p2.size()) {
    p->push(p2.top());
    p2.pop();
  }
}

void testeInvertePilhaCom2Pilhas() {
  std::stack<char> pilha;
  pilha.push('A');
  pilha.push('B');
  pilha.push('C');
  pilha.push('D');

  invertePilhaCom2Pilhas(&pilha);

  assert(pilha.top() == 'A');
  pilha.pop();
  assert(pilha.top() == 'B');
  pilha.pop();
  assert(pilha.top() == 'C');
  pilha.pop();
  assert(pilha.top() == 'D');
  pilha.pop();

  fmt::print("Todos os testes 04-b passaram!\n");
}
#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_04_B_HPP_
