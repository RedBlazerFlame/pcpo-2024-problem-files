#include "testlib.h"
using namespace std;
typedef long long ll;

const ll max_n = 200'000ll;
const ll max_s = 300'000ll;
const ll max_d = 1'000ll;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    
    ll cur_sum_s = 0ll;
    ll N = inf.readLong(1, max_n, "N");
    set<ll> activity_occurrences;
    inf.readEoln();
    for(ll i = 0ll; i < N; i++) {
        ll n_i = inf.readLong(1, N, "i");
        activity_occurrences.insert(n_i);
        inf.readSpace();
        ll dur = inf.readLong(1, max_d, "d");
        inf.readSpace();
        ll spi = inf.readLong(0, max_s, "s");
        for(ll j = 0ll; j < spi; j++) {
            inf.readSpace();
            ll pi = inf.readLong(1, N, "pi");
        }
        cur_sum_s += spi;
        inf.readEoln();
    }
    inf.readEof();
    ensuref(activity_occurrences.size() == N, "Each activity must appear exactly once");
    ensuref(cur_sum_s <= max_s, "There must be at most 300000 edges");
    return 0;
}