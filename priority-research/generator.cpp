#include "testlib.h"
using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    ll n = opt<ll>("n");

    cout << n << "\n";

    return 0;
}