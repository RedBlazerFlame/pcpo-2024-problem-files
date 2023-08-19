#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    public:
        vector<int> par;
        vector<int> csize;
        int n;

        UnionFind(int a_n): n(a_n) {
            for(int i = 0; i < n; i++) {
                par.push_back(i);
                csize.push_back(1);
            }
        }

        int find(int i) {
            int orig = i;

            while(i != par[i]) {
                i = par[i];
            }

            while(orig != par[orig]) {
                int neworig = par[orig];
                par[orig] = i;

                orig = neworig;
            }
            
            return i;
        }

        bool connected(int i, int j) {
            return find(i) == find(j);
        }

        void unify(int i, int j) {
            int pari = find(i);
            int parj = find(j);

            if(pari == parj) return;

            if(csize[pari] < csize[parj]) {
                par[pari] = parj;
                csize[parj] += csize[pari];
            } else {
                par[parj] = pari;
                csize[pari] += csize[parj];
            }
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        uf.unify(u, v);
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        cout << (uf.connected(s, e) ? "" : "KONAI ") << "SAIKAI" << endl;
    }

    return 0;
}