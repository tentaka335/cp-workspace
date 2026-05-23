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
using mint = modint;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >>m;
    map<ll,ll> A;
    ll ans = inf;
    ll asum = 0;
    map<ll,bool> ispar;
    rep(i,n) {
        ll a;
        cin >> a;
        A[a]++;
        asum +=a;
        ispar[a] = true;
    }
    
    for(auto p : A) {
        if(A.count((p.first-1 + m)%m)) {
            ispar[p.first] = false;
        }
    }
    bool allconect = true;
    for(auto start :ispar) {
        if(ispar[start.first]==false) continue;
        allconect = false;
        ll stakey = start.first;
        ll sum = 0;
        ll i = 0;
       while(true) { 
        ll nex = (stakey + i)%m;
        if(A.count(nex)) {
            sum +=A[(nex)]*(nex);
            chmin(ans,asum - sum);
            i++;
        }
        else break;
    }
        
    }
    if(allconect == true) {
        cout << 0 << "\n";
    }
    else  cout << ans << "\n";
   
    return 0;
}