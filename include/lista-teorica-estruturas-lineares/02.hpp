#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_

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

  char topo() {
    if (this->f1.empty()) return f2.back();
    return f1.back();
  }

  void empilha(char dado) {
    if (this->f1.empty()) return f2.push(dado);
    f1.push(dado);
  }

  char desempilha() {
    char dado = this->topo();
    if (f1.empty()) {
      while (f2.size() > 1) {
        f1.push(f2.front());
        f2.pop();
      }
      f2.pop();
      assert(f2.size() == 0);

    } else {
      while (f1.size() > 1) {
        f2.push(f1.front());
        f1.pop();
      }
      f1.pop();
      assert(f1.size() == 0);
    }

    return dado;
  }

  int tamanho() {
    if (f1.empty()) return f2.size();
    return f1.size();
  }

  void teste() {
    // Testa empilhar dados
    for (char i = '0'; i <= '9'; i++) {
      int tamanho = this->tamanho();
      this->empilha(i);

      assert(this->tamanho() == tamanho + 1);
      assert(this->topo() == i);
    }

    // Testa desempilhar dados
    for (char i = '9'; i >= '0'; i--) {
      int tamanho = this->tamanho();
      char topo = this->topo();

      assert(topo == i);
      assert(this->topo() == topo);

      this->desempilha();
      assert(this->tamanho() == tamanho - 1);
    }

    assert(this->tamanho() == 0);
    print("Todos os testes 02 passaram!\n");
  }
};

static_assert(PilhaTAD<Pilha2F, char>);  // testa se Pilha está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_
