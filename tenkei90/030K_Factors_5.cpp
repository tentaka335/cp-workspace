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
    vector<ll> A(n+1);
    vector<bool> isprime(n+1,true);
     ll ans = 0;
    for(ll i = 2;i<=n;i++) {
        if(isprime[i]==false) continue;
            A[i] = 1;
            if(A[i]==k) ans++;
            for(ll j = 2*i;j<=n;j+=i) {
                A[j]++;
                isprime[j] = false;
                if(A[j]==k) ans++;
                
            }
    }
    
   
    cout << ans;
  
    return 0;
}