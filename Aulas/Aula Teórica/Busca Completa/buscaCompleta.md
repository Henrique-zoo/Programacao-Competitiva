# Busca Completa
- É um paradigma para resolução de problemas que pode ser utilizado para resolver qualquer problema por meio de algoritmos;
- A ideia consiste em gerar todas as possíveis soluções para o problema utilizando força bruta;
- Em seguida, deve-se selecionar a melhor solução ou contar a quantidade total de soluções, dependendo do problema;
- O processo de busca geralmente é fácil de implementar e sempre retorna a resposta correta, porém, é pesado, ou seja, seu sucesso depende de entradas pequenas e tempos limite grandes;
- Ao desenvolver a solução de um problema usando busca completa, podemos utilizar estratégias generativas ou por filtragem;
    - Generativas: na geração dos elemetos de S, tentar construir diretamente apenas as soluções adequadas para o problema;
    - Filtragem: gera explicitamente todos os elementos de S e então checam cada elemento em busca da solução, isso é a filtragem;
        - São menos eficientes no sentido de tempo de execução.
- Uma etapa crucial de um algoritmo de busca completa é a geração de todos os elementos do espaço de soluções S do problema
- Exemplo (para ilustrar a diferença entre um gerador e um filtro):
    - Cosidere o problema de listar todos os initeiros positivos menores ou iguais a N que sejam múltiplos ou de 'a' ou de 'b'. O espaço de soluções S seriam todos os subconjuntos de A = {1, 2, 3, ..., N}.
        - Uma solução por filtro seria olhar cada um dos elementos s ∈ S e verificar se ele é composto apenas por múltiplos de 3 ou de 5. Como |S| é muito grande, é mais eficiente olhar individualmente os elementos de A e escolher somente os múltiplos de 3 ou 5
        - A solução por gerador seria construir múltiplos m de 3 e 5 diretamente, tomando cuidado para excluir elementos duplicados.

    ## Backtracking
    - O backtracking pode ser visto como uma busca em árvore onde cada nó representa um estado parcial da solução. O algoritmo explora cada possibilidade, avançando até encontrar uma solução completa ou chegar a um ponto onde não é possível continuar. Quando o algoritmo encontra um impasse (ou seja, uma solução parcial que não pode ser estendida para uma solução completa), ele "retrocede" (backtrack) para o último ponto de decisão e tenta uma alternativa diferente;
        ### Passos Gerais do Backtracking
        1. Esolha: escolher uma opção para seguir;
        2. Restrições: verificar se a escolha é válida de acordo com as restrições do problema;
        3. Exploração: se for segura, avança para a próxima linha e repete o processo;
        4. Solução Completa: Se uma solução completa é encontrada, ela é registrada;
        5. Retroceder: Se nenhuma solução completa pode ser obtida a partir do estado atual, desfaz a última escolha (volta para o ponto de decisão anterior) e tenta uma nova opção.
        ### Exemplo Clássico de Backtracking: Problema das Oito Rainhas
        - O algoritimo tenta colocar uma rainha em cada linha do tabuleiro, se uma posição é segura, a rainha é colocada e a função é chamada recursivamente para a próxima linha. Se a função atinge a última linha, ou seja, se todas as rainhas foram colocadas, a solução é impressa. Se uma posição não é segura, o algoritmo tenta a próxima coluna. Se todas as colunas foram tentadas e nenhuma é segura, o algoritmo retorna (backtrack) para a linha anterior para tentar uma nova posição para a rainha anterior
        1. Início: Começa com um tabuleiro vazio.
        2. Escolha: Coloca uma rainha na primeira coluna da primeira linha.
        3. Restrições: Verifica se a posição escolhida é segura (nenhuma outra rainha pode atacá-la).
        4. Exploração: Se for segura, avança para a próxima linha e repete o processo.
        5. Solução Completa: Quando todas as rainhas forem colocadas no tabuleiro de maneira segura, uma solução é encontrada.
        6. Retroceder: Se não for possível colocar uma rainha em uma linha, remove a última rainha colocada (retrocede) e tenta a próxima posição disponível.
        ```cpp
        #include <bits/stdc++.h>

        #define N 8

        using namespace std;

        bool isSafe(const vector<int>& board, int row, int col) {
            for (int i = 0; i < row; i++) {
                // Verifica se há outra rainha na mesma coluna ou na diagonal
                if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
                    return false;
                }
            }
            return true;
        }

        void solveNQueens(vector<int>& board, int row, vector<vector<int>>& solutions) {
            if (row == N) {
                solutions.push_back(board);
                return;
            }

            for (int col = 0; col < N; col++) {
                if (isSafe(board, row, col)) {
                    board[row] = col;
                    solveNQueens(board, row + 1, solutions);
                }
            }
        }

        int main() {
            vector<int> board(N, -1);
            vector<vector<int>> solutions;
            solveNQueens(board, 0, solutions);

            for (const auto& solution : solutions) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (solution[i] == j)
                            cout << "Q ";
                        else
                            cout << ". ";
                    }
                    cout << endl;
                }
                cout << endl;
            }

            return 0;
        }

        ```
        ### Aplicações do Backtracking
        - Soluções de quebra-cabeças: Como Sudoku, palavras cruzadas e jogos de tabuleiro.
        - Problemas de combinação: Como a geração de todas as combinações de um conjunto de itens ou a resolução de problemas de caminho em grafos.
        - Problemas de otimização: Como o problema da mochila ou problemas de programação de horários.