#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NAMES_LENGTH = 329;
const int MAX_INFLUENCING_FACTOR = 100;
const int NUM_CORES = 3;
const int NUM_ELECS = 7;

int main(int argc, char** argv) {
    string names[] = {"nayeon", "momo", "jeongyeon", "sana", "mina", "tzuyu", "dahyun", "chaeyoung", "tetia", "richeh", "aggott", "qifrey", "olruggio", "olly", "alaira", "tartah", "ronron", "aron", "aaron", "emm", "em", "marie", "josette", "emma", "ray", "norman", "roy", "gilda", "don", "john", "anna", "ana", "anne", "nat", "nick", "thoma", "lannion", "b", "gabee", "gabby", "gabbie", "gabriel", "badeline", "madeline", "mads", "maddie", "apple", "peach", "raven", "blondie", "goldy", "goldie", "cerise", "goldee", "daring", "dexter", "darling", "briar", "yuri", "yor", "loid", "anya", "franky", "bond", "sylvia", "becky", "damian", "emile", "ewen", "twilight", "fiona", "shrek", "donkee", "donkey", "himawari", "mahito", "himi", "natsuko", "jiro", "nahoko", "kiki", "tombo", "howl", "sophie", "suliman", "calcifer", "shirayuki", "zen", "obi", "mitsuhide", "sora", "umi", "uchuu", "reuben", "kaze", "haku", "chihiro", "marnie", "emily", "kazuhiko", "nanny", "hisako", "sayaka", "oiwa", "sho", "arrietty", "haru", "spiller", "niya", "shun", "yuichiro", "sachiko", "shirou", "ryoko", "miki", "muta", "yuki", "humbert", "natoru", "muge", "hinode", "nana", "lili", "mikage", "spica", "urara", "yuuhi", "warawara", "kiriko", "suisei", "gura", "sheeta", "pazu", "muska", "dola", "louis", "charles", "jiji", "cloth", "hornet", "zote", "radiance", "quirrel", "cornifer", "minerva", "athena", "skye", "sky", "mary", "jane", "mj", "michael", "jackson", "monique", "jhoienyl", "jonel", "janelle", "mirai", "cress", "adan", "myu", "lauren", "sarah", "sara", "sera", "aydan", "eden", "lance", "ian", "ieuan", "sayoowee", "bumblebee", "mateo", "matteo", "matt", "carlo", "carlos", "inigo", "paolo", "paul", "amos", "talan", "marco", "polo", "kart", "bartholomew", "henry", "allen", "barry", "bart", "iris", "eris", "basti", "hr", "harrison", "harry", "hermione", "ron", "snape", "dumbledore", "cedric", "diggory", "myrtle", "luna", "cho", "molly", "percy", "annabeth", "penelope", "grover", "neville", "clarisse", "luke", "chiron", "cerebus", "dionysus", "sally", "asriel", "bratty", "catty", "tem", "tommy", "temmy", "temmie", "chara", "frisk", "undyne", "sans", "flowey", "ralsei", "kris", "susie", "toriel", "asgore", "mettaton", "toby", "papyrus", "paps", "tobi", "tauriel", "sussy", "sucy", "akko", "lotte", "lotty", "ursula", "diana", "lazurite", "lina", "doon", "alphonso", "randy", "rainbowdash", "pinkiepie", "applejack", "rarity", "twilightsparkle", "sparkle", "shoko", "shoya", "natsume", "porter", "skey", "lexi", "cob", "justine", "elarpi", "tong", "kui", "clerk", "delro", "saryo", "vick", "tor", "yah", "ordun", "au", "lychee", "pluto", "callisto", "io", "ganymede", "kay", "wymari", "stella", "carl", "leen", "lian", "tera", "jard", "mansi", "nido", "tow", "bee", "lapi", "tan", "jian", "ale", "minji", "danielle", "hanni", "hyein", "haerin", "yunjin", "heeseung", "jake", "jay", "jimin", "v", "rapmonster", "gabe", "guinevere", "rednos", "frenshwa", "heya", "takoyaki", "gertrude", "jan", "coco", "orang", "boi", "gurl", "sunde", "halpe", "cross", "ink", "gaster", "nightmare"};
    vector<string> poss_cores;
    poss_cores.push_back("chem");
    poss_cores.push_back("phys");
    poss_cores.push_back("bio");

    vector<string> poss_elecs;
    poss_elecs.push_back("cs");
    poss_elecs.push_back("chem");
    poss_elecs.push_back("phys");
    poss_elecs.push_back("tech");
    poss_elecs.push_back("engg");
    poss_elecs.push_back("agri");
    poss_elecs.push_back("bio");

    registerGen(argc, argv, 1);
    int n_bf = opt<int>("NBF");
    int n_f = opt<int>("NF");

    // Core, Elec Prefs
    vector<int> core_inds = rnd.perm<int>(3);
    vector<int> elec_inds = rnd.perm<int>(7);

    for(int i = 0; i < NUM_CORES; i++) {
        cout << poss_cores[core_inds[i]];
        if(i < NUM_CORES - 1) cout << " ";
    }
    cout << "\n";
    for(int i = 0; i < NUM_ELECS; i++) {
        cout << poss_elecs[elec_inds[i]];
        if(i < NUM_ELECS - 1) cout << " ";
    }
    cout << "\n";

    // Best Friends
    int if_bf = rnd.next(0, MAX_INFLUENCING_FACTOR);
    cout << if_bf << " " << n_bf << endl;
    for(int i = 0; i < n_bf; i++) {
        string rand_name = names[rnd.next(0, NAMES_LENGTH - 1)];
        string rand_core = poss_cores[rnd.next(0, NUM_CORES - 1)];
        string rand_elec = poss_elecs[rnd.next(0, NUM_ELECS - 1)];

        cout << rand_name << " " << rand_core << " " << rand_elec << endl;
    }

    // Friends
    int if_f = rnd.next(0, MAX_INFLUENCING_FACTOR);
    cout << if_f << " " << n_f << endl;
    for(int i = 0; i < n_f; i++) {
        string rand_name = names[rnd.next(0, NAMES_LENGTH - 1)];
        string rand_core = poss_cores[rnd.next(0, NUM_CORES - 1)];
        string rand_elec = poss_elecs[rnd.next(0, NUM_ELECS - 1)];

        cout << rand_name << " " << rand_core << " " << rand_elec << endl;
    }

    // Siya
    int if_c = rnd.next(0, MAX_INFLUENCING_FACTOR);
    cout << if_f << endl;
    string rand_name = names[rnd.next(0, NAMES_LENGTH - 1)];
    string rand_core = poss_cores[rnd.next(0, NUM_CORES - 1)];
    string rand_elec = poss_elecs[rnd.next(0, NUM_ELECS - 1)];

    cout << rand_name << " " << rand_core << " " << rand_elec << endl;

    return 0;
}