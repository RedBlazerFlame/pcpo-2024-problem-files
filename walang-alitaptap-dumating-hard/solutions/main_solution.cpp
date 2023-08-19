// O(n^2) DP solution
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int def_access(const vector<vector<int>>& arr, int i, int j, int def) {
    int n = arr.size(), m = arr[0].size();

    return (i < 0 || i >= n || j < 0 || j >= m) ? def : arr[i][j];
}

vector<vector<int>> largest_square;
int find_largest(const vector<vector<bool>>& grid, bool flip) {
    int n = largest_square.size(), m = largest_square[0].size();

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            largest_square[i][j] = (grid[i][j] != flip ? 0 : min({def_access(largest_square, i - 1, j, 0), def_access(largest_square, i, j - 1, 0), def_access(largest_square, i - 1, j - 1, 0)}) + 1);
            ans = max(ans, largest_square[i][j]);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    largest_square.reserve(n);

    vector<vector<bool>> g;
    for(int i = 0; i < n; i ++) {
        vector<bool> row;
        vector<int> largest_square_row(n, 0);
        largest_square.push_back(largest_square_row);
        for(int j = 0; j < n; j ++) {
            bool v;
            cin >> v;

            row.push_back(v != (((i + j) & 0b1) == 0b0));
        }

        g.push_back(row);
    }

    cout << max(find_largest(g, false), find_largest(g, true)) << endl;

    return 0;
}