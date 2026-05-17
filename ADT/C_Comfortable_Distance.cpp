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
    ll n,l,r;
    cin >> n >> l >>r;
    string s;
    cin >> s;
    ll ans = 0;
    map<char,ll> A;
    ll left = l,right = r;
    for(ll i = l;i<=r;i++) {
        A[s[i]]++;
    }
    ans += A[s[0]];
   for(ll i = 1;i<=n-1;i++) {
    if(l+i-1<=n-1) A[s[l+i-1]]--;
    if(r+i<=n-1) A[s[r+i]]++;
    ans+=A[s[i]];
   }
    cout << ans;
    
    return 0;
}