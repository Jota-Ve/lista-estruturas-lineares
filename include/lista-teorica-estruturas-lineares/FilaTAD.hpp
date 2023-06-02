
#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_FILATAD_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_FILATAD_HPP_

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

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_FILATAD_HPP_
