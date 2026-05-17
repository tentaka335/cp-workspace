#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

/*int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;


    vector<vector<tuple<ll,ll,string>>>  version(n+1);
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll p;
            cin >> p;
            ll latest = version[0].size() - 1;
            version[p].push_back({0,latest,""});
        }
        if(qt==2) {
            ll p;
            string s;
            cin >> p >> s;
            ll latest = version[p].size() - 1;
            version[p].push_back({p,latest,s});
        }
        if(qt==3) {
            ll p;
            cin >> p;
             ll latest = version[p].size() - 1;
             version[0].push_back({p,latest,""});
            
        }
    }
    ll latest = version[0].size() - 1;
    if(latest == -1) {
        return 0;
    }
    vector<string> ans;
     auto [x,y,ss] = version[0][latest];
     if(y == -1) {
        cout << ss;
        return 0;
     }

    while(true) {
        auto tempx = x;
        auto tempy = y;
        auto tempss = ss;
        if(ss != "") ans.push_back(ss);
       x  = get<0>(version[tempx][tempy]);
       y  = get<1>(version[tempx][tempy]);
       ss  = get<2>(version[tempx][tempy]);
       if(y==-1) {
        if(ss != "") ans.push_back(ss);
        break;
       }
    }
    reverse(all(ans));
    rep(i,ans.size()) cout << ans[i];
    return 0;
}*/

int main () {
    ll n,q;
    cin >> n >> q;
    vector<ll> Q(q);
    vector<ll> P(q);
    map<ll,string> S;
    rep(qi,q) {
        cin >> Q[qi];
        cin >> P[qi];
        if(Q[qi]==2) {
            string s;
            cin >> s;
            S[qi] = s;
        }
    }
    vector<string> ans;
    ll i = 0;

    for(ll t = q-1;t>=0;t--) {
        if(Q[t]==1) {
            if(i == P[t]) {
                i = 0;
            }
        }
        if(Q[t]==2) {
            if(i==P[t]) {
                ans.push_back(S[t]);
            }
        }
        if(Q[t]==3) {
            if(i==0) {
                i = P[t];
            }
        }
    }
    reverse(all(ans));
    rep(i,ans.size()) cout << ans[i];


}


/*
再帰的な構造に気づけたのはよかったがその実装はもっとうまくいけた。
クエリを必ずしも順にみる必要はないというのは新たな視点だった。
今回ネックだったのは、DP[q][i] :=PC[i]のクエリqを処理した後の文字列とすると
すべてを書き込むのにn*qかかってしまうことだった。
状態がクエリ処理前後で変化しないものに対しては、更新しないという実装方針で解いたが、


*/