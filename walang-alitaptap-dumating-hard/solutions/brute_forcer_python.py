"""
#include <bits/stdc++.h>
using namespace std;

/*
This brute forcer runs in O(n^5)
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
    for(int s = 1; s <= n; s++) {
        if(is_poss(grid, s)) ans = max(ans, s);
    }

    cout << ans << endl;

    return 0;
}
"""

n = int(input())

grid = []

for i in range(n):
    grid.append(list(map(lambda x: bool(int(x)), input().split(" "))))

def is_firefly_square(g, x, y, s):
    init_square_is_bush = g[y][x]
    for i in range(s):
        for j in range(s):
            if(((i + j) & 0b1) == 0b0 and g[i + y][j + x] != init_square_is_bush): return False
            if(((i + j) & 0b1) == 0b1 and g[i + y][j + x] == init_square_is_bush): return False
    return True

def is_poss(g, s):
    poss = False
    n = len(g)
    for y0 in range(n - s + 1):
        for x0 in range(n - s + 1):
            if(is_firefly_square(g, x0, y0, s)): poss = True
    return poss

ans = 0

for s in range(1, n + 1):
    if(is_poss(grid, s)): ans = s

print(ans)