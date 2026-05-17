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
    rep(i,h) cin >> S[i];
    ll maxx = -1,maxy = -1,minx = h,miny = w;
    rep(i,h)rep(j,w) {
        if(S[i][j]=='#') {
            chmax(maxx,i);
            chmax(maxy,j);
            chmin(minx,i);
            chmin(miny,j);
        }
    }
    for(ll i = minx;i<=maxx;i++) {
        for(ll j = miny;j<=maxy;j++) {
            if(S[i][j]=='.') {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}