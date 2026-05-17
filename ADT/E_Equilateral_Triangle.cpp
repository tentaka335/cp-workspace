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

    ll l,n;
    cin >> n >> l;

  
    
    vector<ll> d(n);
    ll s = 0;
    map<ll,ll> A;
    A[0] = 1;
    rep(i,n-1) {
        ll d;
        cin >> d;
        s+=d;
        A[s%l]++;
    }

      if(l%3!=0) {
        cout << 0;
        return 0;
    }

    ll ans = 0;
    
    for(auto p : A) {
    if(p.first>=l/3) {
        break;
    }
    ans += p.second*(A[p.first + l/3]) * (A[p.first+(2*l/3)]);
    }

    cout << ans;


    return 0;
}