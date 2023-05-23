
/*1.c*) Implemente uma estrutura FilaDeque para tipo ‘char’, utilizando
somente um Deque como armazenamento interno e mais espaço auxiliar
constante:*/

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_

#include <cassert>

#include "lista-teorica-estruturas-lineares/01-a.hpp"

template <typename Agregado, typename Tipo>
concept FilaTAD = requires(Agregado a, Tipo t) {
  // requer operação 'frente'
  {a.frente()};  // NOLINT
  // requer operação 'enfileira' sobre tipo 't'
  {a.enfileira(t)};  // NOLINT
  // requer operação 'desenfileira'
  {a.desenfileira()};  // NOLINT
  // requer operação 'tamanho'
  {a.tamanho()};  // NOLINT
};                // NOLINT

class FilaDeque {
 public:
  Deque d;  // Deque para ‘char’ (veja exercício anterior)
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Fila

  // *Para implementar uma Fila utilizando um Deque, é necessário obedecer o
  //  *padrão FIFO, onde o primeiro elemento a entrar é o primeiro a sair. Ou
  //  *seja, deve-se escolher um 'lado' do deque para adicionar dados, e outro
  //  *para remover, simulando assim o comportamento de uma fila.

  void cria() { this->d.inicio(); }

  void libera() { this->d.fim(); }

  // * Θ(1), pois executa apenas 2 operações de desreferenciação, ambas Θ(1).
  char frente() {
    /* Como o lado escolhido para inserir dados foi o Fim, então frente() deve
      retornar o dado apontado pelo ponteiro d.primeiro, que aponta para o
      início do Deque.*/
    return this->d.primeiro->dado;
  }

  // Θ(1), pois apenas executa uma função Θ(1).
  void enfileira(char dado) {
    /* Para simular uma fila, os dados sempre serão inseridos pelo fim do
      Deque.*/
    this->d.insereFim(dado);
  }

  // Θ(1), pois apenas executa uma função Θ(1).
  char desenfileira() {
    /* Para simular uma fila, os dados sempre serão removidos pelo início do
      Deque.*/
    return this->d.removeInicio();
  }

  // Θ(1), pois apenas executa uma desreferenciação.
  int tamanho() {
    // Retorna o tamanho do Deque. Θ(1)
    return this->d.N;
  }

  void teste() {
    this->cria();
    assert(this->tamanho() == 0);

    this->enfileira('A');
    this->enfileira('B');
    this->enfileira('C');
    this->enfileira('D');
    assert(this->tamanho() == 4);

    // Assert frente() não remove Nó da fila, e que está retornando 'A'
    for (int i = 0; i < this->tamanho() * 2; i++) assert(this->frente() == 'A');
    assert(this->tamanho() == 4);

    assert(this->desenfileira() == 'A');
    assert(this->desenfileira() == 'B');
    assert(this->tamanho() == 2);

    this->libera();
    assert(this->tamanho() == 0);

    print("Todos os testes 01-c passaram!\n");
  }
};
static_assert(DequeTAD<Deque, char>);     // testa se Deque está correto
static_assert(FilaTAD<FilaDeque, char>);  // testa se Fila está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_
