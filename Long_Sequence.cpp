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
    vector<ll> L(n);
    vector<vector<ll>> A(n);
    
    rep(i,n) {
        ll l;
        cin >> l;
        L[i] = l;
        rep(j,l) {
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    vector<ll> C(n);
    vector<ll> SCL(n);
rep(i,n) {
    cin >> C[i];
    if(i==0) SCL[i] = L[i]*C[i];
    else SCL[i] = SCL[i-1]+L[i]*C[i];
}

ll pos = lower_bound(all(SCL),k) - SCL.begin();

ll amari;
if(pos==0) amari = k;
else amari = k - SCL[pos-1];//A[pos]の繰り返しの何番目か
amari--;
cout << A[pos][amari%L[pos]];
    return 0;
}