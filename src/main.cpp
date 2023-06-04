// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho
#include <fmt/core.h>

#include <cassert>
#include <lista-teorica-estruturas-lineares/01-a.hpp>
#include <lista-teorica-estruturas-lineares/01-b.hpp>
#include <lista-teorica-estruturas-lineares/01-c.hpp>
#include <lista-teorica-estruturas-lineares/02.hpp>
#include <lista-teorica-estruturas-lineares/03.hpp>
#include <lista-teorica-estruturas-lineares/04-a.hpp>
#include <lista-teorica-estruturas-lineares/04-b.hpp>
#include <lista-teorica-estruturas-lineares/04-c.hpp>
#include <lista-teorica-estruturas-lineares/05.hpp>

using fmt::print;

int somaIntervalo(int primeiro, int ultimo) {
  int soma = 0;
  for (int i = primeiro; i <= ultimo; i++) soma += i;

  return soma;
}

int main() {
  Deque deq;
  deq.teste();

  PilhaDeque pilhaDeq;
  pilhaDeq.teste();

  FilaDeque filaDeq;
  filaDeq.teste();

  Pilha2F pilha2f;
  pilha2f.teste();

  Fila2P fila2p;
  fila2p.teste();

  InversorDeFila invFila;

  testeInvertePilhaComFila();
  testeInvertePilhaCom2Pilhas();
  testeInvertePilhaCom1Pilha();
  invFila.teste();

  return 0;
}
