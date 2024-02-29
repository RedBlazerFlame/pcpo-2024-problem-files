#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;

const int max_nodes = 328;
const int max_n = max_nodes - 1;
const int max_name_length = 20;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    set<string> found_names;
    int n = inf.readInt(0, max_n, "n");
    inf.readEoln();
    int num_edges = 0;

    for(int i = 0; i < n; i ++) {
        int num_spread = inf.readInt(0, max_n, "m");
        inf.readEoln();
        string spreader = inf.readToken();
        found_names.insert(spreader);
        ensuref(spreader.size() <= max_name_length, "Names must not be more than %d characters long", max_name_length);
        inf.readEoln();
        vector<string> spreadees;
        num_edges += num_spread;
        for(int j = 0; j < num_spread; j++) {
            string spreadee = inf.readToken();
            if(j < num_spread - 1) inf.readSpace();
            found_names.insert(spreadee);
            ensuref(spreadee.size() <= max_name_length, "Names must not be more than %d characters long", max_name_length);
            spreadees.push_back(spreadee);
        }
        inf.readEoln();
    }
    inf.readEof();
    ensuref(found_names.size() <= max_nodes, "There must be at most %d people", max_nodes);
    ensuref(found_names.size() == num_edges + 1, "Trees must consist of exactly n nodes and n - 1 edges for some integer n, not V = %d and E = %d", found_names.size(), num_edges);

    return 0;
}