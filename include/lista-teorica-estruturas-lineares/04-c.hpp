
// * 4) Escreva um algoritmo que dada uma pilha padrão P externa passada como
// * parâmetro, inverte o conteúdo de P. Somente utilize as estruturas extras
// * permitidas como armazenamento externo(mais espaço constante)
// * c) Uma Pilha

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_04_C_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_04_C_HPP_

#include <fmt/core.h>

#include <cassert>
#include <queue>
#include <stack>

/*
  * i | *p | p1 | aux
    0 | 3  |    |     * Começo
      | 2  |    |
      | 1  |    |
   ___|____|____|____
    0 | 2  |    | 3   * Salva o topo em aux
      | 1  |    |
   ___|____|____|____
    0 |    | 1  | 3   * Passa N-i elementos de *p para p1
      |    | 2  |
   ___|____|____|____
    0 |    | 1  |     * Devolve aux para *p
      | 3  | 2  |
   ___|____|____|____
    0 | 2  |    |     * Devolve p1 para *p
      | 1  |    |
      | 3  |    |
   ___|____|____|____
    1 | 1  |    | 2   * Repete N-1 vezes
      | 3  |    |
   ___|____|____|____
    1 | 3  | 1  | 2
   ___|____|____|____
    1 | 2  | 1  |
      | 3  |    |
   ___|____|____|____
    1 | 1  |    |
      | 2  |    |
      | 3  |    |
   ___|____|____|____
    2 | 2  |    | 1
      | 3  |    |
   ___|____|____|____
    2 | 1  |    |
      | 2  |    |
      | 3  |    |
   ___|____|____|____

*/

void invertePilhaCom1Pilha(std::stack<char>* p) {
  std::stack<char> p1;
  char aux;

  for (auto i = 0; i < p->size(); i++) {
    // Passa o primeiro elemento para aux
    aux = p->top();
    p->pop();

    /* Passa N-i elementos de 'p' para 'p1', invertendo a ordem. N-i pois os
      últimos 'i' elementos já foram inseridos na ordem inversa. */
    while (p->size() > i) {
      p1.push(p->top());
      p->pop();
    }

    // Agora só restam os elentos invertidos em 'p'.

    // Adiciona o elemento separado em 'aux' como o novo elemento invertido em
    // 'p'.
    p->push(aux);

    // Devolve 'p1' para 'p', restaurando a ordem original desses elementos.
    while (p1.size()) {
      p->push(p1.top());
      p1.pop();
    }
  }
}

void testeInvertePilhaCom1Pilha() {
  std::stack<char> p;

  p.push('A');
  p.push('B');
  p.push('C');
  p.push('D');

  invertePilhaCom1Pilha(&p);

  assert(p.top() == 'A');
  p.pop();
  assert(p.top() == 'B');
  p.pop();
  assert(p.top() == 'C');
  p.pop();
  assert(p.top() == 'D');
  p.pop();

  print("Todos os testes 04-c passaram!\n");
}
#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_04_C_HPP_
