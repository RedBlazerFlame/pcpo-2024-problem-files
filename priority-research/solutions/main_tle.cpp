#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 999983ll;

ll solve(ll n) {
    vector<ll> terms;
    terms.push_back(1ll);

    while(terms.size() <= n) {
        ll sum = 0ll;
        for(ll v : terms) {
            sum = (sum + v) % MOD;
        }
        terms.push_back((sum * terms[terms.size() - 1ll]) % MOD);
    }

    return terms[terms.size() - 1ll];
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}