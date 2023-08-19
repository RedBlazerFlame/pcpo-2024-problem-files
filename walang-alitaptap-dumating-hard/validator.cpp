#include "testlib.h"
using namespace std;
typedef long long ll;

const ll max_n = 1'000ll;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    
    ll N = inf.readInt(1, max_n, "N");
    inf.readEoln();

    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            ll g = inf.readInt(0, 1, "g_[" + to_string(i + 1) + "][" + to_string(j + 1) + "]");
            if(j < N - 1) inf.readSpace();
        }
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}