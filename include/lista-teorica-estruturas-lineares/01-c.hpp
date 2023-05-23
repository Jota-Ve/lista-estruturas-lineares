
/*1.c*) Implemente uma estrutura FilaDeque para tipo ‘char’, utilizando
somente um Deque como armazenamento interno e mais espaço auxiliar
constante:*/

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_

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

  char frente() { return this->d.primeiro->dado; }

  void enfileira(char dado) { this->d.insereFim(dado); }

  char desenfileira() { return this->d.removeInicio(); }

  int tamanho() { return this->d.N; }
};
static_assert(DequeTAD<Deque, char>);     // testa se Deque está correto
static_assert(FilaTAD<FilaDeque, char>);  // testa se Fila está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_01_C_HPP_
