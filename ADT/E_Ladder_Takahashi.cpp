#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

map<ll,vector<ll>> A;
ll n;
ll ans = 1;
set<ll> visited;

 void dfs (ll pos) {
    visited.insert(pos);
    rep(i,A[pos].size()) {
        ll nex = A[pos][i];
        if(visited.count(nex)==false) {
            chmax(ans,nex);
            dfs(nex);
        }
    }
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
   
    cin >> n;

    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    dfs(1);

    cout << ans;

    
    return 0;
}