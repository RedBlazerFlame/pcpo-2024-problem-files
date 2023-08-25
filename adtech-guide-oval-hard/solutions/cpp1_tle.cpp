#include <iostream>
using namespace std;
typedef long long ll;

char solve(ll N, ll x, ll y) {
    ll curx = 0;
    ll cury = 0;
    char cur_cell;
    
    for(ll i = 0; i < N; i++) {
        curx = 0;
        for(ll j = 0; j < N - i; j++) {
            if(x == curx && y == cury) return '-';
            curx++;
        }

        for(ll j = 0; j < 2 * (N + i); j++) {
            if(x == curx && y == cury) return '#';
            curx++;
        }

        for(ll j = 0; j < N - i; j++) {
            if(x == curx && y == cury) return '-';
            curx++;
        }

        cury++;
    }

    for(ll i = 0; i < N; i++) {
        curx = 0;
        for(ll j = 0; j < N; j++) {
            if(x == curx && y == cury) return '#';
            curx++;
        }

        for(ll j = 0; j < 2 * N; j++) {
            if(x == curx && y == cury) return '-';
            curx++;
        }

        for(ll j = 0; j < N; j++) {
            if(x == curx && y == cury) return '#';
            curx++;
        }

        cury++;
    }

    for(ll i = 0; i < N; i++) {
        curx = 0;
        for(ll j = 0; j < i + 1; j++) {
            if(x == curx && y == cury) return '-';
            curx++;
        }

        for(ll j = 0; j < 4 * N - 2 * (i + 1); j++) {
            if(x == curx && y == cury) return '#';
            curx++;
        }

        for(ll j = 0; j < i + 1; j++) {
            if(x == curx && y == cury) return '-';
            curx++;
        }

        cury++;
    }
}

int main() {
    ll Q;
    cin >> Q;
    
    while(Q--) {
        ll N, x, y;
        cin >> N >> x >> y;

        cout << solve(N, x, y) << "\n";
    }

    cout << flush;

    return 0;
}