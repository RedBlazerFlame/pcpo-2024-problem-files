#include "testlib.h"
using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    ll A = opt<ll>("A");

    cout << A << "\n";

    return 0;
}