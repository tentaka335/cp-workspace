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
    vector<ll> A(n+1);
    set<ll> B;
    if(n!=m) {
        cout << -1;
        return 0;
    }
    rep(i,m) {
        ll x,a;
        cin >> x >> a;
        A[x] = a;
        if(a>=2) B.insert(x);
    }
    ll ans = 0;
    for(ll i = 1;i<=n;i++) {
        if(A[i]==0) {
            auto it = B.upper_bound(i);
            if(it==B.begin()) {
                cout << -1;
                return 0;
            }
            it--;
            ll pos = *it;
            ans += i -pos;
            A[pos]--;
            if(A[pos]==1) {
                B.erase(pos);
            }
        }
    }
    cout << ans;
    
    return 0;
}