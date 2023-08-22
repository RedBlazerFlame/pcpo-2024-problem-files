#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const auto GENERIC_WORD_PATTERN = "[a-zA-Z]+";

ll A;

vector<string> read_answer(InStream &stream) {
    vector<string> res;

    auto token = upperCase(stream.readToken(GENERIC_WORD_PATTERN, "token"));
    stream.quitif(token != "IMPOSSIBLE" && token != "POSSIBLE", _pe,
                    "Expected IMPOSSIBLE or POSSIBLE token, but found \"%s\"",
                    token.c_str());
    res.push_back(token);

    if(token == "POSSIBLE") {
        res.push_back(std::to_string(stream.readLong(1ll, 1'000'000'000ll, "d1")));
        res.push_back(std::to_string(stream.readLong(1ll, 1'000'000'000ll, "d2")));
    }

    stream.quitif(!stream.seekEof(), _pe, "Expected EOF");

    return res;
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    A = inf.readInt();

    auto pa = read_answer(ouf);
    auto ja = read_answer(ans);
    ll computed_j_A, computed_p_A;

    if(ja[0ll] == "POSSIBLE") {

        computed_j_A = stoll(ja[2ll]) * stoll(ja[2ll]) - stoll(ja[1ll]) * stoll(ja[1ll]);

        if(computed_j_A != A) {
            quitf(_fail, "The jury returned an incorrect possible answer: d1 = %d, d2 = %d (d2^2 - d1^2 = %d =/= %d)", stoll(ja[1ll]), stoll(ja[2ll]), computed_j_A, A);
        }
    }

    if(pa[0ll] == "POSSIBLE") {
        computed_p_A = stoll(pa[2ll]) * stoll(pa[2ll]) - stoll(pa[1ll]) * stoll(pa[1ll]);

        if(computed_p_A != A) {
            quitf(_wa, "The participant returned an incorrect possible answer: d1 = %d, d2 = %d (d2^2 - d1^2 = %d =/= %d)", stoll(pa[1ll]), stoll(pa[2ll]), computed_p_A, A);
        }
    }

    if(ja[0ll] == "POSSIBLE" && pa[0ll] == "IMPOSSIBLE") {
        quitf(_wa, "The judge found a correct possible answer, but the participant did not.");
    }

    if(pa[0ll] == "POSSIBLE" && ja[0ll] == "IMPOSSIBLE") {
        quitf(_fail, "The participant found a correct possible answer, but the judge did not.");
    }

    quitf(_ok, "The output is correct");

    return 0;
}