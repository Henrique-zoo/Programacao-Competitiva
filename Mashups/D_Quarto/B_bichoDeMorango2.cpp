#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<char>>& bolo, vector<vector<bool>>& visited, int i, int j) {
    int r = bolo.size();
    int c = bolo[0].size();
    
    if (i < 0 || i >= r || j < 0 || j >= c || visited[i][j] || bolo[i][j] == 'S')
        return 0;

    visited[i][j] = true;

    int count1 = 1, count2 = 1;
    for (int col = 0; col < c; ++col)
        if (!visited[i][col] && bolo[i][col] == '.')
            count1 += dfs(bolo, visited, i, col);
    for (int linha = 0; linha < r; ++linha)
        if (!visited[linha][j] && bolo[linha][j] == '.')
            count2 += dfs(bolo, visited, linha, j);
    return max(count1, count2);
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> bolo(r, vector<char>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> bolo[i][j];
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int pedacosComidos = -1;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (bolo[i][j] == '.' && !visited[i][j])
                pedacosComidos += dfs(bolo, visited, i, j);

    cout << pedacosComidos << endl;
    return 0;
}