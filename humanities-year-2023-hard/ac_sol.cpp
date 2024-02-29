#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll nm210 = n % 210ll;
    ll num_nice = 0ll;
    ll num_nice_lt_nm210 = 0ll;
    for(ll i = 0; i < 210ll; i++) {
        ll count = 0ll;
        if(i % 2 == 1) count++;
        if(i % 3 == 2) count++;
        if(i % 5 == 3) count++;
        if(i % 7 == 5) count++;
        if(count == k) {
            num_nice ++;
            if(i <= nm210) num_nice_lt_nm210++;
        }
    }
    cout << (n / 210) * num_nice + num_nice_lt_nm210 - (k == 0 ? 1 : 0) << endl;
    return 0;
}