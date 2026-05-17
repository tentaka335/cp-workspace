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
    vector<ll> A(n);
    rep(i,n) cin >> A[i];

     
    ll m;
    cin >> m;
    vector<ll> B(m);
    rep(i,m) cin >> B[i];
     
    ll l;
    cin >> l;
    vector<ll> C(l);
    rep(i,l) cin >> C[i];
      ll q;
    cin >> q;
    vector<ll> X(q);
    rep(i,q) cin >> X[i];

    set<ll> can;
    for(ll i = 0;i<n;i++) {
        for(ll j = 0;j<m;j++) {
            for(ll k = 0;k<l;k++) {
                ll temp = A[i] + B[j] + C[k];
                can.insert(temp);
            }
        }
    }

    rep(i,q) {
        if(can.count(X[i])) cout << "Yes" << "\n";
        else  cout << "No" << "\n";
    }
    

    
    
    return 0;
}