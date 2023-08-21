#include "testlib.h"
using namespace std;
typedef long long ll;

class UnionFind {
    public:
        vector<int> par;
        vector<int> csize;
        int n;

        UnionFind(int a_n) : n(a_n) {
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

        bool connected(int i, int j) {
            return find(i) == find(j);
        }
};

int main(int argc, char** argv) {
    // TODO

    registerGen(argc, argv, 1);
    int nodes = opt<int>("nodes");
    int edges = opt<int>("edges");
    bool reachable = opt<bool>("reachable");

    cout << nodes << " " << edges << "\n";
    int cnana, clili;

    set<pair<int, int>> edge_set;
    vector<pair<int, int>> edge_list;
    while(true) {
        edge_set.clear();
        edge_list.clear();
        UnionFind uf(nodes);

        for(int i = 0; i < edges; i++) {
            int u, v;
            do {
                u = rnd.next(1, nodes);
                v = rnd.next(1, nodes);
            } while(u == v || edge_set.count({min(u, v), max(u, v)}) > 0);

            edge_set.insert({min(u, v), max(u,v)});
            edge_list.push_back({u, v});
            uf.unify(u - 1, v - 1);
        }


        int tries = 0;
        do {
            cnana = rnd.next(1, nodes);
            clili = rnd.next(1, nodes);
            tries ++;
        } while((cnana == clili || uf.connected(cnana - 1, clili - 1) != reachable) && tries <= 100);
        if(cnana != clili && uf.connected(cnana - 1, clili - 1) == reachable) break;
    }

    cout << cnana << " " << clili << "\n";

    for(auto [u, v] : edge_list) {
        cout << u << " " << v << "\n";
    }

    return 0;
}