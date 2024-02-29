#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0ll;
    for(ll i = 1; i <= n; i++) {
        ll count = 0ll;
        if(i % 2 == 1) count++;
        if(i % 3 == 2) count++;
        if(i % 5 == 3) count++;
        if(i % 7 == 5) count++;
        if(count == k) ans++; 
    }
    cout << ans << endl;
}