# O Algoritmo de Dijkstra
- Dado um grafo G de N vértices e M arestas onde cada aresta do grafo possui um peso não negativo e dado um vértice A deste grafo, o algoritmo desenvolvido em 1956 por Edsger Dijkstra, produz um vetor D de tamanho N, em que D[B] representa a soma mínima dos pesos das arestas que formam um caminho de A para B, ou seja, D[B] é o tamanho do menor caminho de A para B.
- Esse algoritmo, originalmente, tem uma complexidade de O(n²), mas com o auxílio de estruturas de dados como fila de prioridade, é possível reduzir sua complexidade a O(M*log(N)).
- O algoritmo de Dijkstra é uma bfs. A ideia é, partindo de um vértice, verificar todos os caminhos que chegam em todos os outros vértices e guardar o menor caminho para cada um deles.
    - Para fazer isso, nós visitamos os vértices adjacentes ao inicial e guardamos em uma fila de prioridade um par com o tamanho do caminho até esses vértices e esses vértices.
    - Então, nós percorremos essa fila de prioridade visitando os vértices adjacentes a cada vértice presente nela. Seja U um vértice presente na fila de prioridade, o tamanho do caminho para cada vértice adjacente a U é a soma do tamanho do caminho do vértice inicial até U (ou seja, o valor guardado na primeira posição do par que nós acessamos da fila de pioridade) com o tamanho do caminho de U até esse vértice. Nós comparamos o tamanho desse caminho com o tamanho do caminho já guardado no vetor D para chegarmos a esse vértice (que começa em infinito), se esse novo caminho for menor, guardamos ele no lugar do anterior
    - Daí, nós guardamos na fila de prioridade um par com o tamanho do caminho até cada um dos novos vértices visitados e com seus valores e repetimos o passo anterior até que a fila de prioridade esteja vazia (ou seja, até percorrermos todo o grafo).
## Implementação do algoritmo em c++
```cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> par;

vector<int> dijkstra(vector<vector<par>> & grafo, int A) {
    // Inicializamos o vetor dos menores caminhos
    vector<int> D(grafo.size(), 1e9+7);
    vector<bool> visitado(grafo.size(), false);
    priority_queue<par, vector<par>, greater<par>> fila;
    D[A] = 0; // O caminho de A até A tem peso 0
    fila.push({D[A], A});

    while (!fila.empty()) {
        int c, v;
        tie(c, v) = fila.top();
        fila.pop();
        if (!visitado[v]) {
            visitado[v] = true;
            // Para cada nó adjacente ao atual
            for (par & adj : grafo[v]) {
                int u, p;
                tie(u, p) = adj;
                // nós verificamos se a soma do peso do caminho até o nó atual (c) com o peso do caminho do nó atual até o adjacente (p) é menor do que o menor caminho já encontrado até esse nó adjacente, se for, guardamos ele
                if (p + c < D[u]) {
                    D[u] = p + c;
                    // Se o caminho encontrado for o menor, nós faremos tudo o que foi feito aqui para esse nó
                    fila.push({D[u], u});
                }
            }
        }
    }

    return D;
}
```