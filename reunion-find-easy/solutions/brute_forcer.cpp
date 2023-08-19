#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> mat;
    for(int i = 0; i < n; i++) {
        vector<bool> row(n, false);
        mat.push_back(row);
    }

    int s, e;
    cin >> s >> e;
    s--; e--;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        mat[u][v] = true;
        mat[v][u] = true;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
                mat[j][i] = mat[i][j];
            }
        }
    }

    cout << (mat[s][e] ? "SAIKAI" : "KONAI SAIKAI") << endl;

    return 0;
}