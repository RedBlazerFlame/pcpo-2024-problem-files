#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int NUM_CORES = 3;
const int NUM_ELECS = 7;
const int MAX_INFLUENCING_FACTOR = 100;
const int MAX_N_BF = 5;
const int MAX_N_F = 200;

int main(int argc, char** argv) {
    set<string> poss_cores;
    poss_cores.insert("chem");
    poss_cores.insert("phys");
    poss_cores.insert("bio");
    
    set<string> poss_elecs;
    poss_elecs.insert("cs");
    poss_elecs.insert("chem");
    poss_elecs.insert("phys");
    poss_elecs.insert("tech");
    poss_elecs.insert("engg");
    poss_elecs.insert("agri");
    poss_elecs.insert("bio");
    registerValidation(argc, argv);

    set<string> given_cores;
    set<string> given_elecs;

    for(int i = 0; i < NUM_CORES; i++) {
        string cur_core = inf.readString();
        given_cores.insert(cur_core);
        if(i < NUM_CORES - 1) inf.readSpace();
    }
    inf.readEoln();
    ensuref(given_cores == poss_cores, "The given cores are not a permutation of [chem, phys, bio]");

    for(int i = 0; i < NUM_ELECS; i++) {
        string cur_elec = inf.readString();
        given_elecs.insert(cur_elec);
        if(i < NUM_ELECS - 1) inf.readSpace();
    }
    inf.readEoln();
    ensuref(given_elecs == poss_elecs, "The given electives are not a permutation of [chem, phys, bio, cs, tech, engg, agri]");
    
    int if_bf = inf.readInt(0, MAX_INFLUENCING_FACTOR, "if_bf");
    inf.readSpace();

    int n_bf = inf.readInt(0, MAX_N_BF, "n_bf");
    inf.readEoln();

    for(int i = 0; i < n_bf; i++) {
        string fname = inf.readString();
        inf.readSpace();

        string fcore = inf.readString();
        ensuref(poss_cores.count(fcore) == 1, "Best friend's core must be either chem, phys, or bio (%s)", fname);
        inf.readSpace();

        string felec = inf.readString();
        ensuref(poss_elecs.count(felec) == 1, "Best friend's elective must be either chem, phys, bio, cs, tech, engg, or agri (%s)", fname);
        inf.readEoln();
    }

    int if_f = inf.readInt(0, MAX_INFLUENCING_FACTOR, "if_f");
    inf.readSpace();

    int n_f = inf.readInt(0, MAX_N_F, "n_f");
    inf.readEoln();

    for(int i = 0; i < n_f; i++) {
        string fname = inf.readString();
        inf.readSpace();

        string fcore = inf.readString();
        ensuref(poss_cores.count(fcore) == 1, "Friend's core must be either chem, phys, or bio (%s)", fname);
        inf.readSpace();

        string felec = inf.readString();
        ensuref(poss_elecs.count(felec) == 1, "Friend's elective must be either chem, phys, bio, cs, tech, engg, or agri (%s)", fname);
        inf.readEoln();
    }

    int if_c = inf.readInt(0, MAX_INFLUENCING_FACTOR, "if_c");

    string cname = inf.readString();
    inf.readSpace();

    string ccore = inf.readString();
    ensuref(poss_cores.count(ccore) == 1, "Crush's core must be either chem, phys, or bio (%s)", cname);
    inf.readSpace();

    string celec = inf.readString();
    ensuref(poss_elecs.count(celec) == 1, "Crush's elective must be either chem, phys, bio, cs, tech, engg, or agri (%s)", cname);
    inf.readEoln();
    inf.readEof();

    return 0;
}