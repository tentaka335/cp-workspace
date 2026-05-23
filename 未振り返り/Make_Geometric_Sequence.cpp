#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
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
    ll t;
    cin >> t;
    rep(ti,t) {
    ll n;
    cin >> n;
    vector<Pll> B(n);
    bool ok = true;
    bool abssame = true;
    bool same = true;
    map<ll,ll> A;
    ll temp;
    rep(i,n) {
        ll a;
        cin >> a;
        if(i==0) temp = a;
        B[i] = {llabs(a),a};
        if(llabs(temp) != llabs(a)) abssame = false;
        if(temp != a) same = false;
        A[a]++;

    } 
    if(same==false&&abssame == true) {
        if(llabs(A[temp] - A[-temp])<=1);
        else ok = false;
    }
    
   else { sort(all(B));
   
    
    if (n>=3)  {
        for(ll i = 0;i<=n-3;i++) {
        ll b1 = B[i].second;
        ll b2 = B[i+1].second;
        ll b3 = B[i+2].second;
        if(b1*b3!=b2*b2) {
            ok = false;
            break;
        }
    }
}
   }
    

    cout <<(ok?"Yes":"No") << "\n";
}
    return 0;
}