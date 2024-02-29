#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans = 0ll;

    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1 && i % 3 == 2 && i % 5 == 3 && i % 7 == 5) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}