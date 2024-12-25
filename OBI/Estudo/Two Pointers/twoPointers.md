# Vetor
- É uma estrutura de dados que aloca memória dinâmicamente
- O tipo dos elementos é definido a priori
- Métodos do vector
```cpp
int main() {
    vector<int> v;
    // adiciona o elemento 7 ao vetor
    v.push_back(7);
    // remove o elemento na primeira posição do vetor
    v.pop_back();
    // ordena o vetor de forma crescente
    sort(v.begin(), v.end())
    // ordena o vetor de ordem decrescente
    sort(v.begin(), v.end(), greater<int>())
}

```