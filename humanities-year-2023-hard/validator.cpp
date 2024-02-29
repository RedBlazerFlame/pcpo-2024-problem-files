#include "testlib.h"
using namespace std;
typedef long long ll;

const ll max_n = 1'000'000'000'000'000'000ll;
const ll max_k = 4;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    inf.readLong(1, max_n, "N");
    inf.readSpace();
    inf.readLong(0, max_k, "K");
    inf.readEoln();
    inf.readEof();

    return 0;
}