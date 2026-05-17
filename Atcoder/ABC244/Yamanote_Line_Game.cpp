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

    
    ll n;
    cin >> n;
    queue<ll> A;
    vector<bool> used(2*n+2);
    for(ll i = 1;i<=2*n+1;i++) A.push(i);
    while(!A.empty()) {
        ll x = A.front();
        A.pop();
        if(used[x]==true) continue;
        
        used[x] = true;
        cout << x << "\n" << flush;
        ll a;
        cin >> a;
        if(a==0) {
            return 0;
        }
        used[a] = true;

    }
    return 0;
}