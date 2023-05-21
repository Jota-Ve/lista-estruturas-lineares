// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho
#include <fmt/core.h>

#include <cassert>
#include <lista-teorica-estruturas-lineares/01-a.hpp>

using fmt::print;

int somaIntervalo(int primeiro, int ultimo) {
  int soma = 0;
  for (int i = primeiro; i <= ultimo; i++) soma += i;

  return soma;
}

void insereNos(Deque* dq) {
  dq->insereFim('D');
  dq->insereFim('E');
  dq->insereInicio('C');
  dq->insereFim('F');
  dq->insereInicio('B');
  dq->insereInicio('A');
  dq->insereFim('G');
  dq->insereFim('H');
  dq->insereFim('I');
  dq->insereFim('J');
  assert(dq->N == 10);
}

void test_01() {
  Deque dq;
  dq.inicio();

  insereNos(&dq);
  int N = dq.N;
  assert(dq.removeFim() == 'J');
  assert(dq.removeFim() == 'I');
  assert(dq.removeFim() == 'H');
  assert(dq.N == (N -= 3));

  assert(dq.removeInicio() == 'A');
  assert(dq.removeInicio() == 'B');
  assert(dq.N == (N -= 2));

  while (dq.N > 0) {
    dq.removeInicio();
    N--;
  }
  assert(dq.N == N && dq.N == 0);

  insereNos(&dq);
  dq.fim();
  assert(dq.N == 0);

  print("Todos os testes 01 passaram!\n");
}

int main() {
  test_01();

  return 0;
}
