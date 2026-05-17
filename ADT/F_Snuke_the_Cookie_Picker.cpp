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
    vector<vector<char>> HW(h,vector<char>(w));
    rep(i,h)rep(j,w) cin >> HW[i][j];
    
    ll minx = h-1,maxy = 0,miny = w-1,maxx = 0;
    rep(x,h)rep(y,w) {
        if(HW[x][y]=='#') {
            chmax(maxx,x);
            chmax(maxy,y);
            chmin(minx,x);
            chmin(miny,y);
        }
    }
    for(ll  x = minx;x<=maxx;x++) {
        for(ll y = miny;y<=maxy;y++) {
            if(HW[x][y] == '.') cout << x+1 << " " << y+1;
        }
    }
    return 0;
}