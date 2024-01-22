#include<bits/stdc++.h>
using namespace std;

int main() {
    /*
    This solution should fail
    because it uses 32-bit integers

    The values in the problem could become larger
    than the signed 32-bit integer limit
    (around 2.15 billion)

    When this happens, an integer overflow occurs
    */
    int h, m, s;
    cin >> h >> m >> s;
    cout << 3600 * h + 60 * m + s << endl;

    return 0;
}