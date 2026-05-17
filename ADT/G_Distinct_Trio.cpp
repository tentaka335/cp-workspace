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
    map<ll,ll> A;
    ll noans = 0;
    rep(i,n) {
        ll a;
        cin >> a;
        A[a]++;
    }
    for(auto p:A) {
        auto [k,v] = p;
        if(v>=2) {
            noans += ((v*(v-1))/2) *(n-v);
        }
        if(v>=3) {
            noans+=(v*(v-1)*(v-2))/6;
        }
    }
  ll  ans = (n*(n-1)*(n-2))/6 - noans;
  cout << ans;
    return 0;
} 