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
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string,ll> A;
    ll maxc = 0;
    rep(i,n-k+1) {
        string subs = s.substr(i,k);
        A[subs]++;
        maxc = max(maxc,A[subs]);
    }
    cout << maxc << "\n";
    for(auto a:A) {
        if(a.second == maxc) cout << a.first << " ";
    }
    
    return 0;
}