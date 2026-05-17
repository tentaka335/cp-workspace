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
    
    ll n,t;
    cin >> n >> t;

    vector<ll> A(n);

    vector<ll> B(n);
    vector<ll> C(n);
    set<ll> D,E;
    ll d = 0,e = 0;
    for(ll i = 1;i<=n*n;i+=n+1) {
        D.insert(i);
    }
    for(ll i = n;i<=n*(n-1)+1;i+=n-1) {
        E.insert(i);
    }

    rep(ti,t) {
        ll a;
        cin >> a;
        B[(a-1)/n]++;
        if(B[(a-1)/n]==n) {
            cout << ti+1;
            return 0;
        }
        C[a%n]++;
        if(C[a%n]==n) {
            cout << ti+1;
            return 0;
        }
        if(D.count(a)) {
            d++;
            if(d==n) {
                cout << ti+1;
                return 0;
            }
        }
        if(E.count(a)) {
            e++;
            if(e==n) {
                cout << ti+1;
                return 0;
            }
        }
    }
    cout << -1;
    
    return 0;
}