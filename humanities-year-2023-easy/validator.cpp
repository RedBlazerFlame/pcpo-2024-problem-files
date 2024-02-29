#include "testlib.h"
using namespace std;

const int max_n = 200'000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    inf.readInt(1, max_n, "N");
    inf.readEoln();
    inf.readEof();

    return 0;
}