
//* 2) Implemente uma estrutura que satisfaz o TAD Pilha para o tipo ‘char’ e
//* somente utiliza duas Filas como armazenamento interno (mais espaço
//* constante):

#ifndef LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_
#define LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_

#include <fmt/core.h>

#include <cassert>
#include <lista-teorica-estruturas-lineares/PilhaTAD.hpp>
#include <queue>  // Fila genérica em C++

class Pilha2F {
 public:
  std::queue<char> f1;  // Fila para ‘char’
  std::queue<char> f2;  // Fila para ‘char’
  // SOMENTE espaço auxiliar CONSTANTE aqui (nenhum vetor, lista, etc)
  // implementar métodos do TAD Pilha

  char topo() {  // Retorna o último da fila não vazia  Θ(1)
    if (this->f1.empty()) return f2.back();  // Θ(1)
    return f1.back();                        // Θ(1)
  }

  void empilha(char dado) {  // Adiciona ao final da fila não vazia Θ(1)
    if (this->f1.empty()) return f2.push(dado);  // Θ(1)
    f1.push(dado);                               // Θ(1)
  }

  char desempilha() {
    /*Salva o topo
     */
    char dado = this->topo();  // salva o ultimo da fila Θ(1)

    // Esvazia a fila que tiver dados passando para a outra fila.
    // Deleta o último eleemnto da fila
    if (f1.empty()) {          // Ω(1), O(N)
      while (f2.size() > 1) {  // Θ(N)
        f1.push(f2.front());   // Θ(1)
        f2.pop();              // Θ(1)
      }
      f2.pop();  // Θ(1)
      assert(f2.size() == 0);

    } else {
      while (f1.size() > 1) {  // Ω(1), O(N)
        f2.push(f1.front());   // Θ(1)
        f1.pop();              // Θ(1)
      }
      f1.pop();  // Θ(1)
      assert(f1.size() == 0);
    }

    return dado;  // Θ(1)
  }

  int tamanho() {                      // Θ(1)
    if (f1.empty()) return f2.size();  // Θ(1)
    return f1.size();                  // Θ(1)
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
    fmt::print("Todos os testes 02 passaram!\n");
  }
};

static_assert(PilhaTAD<Pilha2F, char>);  // testa se Pilha está correta

#endif  // LISTA_TEORICA_ESTRUTURAS_LINEARES_02_HPP_
