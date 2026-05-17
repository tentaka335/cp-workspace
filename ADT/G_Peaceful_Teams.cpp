#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;







int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,t,m;
    cin >> n >> t >> m;

    vector<vector<bool>> hate(n,vector<bool>(n));
    rep(qi,m) {
        ll a,b;
        cin >> a >> b;
        a--;b--;

        hate[a][b] = true;
        hate[b][a] = true;
    }
    ll ans = 0;
    vector<vector<ll>> team;
    auto f = [&](auto f,ll i) -> void {
        if(i==n) {
            if(team.size()==t) ans++;
            return ;
        }

        rep(j,team.size()) {
            bool ok = true;
            for(ll p:team[j]) {
                if(hate[i][p]) ok = false;
            }
            if(!ok) continue;
            team[j].push_back(i);
            f(f,i+1);
            team[j].pop_back();
        }
        
        //newteam追加
        team.push_back(vector<ll>(1,i));
        f(f,i+1);
        team.pop_back();
    };
    f(f,0);

    cout << ans;
    
    
    return 0;
}