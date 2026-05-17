#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;

    vector<vector<ll>> HW(h+1,vector<ll>(w+1));
    for(ll i = 1;i<=h;i++) for(ll j = 1;j<=w;j++) {
        cin >> HW[i][j];
    }
    ll ans = 0;
    for(ll i = 0;i<(1<<(h*w));i++) {
        vector<vector<bool>> blacked(h+1,vector<bool>(w+1));
        ll blackcount = 0;
        for(ll x = 1;x<=h;x++) for(ll y = 1;y<=w;y++) {
            if((i>>(w*(x-1)+y-1)&1) == 1) {
                blacked[x][y] = true;
                blackcount++;
            }
        }

        if(blackcount%2!=0) {
            continue;
        }
        bool ok = true;
         for(ll x = 1;x<=h;x++) for(ll y = 1;y<=w;y++) {

            if(blacked[x][y]==false) continue;
            ll rinsetu = 0;
            rep(v,4) {
                ll nx = x + dx[v];
                ll ny = y + dy[v];
            
                if(1<=nx&&nx<=h&&1<=ny&&ny<=w) {
                    if(blacked[nx][ny]==true) {
                        rinsetu++;
                    }
                }
            }
            if(rinsetu==0) ok = false;
        }
        if(ok == false) continue;
        ll semians = 0;
         for(ll x = 1;x<=h;x++)for(ll y = 1;y<=w;y++) {
            if(blacked[x][y]==false) {
                semians^=HW[x][y];
            }
        }

        chmax(ans,semians);

        
    }

    cout << ans;
    
    return 0;
}