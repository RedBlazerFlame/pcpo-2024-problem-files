#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 999983ll;

ll solve(ll n) {
    if(n >= 1075364ll) return 0ll;
    ll cur_term = 1ll;
    ll cur_sum = 1ll;

    for(ll i = 0ll; i < n; i++) {
        cur_term = (cur_term * cur_sum) % MOD;
        cur_sum = (cur_sum + cur_term) % MOD;
    }

    return cur_term;
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}