#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, long long> merge_and_count(vector<int>& esq, vector<int>& dir) {
    vector<int> resultado;
    int i = 0, j = 0;
    long long contador = 0;

    while (i < esq.size() && j < dir.size()) {
        if (esq[i] <= dir[j])
            resultado.push_back(esq[i++]);
        else {
            resultado.push_back(dir[j++]);
            contador += esq.size() - i;
        }
    }

    while (i < esq.size())
        resultado.push_back(esq[i++]);

    while (j < dir.size())
        resultado.push_back(dir[j++]);

    return {resultado, contador};
}

pair<vector<int>, long long> contaTrocas(vector<int>& v) {
    if (v.size() < 2)
        return {v, 0};

    int mid = v.size() / 2;
    vector<int> esq(v.begin(), v.begin() + mid);
    vector<int> dir(v.begin() + mid, v.end());

    pair<vector<int>, long long> esq_resultado = contaTrocas(esq);
    pair<vector<int>, long long> dir_resultado = contaTrocas(dir);

    pair<vector<int>, long long> merge_resultado = merge_and_count(esq_resultado.first, dir_resultado.first);

    long long trocasTotais = esq_resultado.second + dir_resultado.second + merge_resultado.second;

    return {merge_resultado.first, trocasTotais};
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; ++i)
        cin >> p[i];

    pair<vector<int>, long long> resultado = contaTrocas(p);
    long long trocas = resultado.second;

    if (!(trocas % 2))
        cout << "Carlos" << endl;
    else
        cout << "Marcelo" << endl;

    return 0;
}
