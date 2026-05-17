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
    cin  >> s;
    vector<ll> ans;
    ll stickcnt = 0;
    ll cnt = 0;
    rep(i,s.size()) {
        if(s[i] == '|') stickcnt++;
        else cnt++;
        if(stickcnt>=2) {
            ans.push_back(cnt);
            stickcnt = 1;
            cnt = 0;
        }
    }
    
    rep(i,ans.size()) cout << ans[i] << " ";
    
    return 0;
}