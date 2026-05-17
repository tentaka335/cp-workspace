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
    ll n;
    cin >> n;
    vector<string> S(n);
    vector<pair<ll,ll>> ans(n);
    rep(i,n) cin >> S[i];
    rep(i,n) {
        ll cnt = 0;
        rep(j,n) {
            if(S[i][j]=='o') cnt--;
    }
    ans[i] = {cnt,i+1};
}
sort(all(ans));

rep(i,n) cout << ans[i].second << " ";
    return 0;
}