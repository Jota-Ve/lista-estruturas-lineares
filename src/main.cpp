// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho
#include <fmt/core.h>

#include <cassert>
#include <lista-teorica-estruturas-lineares/01-a.hpp>
#include <lista-teorica-estruturas-lineares/01-b.hpp>
#include <lista-teorica-estruturas-lineares/01-c.hpp>

using fmt::print;

int somaIntervalo(int primeiro, int ultimo) {
  int soma = 0;
  for (int i = primeiro; i <= ultimo; i++) soma += i;

  return soma;
}

int main() {
  Deque deq;
  PilhaDeque pilhaDeq;
  FilaDeque filaDeq;

  deq.teste();
  pilhaDeq.teste();
  filaDeq.teste();
  return 0;
}
