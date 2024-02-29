#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;

const int NAMES_LENGTH = 328;
string names[] = {"nayeon", "momo", "jeongyeon", "sana", "mina", "tzuyu", "dahyun", "chaeyoung", "tetia", "richeh", "aggott", "qifrey", "olruggio", "olly", "alaira", "tartah", "ronron", "aron", "aaron", "emm", "em", "marie", "josette", "emma", "ray", "norman", "roy", "gilda", "don", "john", "anna", "ana", "anne", "nat", "nick", "thoma", "lannion", "b", "gabee", "gabby", "gabbie", "gabriel", "badeline", "madeline", "mads", "maddie", "apple", "peach", "raven", "blondie", "goldy", "goldie", "cerise", "goldee", "daring", "dexter", "darling", "briar", "yuri", "yor", "loid", "anya", "franky", "bond", "sylvia", "becky", "damian", "emile", "ewen", "twilight", "fiona", "shrek", "donkee", "donkey", "himawari", "mahito", "himi", "natsuko", "jiro", "nahoko", "kiki", "tombo", "howl", "sophie", "suliman", "calcifer", "shirayuki", "zen", "obi", "mitsuhide", "sora", "umi", "uchuu", "reuben", "kaze", "haku", "chihiro", "marnie", "emily", "kazuhiko", "nanny", "hisako", "sayaka", "oiwa", "sho", "arrietty", "haru", "spiller", "niya", "shun", "yuichiro", "sachiko", "shirou", "ryoko", "miki", "muta", "yuki", "humbert", "natoru", "muge", "hinode", "nana", "lili", "mikage", "spica", "urara", "yuuhi", "warawara", "kiriko", "suisei", "gura", "sheeta", "pazu", "muska", "dola", "louis", "charles", "jiji", "cloth", "hornet", "zote", "radiance", "quirrel", "cornifer", "minerva", "athena", "skye", "sky", "mary", "jane", "mj", "michael", "jackson", "monique", "jhoienyl", "jonel", "janelle", "mirai", "cress", "adan", "myu", "lauren", "sarah", "sara", "sera", "aydan", "eden", "lance", "ian", "ieuan", "sayoowee", "bumblebee", "mateo", "matteo", "matt", "carlo", "carlos", "inigo", "paolo", "paul", "amos", "talan", "marco", "polo", "kart", "bartholomew", "henry", "allen", "barry", "bart", "iris", "eris", "basti", "hr", "harrison", "harry", "hermione", "ron", "snape", "dumbledore", "cedric", "diggory", "myrtle", "luna", "cho", "molly", "percy", "annabeth", "penelope", "grover", "neville", "clarisse", "luke", "chiron", "cerebus", "dionysus", "sally", "asriel", "bratty", "catty", "tem", "tommy", "temmy", "temmie", "chara", "frisk", "undyne", "sans", "flowey", "ralsei", "kris", "susie", "toriel", "asgore", "mettaton", "toby", "papyrus", "paps", "tobi", "tauriel", "sussy", "sucy", "akko", "lotte", "lotty", "ursula", "diana", "lazurite", "lina", "doon", "alphonso", "randy", "rainbowdash", "pinkiepie", "applejack", "rarity", "twilightsparkle", "sparkle", "shoko", "shoya", "natsume", "porter", "skey", "lexi", "cob", "justine", "elarpi", "tong", "kui", "clerk", "delro", "saryo", "vick", "tor", "yah", "ordun", "au", "lychee", "pluto", "callisto", "io", "ganymede", "kay", "wymari", "stella", "carl", "leen", "lian", "tera", "jard", "mansi", "nido", "tow", "bee", "lapi", "tan", "jian", "ale", "minji", "danielle", "hanni", "hyein", "haerin", "yunjin", "heeseung", "jake", "jay", "jimin", "v", "rapmonster", "gabe", "guinevere", "rednos", "frenshwa", "heya", "takoyaki", "gertrude", "jan", "coco", "orang", "boi", "gurl", "sunde", "halpe", "cross", "ink", "gaster", "nightmare"};

int main(int argc, char** argv) {
    registerGen(argc, argv);

    // Take, as input, the number of people first
    int nump = opt<int>("NP");
    
    // Then, obtain a random sample of names
    vector<int> rand_inds = rnd.distinct(nump, NAMES_LENGTH);
    vector<string> s_names;
    for(int i : rand_inds) {
        s_names.push_back(names[i]);
    }
    
    // Generate a random tree by creating a successor graph
    // Then, for each node i >= 1, set its parent to a random number in [0, i - 1]
    vector<int> par;
    par.push_back(0);
    for(int i = 1; i < nump; i++) {
        par[i] = rnd.next(0, i - 1);
    }

    // Create an adjacency list pointing downwards from the root node
    vector<vector<int>> adj;
    for(int i = 0; i < nump; i++) {
        vector<int> row;
        adj.push_back(row);
    }

    for(int i = 1; i < nump; i++) {
        adj[par[i]].push_back(i);
    }

    // Count the number of nodes with child edges. This will be the value of n
    int n = 0;
    for(int i = 0; i < nump; i++) {
        if(adj[i].size() > 0) n++;
    }

    // Create a random permutation of integers representing the random order of traversal
    vector<int> list_order = rnd.perm(nump);

    // Iterate through this random order one by one, printing both the name of the spreader
    // And the names of the spreadees. Don't forget the number of spreadees too! :D 
    cout << n << "\n";
    for(int unsorted_i = 0; unsorted_i < nump; unsorted_i++) {
        int i = list_order[unsorted_i];
        int m = adj[i].size();
        if(m == 0) continue;

        cout << m << "\n";
        cout << s_names[i] << "\n";
        for(int j = 0; j < m; j++) {
            cout << s_names[adj[i][j]];
            if(j < m - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}