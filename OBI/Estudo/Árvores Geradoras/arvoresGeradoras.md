# Árvores Geradoras
- Seja G um grafo conexo não direcionado. Uma árvore geradora T de G é um subgrafo de G que é uma árvore, de modo que todo vértice pertencente a G também pertence a T.
    ## Árvore Geradora Mínima
    - Seja G um grafo conexo não direcionado com pesos. Uma árvore geradora T de G é uma árvore geradora mínima se a soma dos pesos das arestas T é a mínima possível.

# Algoritmo de Krushal
- Desenvolvido por Joseph Kurshal em 1956, encontra uma árvore geradora mínima de um grafo.
- A ideia consiste em criar um vetor que contém todas as arestas do grafo e ordenar esse vetor pelos pesos de forma crescente. 