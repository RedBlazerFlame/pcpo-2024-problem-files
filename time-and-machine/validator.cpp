#include "testlib.h"
using namespace std;
typedef long long ll;

const ll h_max = 8766000;
const ll m_max = 59;
const ll s_max = 59;

int main(int argc, char ** argv) {
    // Required line
    registerValidation(argc, argv);

    /*
    Format:
    h m s
    */
    ll h, m, s;
    h = inf.readLong(0, h_max, "h");
    inf.readSpace();
    m = inf.readLong(0, m_max, "m");
    inf.readSpace();
    s = inf.readLong(0, s_max, "s");
    
    // I found that adding an extra end of line at
    // the end of the test case helps
    inf.readEoln();
    inf.readEof();

    return 0;
}