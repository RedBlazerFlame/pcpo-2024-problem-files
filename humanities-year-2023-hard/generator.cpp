#include "testlib.h"
using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    ll N = opt<ll>("N");
    ll K = opt<ll>("K");

    cout << N << " " << K << "\n";

    return 0;
}