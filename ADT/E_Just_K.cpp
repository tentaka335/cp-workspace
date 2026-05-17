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
    
    ll n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<set<ll>> A(n);
    rep(i,n) {
        rep(j,s[i].size()) {
            ll k = s[i][j] - 'a';
            A[i].insert(k);
        }
    }
ll ans = 0;
    for(ll i = 0;i<(1<<n);i++) {
        ll cnt = 0;
        for(ll j = 0;j<=25;j++) {
        
            ll cnt1 = 0;
            for(ll k = 0;k<n;k++) {
                if((i>>k)%2==0) {
                    if(A[k].count(j)) {
                        cnt1++;
                    }
                }
            }
            if(cnt1==m) {
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }

    cout << ans;
    
    
    
    return 0;
}