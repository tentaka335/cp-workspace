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
    
    string s;
    cin >> s;
    map<char,ll> A;
    ll maxs  = 0;
    for(ll i = 0;i<s.size();i++) {
        A[s[i]]++;
        maxs = max(maxs,A[s[i]]);
    }

    rep(i,s.size()) {
        if(A[s[i]]!=maxs) {
            cout << s[i];
        }
    }
    
    return 0;
}