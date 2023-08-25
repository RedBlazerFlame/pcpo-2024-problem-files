#include "testlib.h"
using namespace std;
typedef long long ll;

const ll max_n = 1'000'000'000'000'000'000ll;
const ll max_q = 50'000ll;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    
    ll Q = inf.readLong(1, max_q, "Q");
    inf.readEoln();
    while(Q--) {
        ll N = inf.readLong(1, max_n, "N");
        inf.readSpace();
        ll x = inf.readLong(0, 4 * N - 1, "x");
        inf.readSpace();
        ll y = inf.readLong(0, 3 * N - 1, "y");
        inf.readEoln();
    }
    inf.readEof();

    return 0;
}