#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll compute_ect(vector<ll>& memo, const vector<ll>& durs, const vector<vector<ll>>& ipas, ll cur_act) {
    if(memo[cur_act] == -1) {
        ll dur = durs[cur_act];
        if(ipas[cur_act].size() == 0) {
            memo[cur_act] = dur;
        } else {
            ll ans = std::numeric_limits<ll>::min();

            for(ll ipa : ipas[cur_act]) {
                ans = max(ans, compute_ect(memo, durs, ipas, ipa));
            }

            ans += dur;
            memo[cur_act] = ans;
        }
    }

    return memo[cur_act];
}

int main() {
    ll N;
    cin >> N;
    vector<ll> durs(N, 0);
    vector<vector<ll>> ipas;
    for(ll i = 0; i < N; i++) {
        vector<ll> ipa_row;
        ipas.push_back(ipa_row);
    }
    for(ll i = 0; i < N; i++) {
        ll anum, adur, acount;
        cin >> anum >> adur >> acount;
        for(ll j = 0; j < acount; j++) {
            ll cur_ipa;
            cin >> cur_ipa;
            cur_ipa--;
            ipas[anum - 1].push_back(cur_ipa);
        }
        durs[anum - 1] = adur;
    }

    vector<ll> memo(N, -1ll);

    for(ll i = 0; i < N; i++) {
        compute_ect(memo, durs, ipas, i);
    }
    
    ll fin_ans = std::numeric_limits<ll>::min();

    for(ll time : memo) {
        fin_ans = max(fin_ans, time);
    }

    cout << fin_ans << endl;
    
    return 0;
}