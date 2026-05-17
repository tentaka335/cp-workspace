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
    
    ll n,m,k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> A(n);
    vector<ll> C(n);
    ll asum  = 0;
    rep(i,n) {
        ll a;
        cin >> a;
        A[i] = {a,i};
        asum +=a;
    }
    sort(all(A));
    vector<ll> S(n);
    ll border = n - m;
    for(ll i = n - m  ;i>=1;i--) {
        if(A[i].first == A[i-1].first) {
            border = i - 1;
        }
        else break;
    }

    
    return 0;
}