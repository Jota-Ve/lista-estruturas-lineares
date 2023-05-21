
// 1. Considere um tipo chamado Deque, que inclui manipulação de dois extremos
// em uma estrutura linear (como se operasse como Pilha e Fila simultaneamente).

#include <cassert>
template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t) {
  // requer operação de consulta ao elemento 'inicio'
  {a.inicio()};         // requer operação de consulta ao elemento 'fim'
  {a.fim()};            // requer operação 'insereInicio' sobre tipo 't'
  {a.insereInicio(t)};  // requer operação 'insereFim' sobre tipo 't'
  {a.insereFim(t)};     // requer operação 'removeInicio' e retorna tipo 't'
  {a.removeInicio()};   // requer operação 'removeFim' e retorna tipo 't'
  {a.removeFim()};
};

/*1.a) Satisfaça as seguintes operações de um DequeTAD para o tipo ‘char’,
utilizando uma estrutura Sequencial OU uma estrutura encadeada:*/

class No {
  /* Classe No com 'char dado' e 2 ponteiros:
    'ant': Será o ponteiro que aponta para o 'Nó anterior'. Com exceção
      do primeiro Nó, que apontará para zero, todos os Nós devem possuir
      uma referência para o 'Nó anterior'.

    'prox': Será o ponteiro que aponta para o 'próximo Nó'. Com exceção
      do último Nó, que apontará para zero, todos os Nós devem possuir
      uma referência para o 'próximo Nó'.

    *Quando o deque possuir apenas um Nó, ele será o primeiro e último ao mesmo
    *tempo, e por isso ambos os ponteiros apontarão para zero.
  */
 public:
  char dado;
  No* ant;
  No* prox;
};

class Deque {
 public:
  // Referências para o primeiro e último Nó do Deque, tornando-os sempre
  // acessíveis em Θ(1) pois não será necessário percorrer o Deque para
  // encontrá-los.
  No* primeiro;
  No* ultimo;

  // Contador de Nós/elementos no Deque.
  int N;

  // Θ(1), sempre serão executadas 3 simples operações Θ(1) de atribuição
  void inicio() {
    /* 'primeiro' e 'ultimo' ambos apontam para zero, pois o deque está vazio.
      'N', contador de elementos no Deque, também inicializado com zero.*/
    this->primeiro = 0;
    this->ultimo = 0;
    this->N = 0;
  }

  /*O(N):
    No melhor caso, this->N == 0, então não executa o loop. Ω(1).
    No pior caso, this->N > 0, então executa o loop N vezes. O(N).*/
  void fim() {
    // Enquanto possuir Nó, remove um Nó do fim.
    while (this->N > 0) this->removeFim();  // Θ(1) para cada iteração
  }

  // Θ(1), pois executa um número constante de operações Θ(1)
  void insereInicio(char dado) {
    /* Cria um novo Nó, atribuindo o dado a ser inserido.
      Como o novoNo será inserido no início, seu ponteiro para o Nó
      anterior é inicializado com zero, e o ponteiro para o próximo
      Nó recebe a referência para o primeiro Nó atual.*/
    No* novoNo = new No{.dado = dado, .ant = 0, .prox = this->primeiro};

    if (this->N == 0)
      // Se o deque estiver vazio, o ponteiro para o último Nó também aponta
      // para o novo Nó. Ou seja, o novo Nó será o primeiro e o último, pois é o
      // único elemento
      this->ultimo = novoNo;
    else
      /*Se o deque não estiver vazio, já existe um primeiro Nó.
        O primeiro Nó atual então passa a ter um 'Nó anterior',
        o novoNo, pois ele está sendo inserido no início do deque.*/
      this->primeiro->ant = novoNo;

    // Finalmente, o novoNo passa a ser referenciado como o primeiro do deque.
    this->primeiro = novoNo;
    // Aumenta o contador de elementos.
    this->N++;
  }

  // Θ(1), pois executa um número constante de operações Θ(1)
  void insereFim(char dado) {
    /*Cria o novoNo, atribuindo o dado a ser inserido.
      Por estar sendo inserido no fim, o ponteiro ant aponta para o último Nó
      atual, e o ponteiro prox é inicializado com zero.*/
    No* novoNo = new No{.dado = dado, .ant = this->ultimo, .prox = 0};

    if (this->N == 0)
      /*Se o deque está vazio, o ponteiro para o primeiro Nó também aponta para
       * o novoNo*/
      this->primeiro = novoNo;
    else
      /*Se o deque não está vazio, o último atual passa a ter um 'próximo Nó', o
      novoNo, pois ele está sendo inserido no fim do deque.*/
      this->ultimo->prox = novoNo;

    // Finalmente, o novoNo passa a ser referenciado como o último Nó.
    this->ultimo = novoNo;
    // Aumenta o contador de elementos.
    this->N++;
  }

  // Θ(1), pois executa um número constante de operações Θ(1)
  char removeInicio() {
    // Copia a referência ao primeiro Nó, para que a memória possa ser liberada
    // em breve.
    No* primeiro = this->primeiro;
    // Copia o dado do primeiro Nó, para que seja retornado ao final.
    char dado = primeiro->dado;

    /* Faz o ponteiro primeiro apontar para o próximo nó
    (ou zero, caso esteja removendo o último elemento do deque)*/
    this->primeiro = this->primeiro->prox;

    /* Se o novo primeiro for diferente de zero, então ele é um Nó, e como o
      'primeiro Nó' não deve possuir um 'Nó anterior' o ponteiro 'ant'
      deve receber zero.*/
    if (this->primeiro != 0) this->primeiro->ant = 0;

    // Libera a memória do Nó que está sendo removido.
    delete primeiro;
    // Decrementa o contador de Nós em 1.
    this->N--;
    // Retorna o dado do Nó removido.
    return dado;
  }

  // Θ(1), pois executa um número constante de operações Θ(1)
  char removeFim() {
    // Copia a referência ao último Nó, para que a memória possa ser liberada
    // em breve.
    No* ultimo = this->ultimo;

    // Copia o dado do último Nó, para que seja retornado ao final.
    char dado = ultimo->dado;

    /* Faz o ponteiro último apontar para o Nó anterior
    (ou zero, caso esteja removendo o último elemento do deque)*/
    this->ultimo = this->ultimo->ant;

    /* Se o novo último for diferente de zero, então ele é um Nó, e como o
      'último Nó' não deve possuir um 'próximo Nó' o ponteiro 'prox'
      deve receber zero.*/
    if (this->ultimo != 0) this->ultimo->prox = 0;

    // Libera a memória do Nó que está sendo removido.
    delete ultimo;

    // Decrementa o contador de Nós em 1.
    this->N--;
    // Retorna o dado do Nó removido.
    return dado;
  }
};
static_assert(DequeTAD<Deque, char>);  // testa se Deque está correto