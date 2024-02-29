#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int X = opt<int>("X");
    int n = opt<int>("N");
    int max_price = opt<int>("P");
    set<int> prices;

    cout << X << " " << n << "\n";
    for(int i = 0; i < n; ) {
        int cur_price = rnd.next(1, max_price);
        if(prices.count(cur_price) > 0) continue;
        prices.insert(cur_price);
        cout << cur_price;
        if(i < n - 1) cout << " ";
        i++;
    }

    cout << "\n";

    return 0;
}