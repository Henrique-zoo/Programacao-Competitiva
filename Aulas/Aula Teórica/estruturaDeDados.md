<style>
    .imagem {
        align: center;
    }
</style>

# Estruturas de Dados
- Para certas aplicações, tornam-se necessárias estruturas de dados contituídas por conjuntos de elementos organizados, não pelos valores dos dados, mas com base em um determinado critério que regulamenta a entrada e a saída dos dados na estrutura
- Os critérios mais utilizados para regular a entrada e a saída dos dados são:
    - LIFO (last in, first out): dentre os elementos presentes na estrutura, o primeiro a sair dela será o último que foi adicionado. A estrutura de dados que segue esse princípio é a pilha (stack)
        - Exemplos: pilha de pratos e anilhas de academia

        <div class="imagem">

        ![Alt text](https://lh5.ggpht.com/_a2CzM_HCl5c/TBgv_qDmW-I/AAAAAAAAAlc/kodfuTYc8UI/image_thumb%5B3%5D.png?imgmax=800 "Pilha de pratos")
        </div>
    
    - FIFO (first in, first out): dentre os elementos presentes na estrutura, o primeiro a sair dela será o primeiro que a ela foi adicionado. A estrutura de dados que segue esse princípio é a fila (queue)
        - Exemplos: filas em guichês e engarrafamentos no tráfego
        <div class="imagem">
        
        ![Alt text](https://uploads.metropoles.cloud/wp-content/uploads/2023/01/01105612/apoiadores-de-Lula-formam-filas-quilome%CC%81tricas-para-acompanhar-posse-em-Brasi%CC%81lia.jpeg "Fila de petistas")
        </div>

## Fila
- First In First Out (FIFO)
- Armazena os elementos sequencialmente
- Inserção de elementos no final da ED
- Remoção de elementos no início da fila
    ### Implementação em C
    - Aqui, construímos uma fila aberta com encadeamento simples sem usar nenhuma classe ou tipo pré-definido.
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    struct elemento {
        char dado;
        struct elemento *prox;
    };

    void construir(struct elemento **pinicio) {
        FILE *arq;
        struct elemento *p1;
        char c;

        arq = fopen("t1.txt", "r");
        *pinicio = NULL;
        while ((c = getc(arq)) != EOF) {
            if (c != '\n') {
                p1 = malloc(sizeof(struct elemento));
                p1->dado = c;
                p1->prox = *pinicio;
                *pinicio = p1;
            }
        }
        fclose(arq);
        return;
    }

    void percorrer(struct elemento *pinicio) {
        struct elemento *p1;

        if (pinicio == NULL)
            printf("A lista está vazia!\n");
        else {
            p1 = pinicio;
            printf("\nElementos:\n");
            while (p1 != NULL) {
                printf("%c; ", p1 -> dado);
                p1 = p1 -> prox;
            }
            printf("\n\n");
        }
        return;
    }

    struct elemento *procurar(struct elemento *pinicio, char chave) {
        struct elemento *p1;

        p1 = pinicio;
        while ((p1 != NULL) && (p1 -> dado != chave))
            p1 = p1-> prox;
        return p1;
    }

    void remover(struct elemento **pinicio, char chave) {
        struct elemento *p1, *p2;
        int achou;

        if (*pinicio == NULL)
            printf("A lista está vazia!\n");
        else {
            p1 = *pinicio;
            achou = 0;

            while (p1 != NULL) {
                if (p1->dado == chave) {
                    if (*pinicio == p1) {
                        *pinicio = (*pinicio)->prox;
                        p2 = *pinicio;
                    } else {
                        p2->prox = p1->prox;
                    }
                    free(p1);
                    p1 = p2;
                    achou = 1;
                } else {
                    p2 = p1;
                    p1 = p1->prox;
                }
            }
            if (!achou)
                printf("Esse elemento não está na lista!");
        }
        return;
    }

    void destruir(struct elemento **pinicio) {
        struct elemento *p1;

        while (*pinicio != NULL) {
            p1 = *pinicio;
            *pinicio = (*pinicio) -> prox;
            free(p1);
        }
        return;
    }

    int main() {
        struct elemento *lista = NULL;
        char chave;
        int funcao;
        construir(&lista);

        while (funcao != 5) {
            printf("1. Exibir a lista\n2. Procurar um elemento\n3. Remover um elemento\n4. Apagar a lista\n5. Sair dessa tela\n");
            printf("Digite o número correspondente à ação que você quer: ");
            scanf("%d", &funcao);
            switch (funcao) {
                case 1:
                    percorrer(lista);
                    break;
                case 2:
                    printf("\nDigite um elemento para procurar na lista: ");
                    scanf(" %c", &chave);
                    struct elemento *resultado = procurar(lista, chave);
                    if (resultado != NULL) {
                        printf("\nElemento '%c' encontrado.\n\n", resultado -> dado);
                    } else {
                        printf("Elemento não encontrado na lista.\n");
                    }
                    break;
                case 3:
                    printf("\nDigite um elemento para remover da lista: ");
                    scanf(" %c", &chave);
                    remover(&lista, chave);
                    printf("\nLista após remoção do elemento '%c':\n", chave);
                    percorrer(lista);
                    break;
                case 4:
                    destruir(&lista);
                    break;
                case 5:
                    break;
                default:
                    printf("Essa não é uma opção, seu acéfalo!\n");
                    break;
            }
        }

        return 0;
    }
    ```
    ### Utilização em c++
    - Aqui, apenas utilizamos o tipo "queue" da stl para realizar as mesmas funções implementadas no códgigo anterior
    ```cpp
    #include<bits/stdc++.h>

    using namespace std;

    int main() {
        ios::sync_qwith_stdio(false); cin.tie(NULL); cout.tie(NULL);

        queue<int> fila;
        int n;
        cout << "1. Adicionar item a fila\n2. Exibir tamanho da fila\n3. Remover o primeiro item da fila\n4. Apagar toda a fila\nDigite o número referente a ação que você quer realizar: ";
        cin >> n;

        switch(n) {
            case 1:
                int a;
                cout << "Insira o número que você que adicionar: ";
                cin >> a;
                fila.push(a);
                break;
            case 2:
                cout << "A fila contém " << fila.size() << " elementos\n";
                break;
            case 3:
                int elemRemovido = fila.front();
                cout << "O elemento removido foi: " << elemRemovido;
                fila.pop();
                break;
            case 4:
                while (!fila.empty()) {
                    int elemRemovido = fila.front();
                    cout << elemRemovido << "\n";
                    fila.pop();
                }
                break;
            default:
                cout << "Esse número não é uma opção!";
                break;
        }
        return 0;
    }
    ```
## Pilha
- Last In First Out (LIFO)
- Iserção de elementos no início da ED
- Remoção de elementos no início da fila
    ### Implementação em C
    - A única diferença entre essa implementação é a função construir
    ```c

    ```
## Fila de Prioridade
- Tipicamente, está ligada à inserção ordenada mas, no C++, não é assim
- Em C++, a fila de prioridade é uma árvore chamada heap, uma estrutura de dados não linear
![Heap](../../../../../../henri/Pictures/Imagens%20Salvas/Heap.png "Heap")
- Cada elemento tem seus elementos filhos, que são necessariamente menores do que ele, conclui-se, portanto que o maior elemento é o que está no topo, porém, não necessariamente os outros elementos estão ordenados
    - Numa representação com lista, o heap é representado de modo que os elemento filho de um elemento no índice i estão nas posições 2i+1 e 2i+2
- Uma fila de prioridade é implementada da seguinte forma
    ```cpp
    template <class T, class Container = vector<T>,  class Compare = less<typename Container::value_type> > class priority_queue;
    ```
    - Onde:
        - T é o tipo dos elementos da fila;
        - Container é o tipo do objeto contêiner subjacente interno onde os elementos são armazenados, o tipo dos elementos deve ser T;
        - Compare é uma função que recebe dois elementos 'a' e 'b' do tipo T e retorna um booleano que será "true" se 'a' deve aparecer antes de 'b' na fila.
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int q, a, op, elem, maior_pilha;
    priority_queue<int> fp_max; // Fila de prioridade de máximos
    priority_queue<int, vector<int>, greater<int>> fp_min; // Fila de prioridade de mínimos
}
```
## Árvores
- Uma árvore é uma estrutura de dados que se caracteriza por uma relação hierarquica entre os elementos que a compõem.
- De forma mais formal, podemos dizer que uma árvore é um conjunto tal que:
    - Existe um nó (elemento) chamado raiz;
    - Os demais nós formam m conjuntos disjuntos tais que cada um desses conjuntos é, também, uma árvore (denomina-se sub-árvore)
- Representações de Árvore:
    - Representação Hierárquica:
    <div class="imagem">

    ![Árvore](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTA7hrc6qxAwmszkWbKzDIwP77jA6OAM9_9oD3UC6yl7A&s)
    </div>
    
    - Representação por conjuntos: