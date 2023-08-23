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
    ll N;
    cin >> N;

    ll X = 4 * N, Y = 3 * N;

    for(ll y = 0ll; y < Y; y++) {
        for (ll x = 0ll; x < X; x++) {
            cout << (isGrass(N, x, y) ? "-" : "#");
        }
        cout << "\n";
    }

    cout << flush;

    return 0;
}