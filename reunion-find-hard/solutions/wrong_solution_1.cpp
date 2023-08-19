#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        edges.insert({min(u, v), max(u, v)});
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        cout << (edges.count({min(s, e), max(s, e)}) > 0 ? "" : "KONAI ") << "SAIKAI" << endl;
    }

    return 0;
}