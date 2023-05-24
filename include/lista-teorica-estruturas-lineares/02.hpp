/*
* 2) Implemente uma estrutura que satisfaz o TAD Pilha para o tipo ‘char’ e
somente utiliza duas Filas como armazenamento interno (mais espaço constante):
*/

#include <lista-teorica-estruturas-lineares/01-b.hpp>
#include <queue>  // Fila genérica em C++

class Pilha2F {
 public:
  std::queue<char> f1;  // Fila para ‘char’
  std::queue<char> f2;  // Fila para ‘char’
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Pilha
};

static_assert(PilhaTAD<Pilha2F, char>);  // testa se Pilha está correta

/*
P1  P2
2    1
4    3

*/