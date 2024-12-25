#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cubos;
    int aux, sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> aux;
        cubos.push_back(aux);
        sum += aux;
    }

    bool possivel = true, possivel2 = false;
    auto it = max_element(cubos.begin(), cubos.end());
    if (*it * 3 != sum)
        possivel = false;

    if (possivel)
        for (int i = 0; i < 6; i++)
            if (i != (it - cubos.begin()))
                for (int j = i; j < 6; j++)
                    if (cubos[i] + cubos[j] == *it) {
                        possivel2 = true;
                        break;
                    }

    if (possivel2)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}