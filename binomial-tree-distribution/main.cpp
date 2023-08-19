#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 999983ll;

inline ll mod(ll n) {
    return ((n % MOD) + MOD) % MOD;
}

ll solve(ll n) {
    if(n == 0ll) return 1ll;
    ll cur_prod = 1ll;
    ll cur_term = 1ll;
    ll next_term = 1ll;

    for(ll i = 0; i < n; i++) {
        cur_prod = (cur_prod * cur_term) % MOD;
        next_term = (cur_term + cur_prod) % MOD;
        if(i == n - 1) cur_term = next_term;
    }

    return mod(next_term - cur_term);
}

ll seq(ll n) {
    if(n == 0ll) return 1ll;
    ll cur_prod = 1ll;
    ll cur_term = 1ll;
    ll next_term = 1ll;

    for(ll i = 0; i < n; i++) {
        cur_prod = (cur_prod * cur_term) % MOD;
        next_term = (cur_term + cur_prod) % MOD;
        if(i > n - 20ll) cout << i + 1 << ": " << mod(next_term - cur_term) << endl;
        cur_term = next_term;
    }

    return next_term;
}

int main() {
    seq(1075368ll);

    return 0;
}