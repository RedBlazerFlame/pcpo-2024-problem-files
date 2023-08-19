#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    for(int i = 0; i < n; i++) {
        vector<int> row;
        adj.push_back(row);
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> comp(n, 0);
    int cid = 1;

    for(int i = 0; i < n; i++) {
        if(comp[i] == 0) {
            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int i = q.front();
                q.pop();

                if(comp[i] != 0) continue;
                comp[i] = cid;

                for(int j : adj[i]) {
                    q.push(j);
                }
            }

            cid++;
        }
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        cout << (comp[s] == comp[e] ? "" : "KONAI ") << "SAIKAI" << endl;
    }

    return 0;
}