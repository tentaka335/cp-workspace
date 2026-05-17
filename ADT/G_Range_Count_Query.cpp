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
    vector<ll> A(n);
    vector<vector<ll>> Xpos(n+1);
    rep(i,n) {
        cin >> A[i];
        Xpos[A[i]].push_back(i);
    }

    ll q;
    cin >> q;
    rep(qi,q) {
        ll l,r,x;
        cin >> l >> r >> x;
        l--;r--;
        auto left = lower_bound(all(Xpos[x]),l);
        auto right = upper_bound(all(Xpos[x]),r);
        right--;
        ll lef = left - Xpos[x].begin();
        ll rig = right - Xpos[x].begin();
        cout << rig - lef + 1 << "\n";
    
    }
    return 0;
}