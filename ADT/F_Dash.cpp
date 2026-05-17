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
    
    ll n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<ll,ll>> item;
    rep(i,m) {
        ll x,y;
        cin >>x >> y;
        item.insert({x,y});
    }
    ll X = 0,Y = 0;
    rep(i,n) {
        if(s[i]=='R') {
            X++;
        }
         if(s[i]=='L') {
            X--;
        }
         if(s[i]=='U') {
            Y++;
        }
         if(s[i]=='D') {
            Y--;
        }
        h--;

        if(h<0) {
            cout << "No";
            return 0;
        }

        if(item.count({X,Y})) {
            if(h<k) {
                h = k;
                item.erase({X,Y});
            }
        }
     
        
        
    }
    cout << "Yes";
    
    return 0;
}