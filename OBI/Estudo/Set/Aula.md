## std::set
- Sets são containers que armazenam elementos únicos em uma ordem específica;
- Funciona em complexidade O(log(n));
- Elementos duplicados não são inseridos;
- É implementado, basicamente como um vetor, mas o funcionamento é diferente.
    ```cpp
    #include <bits/stdc++.h>
    int main() {
        set<int> s;
        s.insert(1);
        s.insert(3);
        s.insert(2);
        s.insert(3);
        // s = [1, 2, 3]
        s.size(); // retorna a quantidade de elementos no set
        s.empty(); // retorna 1 se o set está vazio
    }
    ```
### Peculiaridades do set
- O set tem funções que facilitam muito a vida do competidor, como lower_bound() e upper_bound()
- O lower_bound() retorna a posição de memória do menor número maior ou igual ao número procurado
- O upper_bound() retorna a posição de memória do menor número maior do que o número procurado
    ```cpp
    #include <bits/stdc++.h>
    int main() {
        set<int> s;
        s.insert(1);
        s.insert(3);
        s.insert(2);
        s.insert(3);
        auto it lower_bound(s.begin(), s.end(), 5);
        if (it != s.end()) {
            cout << "O elemento está no vetor\n";
        }
    }
    ```