
#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_DEQUETAD_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_DEQUETAD_HPP_

template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t) {
  // requer operação de consulta ao elemento 'inicio'
  {a.inicio()};  // requer operação de consulta ao elemento 'fim' NOLINT
  {a.fim()};     // requer operação 'insereInicio' sobre tipo 't' NOLINT
  {a.insereInicio(t)};  // requer operação 'insereFim' sobre tipo 't' NOLINT
  {a.insereFim(t)};  // requer operação 'removeInicio' e retorna tipo 't' NOLINT
  {a.removeInicio()};  // requer operação 'removeFim' e retorna tipo 't' NOLINT
  {a.removeFim()};     // NOLINT
};                     // NOLINT

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_DEQUETAD_HPP_
