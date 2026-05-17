#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
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
    
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> A(n);
    ll sum = 0;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        A[i] = {a,b};
        sum+=b;
    }
    sort(A.begin(),A.end());
    vector<ll> S(n);
    if(sum<=k) {
        cout << 1;
        return 0;
    }
    S[0] = sum - A[0].second;
    if(S[0]<=k) {
        cout << A[0].first + 1;
        return 0;
    }
    for(ll i = 1;i<n;i++) {
        S[i] = S[i-1] - A[i].second;
        if(S[i]<=k) {
            cout << A[i].first + 1;
            return 0;
        }
        
    }
    

    return 0;
}