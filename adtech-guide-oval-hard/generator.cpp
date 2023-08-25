#include "testlib.h"
using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    ll Q = opt<ll>("Q");
    ll MAX_N = opt<ll>("MAXN");

    cout << Q << "\n";
    while(Q--) {
        ll N = rnd.next(1ll, MAX_N);
        ll x = rnd.next(0ll, 4ll * N - 1ll);
        ll y = rnd.next(0ll, 3ll * N - 1ll);

        cout << N << " " << x << " " << y << "\n";
    }

    return 0;
}