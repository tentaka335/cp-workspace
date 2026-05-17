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
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    vector<string> T(h);
    rep(i,h) cin >> S[i];
    rep(i,h) cin >> T[i]; 
    map<string,ll> SS;
    
   for(ll i = 0;i<w;i++) {
    string s;
    for(ll j = 0;j<h;j++) {
        s+=S[j][i];
    }
    SS[s]++;
   }

     for(ll i = 0;i<w;i++) {
    string t;
    for(ll j = 0;j<h;j++) {
        t+=T[j][i];
    }
    if(SS[t]>=1) {
        SS[t]--;

    }
    else {
        cout << "No";
        return 0;
    }
   }

   cout << "Yes";

    
    return 0;
}