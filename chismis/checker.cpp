#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_word_size = 20;

vector<string> read_answer(InStream &stream) {
    vector<string> res;

    stringstream ss(stream.readLine());

    string word;
    while(ss >> word) {
        res.push_back(word);
        stream.quitif(word.size() > max_word_size, _pe, "The contestant/judge printed a name with more than %d characters", max_word_size);
    }

    return res;
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);

    vector<string> pa = read_answer(ouf);
    vector<string> ja = read_answer(ans);
    
    sort(pa.begin(), pa.end());
    sort(ja.begin(), ja.end());

    if(pa.size() != ja.size()) {
        quitf(_wa, "The judge found %d names, but the contestant found %d names", ja.size(), pa.size());
    }

    for(int i = 0; i < pa.size(); i++) {
        if(pa[i] != ja[i]) {
            quitf(_wa, "There was a mismatch between the contestant's and the judge's answers");
        }
    }

    quitf(_ok, "The output is correct");

    return 0;
}