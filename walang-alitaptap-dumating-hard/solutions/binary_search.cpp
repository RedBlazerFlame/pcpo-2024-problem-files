#include <bits/stdc++.h>
using namespace std;

/*
This binary searcher runs in O(n^4 log n)
*/

bool is_firefly_square(const vector<vector<bool>>& g, int x, int y, int s) {
    bool init_square_is_bush = g[y][x];
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            if(((i + j) & 0b1) == 0b0 && g[i + y][j + x] != init_square_is_bush) return false;
            if(((i + j) & 0b1) == 0b1 && g[i + y][j + x] == init_square_is_bush) return false;
        }
    }
    return true;
}

bool is_poss(const vector<vector<bool>>& g, int s) {
    bool poss = false;
    int n = g.size();
    for(int y0 = 0; y0 < n - s + 1; y0++) {
        for(int x0 = 0; x0 < n - s + 1; x0++) {
            if(is_firefly_square(g, x0, y0, s)) poss = true;
        }
    }
    return poss;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<bool>> grid;
    for(int i = 0; i < n; i++) {
        vector<bool> row;
        
        for(int j = 0; j < n; j++) {
            bool v;
            cin >> v;
            row.push_back(v);
        }

        grid.push_back(row);
    }

    int ans = 0;
    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;

        if(is_poss(grid, m)) l = m;
        else r = m;
    }

    cout << l << endl;

    return 0;
}