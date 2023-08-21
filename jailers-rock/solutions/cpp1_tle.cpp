#include<iostream>
#include<utility>
#include<cstdlib>

using namespace std;
typedef long long ll;

pair<ll, ll> solve(ll A) {
    pair<ll, ll> ans = {-1ll, -1ll};
    for(ll i = 1; i <= A; i++) {
        if(A % i != 0) continue;
        ll f2 = A / i;
        if((i + f2) & 0b1ll != 0ll) continue;
        ans = {abs(f2 - i) >> 1ll, (f2 + i) >> 1ll};
        break;
    }
    if(min(ans.first, ans.second) == 0ll) ans = {-1ll, -1ll};
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