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
    
    ll n,m;
    cin >> n >> m;
    map<ll,ll> A;
    rep(i,2*n) {
        ll a;
        cin >> a;
        A[a]++;
    }
    
    for(auto p : A) {
        if((p.second)%2 != 0)  break;

        cout << "Bob" << "\n";
        return 0;
    }
    if(m%2==0&&A.size()%4 == 0) {
        bool ok = true;
        for(auto p : A) {
            auto [key,v] = p;
            if(A[(key+m/2)%m]!=v) ok = false;

        
         
        }
           
        if(ok){
             cout <<"Bob" << "\n";
             return 0;
        }
    }

    cout << "Alice" << "\n";
    return 0;
}