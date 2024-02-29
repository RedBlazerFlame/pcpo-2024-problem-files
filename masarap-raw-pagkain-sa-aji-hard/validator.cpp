#include "testlib.h"
using namespace std;
typedef long long ll;

const int max_X = 10000;
const int max_n = 10;
const int max_p = 1000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    
    int X = inf.readInt(1, max_X, "X");
    inf.readSpace();
    int n = inf.readInt(1, max_n, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++) {
        int p = inf.readInt(1, max_p, "p");
        if(i < n - 1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();

    return 0;
}