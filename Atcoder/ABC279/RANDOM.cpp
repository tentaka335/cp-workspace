#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
ll h,w;
cin >> h >> w;
vector<string> S(h);
rep(i,h) {
    cin >> S[i];
}
vector<string> sss;
unordered_map<string,ll> SS;
for(ll j = 0;j<w;j++) {
    string s;
    for(ll i = 0;i<h;i++) {
        s+=S[i][j];
    }
    SS[s]++;
sss.push_back(s);
}
vector<string>ttt;
vector<string> T(h);
rep(i,h) {
    cin >> T[i];
}
unordered_map<string,ll> TT;
for(ll j = 0;j<w;j++) {
    string t;
    for(ll i = 0;i<h;i++) {
        t+=T[i][j];
    }
    TT[t]++;
    ttt.push_back(t);
}

sort(all(ttt));
sort(all(sss));
rep(i,w) {
    if(ttt[i]!=sss[i]) {
        cout << "No";
        return 0;
    }
}
cout << "Yes";
return 0;

for(auto &p:SS) {
    if(p.second != TT[p.first]) {
        cout << "No";
        return 0;
    }
}

cout << "Yes";


    
    return 0;
}