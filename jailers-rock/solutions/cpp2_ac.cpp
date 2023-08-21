/*
(d2 - d1)(d2 + d1) = A
*/
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;

pair<ll, ll> solve(ll A) {
    pair<ll, ll> ans = {-1ll, -1ll};
    for(ll i = 1; i * i < A; i++) {
        if(A % i != 0) continue;
        ll f2 = A / i;
        if((i + f2) & 0b1ll != 0ll) continue;
        ans = {(f2 - i) >> 1ll, (f2 + i) >> 1ll};
    }
    return ans;
}

int main() {
    ll A;
    cin >> A;
    pair<ll, ll> res = solve(A);

    if(res.first == -1ll) cout << "impossible" << endl;
    else {
        cout << "possible" << endl;
        cout << res.first << " " << res.second << endl;
    }

    return 0;
}