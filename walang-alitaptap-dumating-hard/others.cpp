#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<bool>> generate_firefly_square(int s) {
    vector<vector<bool>> res;
    for(int i = 0; i < s; i++) {
        vector<bool> row(s, 0);
        for(int j = 0; j < s; j++) {
            row[j] = (((i & 0b11) == 0b00 && (j & 0b1) == 0b0) || ((i & 0b11) == 0b10 && (j & 0b1) == 0b1));
        }
        res.push_back(row);
    }
    return res;
}

void print_grid(const vector<vector<bool>>& g) {
    int n = g.size();
    int m = g[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << flush;
}