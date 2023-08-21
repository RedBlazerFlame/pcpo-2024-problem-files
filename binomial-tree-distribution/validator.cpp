#include "testlib.h"
using namespace std;
typedef long long ll;

const ll max_n = 200'000ll;
const ll max_m = 200'000ll;

int main(int argc, char** argv) {
    // TODO
    registerValidation(argc, argv);
    
    ll N = inf.readInt(1, max_n, "N");
    inf.readSpace();
    ll M = inf.readInt(1, min(max_m, (max_n * (max_n - 1)) >> 1), "M");
    inf.readEoln();

    ll cnana = inf.readInt(1, N, "C_nana");
    inf.readSpace();
    ll clili = inf.readInt(1, N, "C_lili");
    inf.readEoln();

    set<pair<ll, ll>> found;

    for(ll i = 0; i < M; i++) {
        ll u = inf.readInt(1, N, "u_" + to_string(i + 1));
        inf.readSpace();
        ll v = inf.readInt(1, N, "v_" + to_string(i + 1));
        inf.readEoln();

        ensuref(u != v, "No city must have a road connecting to itself");
        ensuref(found.count({min(u, v), max(u, v)}) == 0, "All (u_i, v_i) must be distinct");

        found.insert({min(u, v), max(u, v)});
    }

    inf.readEof();
    return 0;
}