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
    registerGen(argc, argv, 1);
    const int max_tries = 100;
    int nodes = opt<int>("nodes");
    int edges = opt<int>("edges");
    int num_yes = opt<int>("yescount");
    int num_no = opt<int>("nocount");
    int q = num_yes + num_no;

    cout << nodes << " " << edges << "\n";

    set<pair<int, int>> edge_set;
    vector<pair<int, int>> edge_list;
    set<pair<int, int>> queries_set;
    vector<pair<int, int>> queries_list;

    while(true) {
        edge_set.clear();
        edge_list.clear();
        queries_set.clear();
        queries_list.clear();
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

        bool failed = false;
        for(int i = 0; i < num_yes; i++) {
            int tries = 0;
            int cnana, clili;
            do {

                cnana = rnd.next(1, nodes);
                clili = rnd.next(1, nodes);
                tries ++;
            } while((queries_set.count({min(cnana, clili), max(cnana, clili)}) > 0 || cnana == clili || (!uf.connected(cnana - 1, clili - 1))) && tries <= max_tries);
            if(queries_set.count({min(cnana, clili), max(cnana, clili)}) > 0 || cnana == clili || (!uf.connected(cnana - 1, clili - 1))) {
                failed = true;
                break;
            }
            queries_set.insert({min(cnana, clili), max(cnana, clili)});
            queries_list.push_back({cnana, clili});
        }
        if(failed) continue;
        failed = false;
        for(int i = 0; i < num_no; i++) {
            int tries = 0;
            int cnana, clili;
            do {

                cnana = rnd.next(1, nodes);
                clili = rnd.next(1, nodes);
                tries ++;
            } while((queries_set.count({min(cnana, clili), max(cnana, clili)}) > 0 || cnana == clili || uf.connected(cnana - 1, clili - 1)) && tries <= max_tries);
            if(queries_set.count({min(cnana, clili), max(cnana, clili)}) > 0 || cnana == clili || uf.connected(cnana - 1, clili - 1)) {
                failed = true;
                break;
            }
            queries_set.insert({min(cnana, clili), max(cnana, clili)});
            queries_list.push_back({cnana, clili});
        }
        if(failed) continue;
        else break;
    }

    for(auto [u, v] : edge_list) {
        cout << u << " " << v << "\n";
    }

    vector<int> order = rnd.perm(q);

    cout << q << endl;

    for(int i : order) {
        cout << queries_list[i].first << " " << queries_list[i].second << endl;
    }

    return 0;
}