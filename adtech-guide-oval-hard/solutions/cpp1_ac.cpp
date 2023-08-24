#include<iostream>
using namespace std;
typedef long long ll;

bool isGrass(ll N, ll x, ll y) {
    ll X = 4 * N, Y = 3 * N;

    if(x > (X / 2)) x = X - x - 1ll;
    if(y > (Y / 2)) y = Y - y - 1ll;
    return (x + y < N) || (x >= N && y >= N);
}

int main() {
    ll Q;
    cin >> Q;

    while(Q--) {
        ll N, x, y;
        cin >> N >> x >> y;

        cout << (isGrass(N, x, y) ? "-" : "#") << "\n";
    }

    cout << flush;

    return 0;
}