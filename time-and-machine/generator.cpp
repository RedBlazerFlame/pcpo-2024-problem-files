#include "testlib.h"
using namespace std;
typedef long long ll;

int main(int argc, char ** argv) {
    // Required Line
    registerGen(argc, argv);

    // Reading options
    ll h = opt<ll>("H");
    ll m = opt<ll>("M");
    ll s = opt<ll>("S");

    // Creating the test case
    cout << h << " " << m << " " << s << endl;

    return 0;
}