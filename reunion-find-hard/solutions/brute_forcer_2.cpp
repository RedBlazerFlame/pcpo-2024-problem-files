#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    int Q;
    cin >> Q;

    while(Q--) {
        int s, e;
        cin >> s >> e;
        s--; e--;
        bool found = false;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(s);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(vis[i]) continue;
            vis[i] = true;
            if(i == e) {
                found = true;
                break;
            }

            for(int j : adj[i]) {
                q.push(j);
            }
        }

        cout << (found ? "SAIKAI" : "KONAI SAIKAI") << endl;
    }

    return 0;
}