#include "testlib.h"
using namespace std;
typedef long long ll;

ll MAX_S = 300'000ll;

ll isqrt(ll n) {
    ll l = 0, r = n + 3ll;
    while(r - l > 1) {
        ll m = (l + r) >> 1;
        if(m * m > n) r = m;
        else l = m;
    }

    return l;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    ll N = opt<ll>("N");
    ll MAX_DUR = opt<ll>("D");
    ll total_edges = 0ll;
    vector<vector<ll>> ipas;
    vector<vector<ll>> rand_ipas;
    for(ll i = 0ll; i < N; i++) {
        vector<ll> row, r_ipas_row;
        ll num_edges_to_add = rnd.next(0ll, isqrt(i));
        vector<ll> candidates = rnd.distinct(num_edges_to_add, i);
        for(ll candidate : candidates) {
            if(total_edges < MAX_S) {
                row.push_back(candidate + 1ll);
                total_edges++;
            }
        }
        
        ipas.push_back(row);
        rand_ipas.push_back(r_ipas_row);
    }
    vector<ll> label = rnd.perm(N, 1ll);
    vector<ll> label_inv(N, 0ll);
    for(ll i = 0ll; i < N; i++) {
        label_inv[label[i] - 1ll] = i + 1ll;
    }
    for(ll i = 0ll; i < N; i++) {
        vector<ll> cur_ipas_unmodified = ipas[label[i] - 1ll];

        for(ll ipa : cur_ipas_unmodified) {
            rand_ipas[i].push_back(label_inv[ipa - 1ll]);
        }
    }

    cout << N << endl;
    for(ll i = 0ll; i < N; i++) {
        cout << i + 1ll << " ";
        cout << rnd.next(1ll, MAX_DUR) << " ";
        cout << ipas[i].size();
        for(ll ipa : ipas[i]) {
            cout << " " << ipa;
        }
        cout << endl;
    }

    return 0;
}