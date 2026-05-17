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
    
    map<ll,ll> S;
    map<ll,ll> pnum;
    ll n;
    cin >> n;
    vector<ll> A(n);
    ll ans = -1;
    rep(i,n) {
        cin >> A[i];
        S[A[i]]++;
        pnum[A[i]] = i+1;
    }
    ll nowmax = -1;
    for(auto p : S) {
        if(p.second==1) {
            if(nowmax<p.first) {
                nowmax = p.first;
                ans = pnum[p.first];
            }
           
        }
    }

    cout << ans;

    
    return 0;
}