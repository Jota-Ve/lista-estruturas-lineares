
#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_PILHATAD_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_PILHATAD_HPP_

template <typename Agregado, typename Tipo>
concept PilhaTAD = requires(Agregado a, Tipo t) {
  // requer operação 'topo'
  {a.topo()};  // NOLINT
  // requer operação 'empilha' sobre tipo 't'
  {a.empilha(t)};  // NOLINT
  // requer operação 'desempilha'
  {a.desempilha()};  // NOLINT
  // requer operação 'tamanho'
  {a.tamanho()};  // NOLINT
};                // NOLINT

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_PILHATAD_HPP_
