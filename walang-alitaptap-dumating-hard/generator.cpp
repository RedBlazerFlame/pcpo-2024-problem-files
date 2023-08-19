#include "testlib.h"
using namespace std;
typedef long long ll;

int def_access(const vector<vector<int>>& arr, int i, int j, int def) {
    int n = arr.size(), m = arr[0].size();

    return (i < 0 || i >= n || j < 0 || j >= m) ? def : arr[i][j];
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    const int max_tries = 100;
    int n = opt<int>("n");
    int rects = opt<int>("rectangles");
    int max_side_length = opt<int>("max_side_length");

    cout << n << endl;

    vector<vector<int>> pref;

    for(int i = 0; i < n + 1; i++) {
        vector<int> row(n + 1, 0);
        pref.push_back(row);
    }

    for(int i = 0; i < rects; i++) {
        int x0, y0, x1, y1;
        
        do {
            x0 = rnd.next(0, n - 1), y0 = rnd.next(0, n - 1), x1 = rnd.next(0, n - 1), y1 = rnd.next(0, n - 1);

            if(x0 > x1) swap(x0, x1);
            if(y0 > y1) swap(y0, y1);
        } while((x1 - x0) > max_side_length || (y1 - y0) > max_side_length);

        pref[y0][x0] += 1;
        pref[y0][x1 + 1] += -1;
        pref[y1 + 1][x0] += -1;
        pref[y1 + 1][x1 + 1] += 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pref[i][j] += def_access(pref, i - 1, j, 0);
            pref[i][j] += def_access(pref, i, j - 1, 0);
            pref[i][j] -= def_access(pref, i - 1, j - 1, 0);
            cout << (pref[i][j] > 0 ? (i + j) & 0b1 : rnd.next(0, 1));
            if(j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    cout << flush;

    return 0;
}