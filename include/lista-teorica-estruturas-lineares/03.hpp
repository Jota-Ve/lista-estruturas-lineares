// * 3) Implemente uma estrutura que satisfaz o TAD Fila para o tipo ‘char’ e
// somente utiliza duas Pilhas como armazenamento interno (mais espaço
// constante):

#include <stack>  // Pilha genérica em C++
class Fila2P {
 public:
  std::stack<char> p1;  // Pilha para ‘char’
  std::stack<char> p2;  // Pilha para ‘char’
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Fila
};
static_assert(FilaTAD<Fila2P, char>);  // testa se Fila está correta