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
    string ans;
    vector<vector<ll>> nexi(26,vector<ll>(n+1,n)); //nexi[i][j] :=iという文字(数値変換済み)がj文字以降に最初に現れる位置
    for(ll i = n-1;i>=0;i--) {
        ll c =  s[i] - 'a';
        for(ll j = 0;j<26;j++) {
            if(j!=c) {
                nexi[j][i] = nexi[j][i+1];
            }
            else {
                nexi[j][i] = i;
            }
        }
    }

    ll last = -1;
    
    for(ll i = 0;i<k;i++) {
        for(ll c = 0;c<26;c++) {
            ll pos = nexi[c][last+1];
            if(pos <= n - (k - i)) {
                ans+=('a'+c);
                last = pos;
                break;
            }
        }
    }

    cout << ans;
    
}