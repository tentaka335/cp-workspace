#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll dx[8] = {1,-1,0,0,1,-1,1,-1};
const ll dy[8] = {0,0,1,-1,-1,1,-1,1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> grit(h,vector<char>(w));
    ll sx,sy,gx,gy;
    rep(i,h)rep(j,w) {
        cin >> grit[i][j];
        if(grit[i][j]=='S') {
            sx = i;
            sy = j;
        }
        if(grit[i][j]=='G') {
            gx = i;
            gy = j;
        }
    }

    vector<vector<vector<bool>>> canvisit(4,vector<vector<bool>>(h,vector<bool>(w,false)));
    vector<vector<vector<bool>>> bfdir(4,vector<vector<bool>>(h,vector<bool>(w,-1)));

    queue<tuple<ll,ll,ll>> Q;
    
    canvisit[0][sx][sy] = true;
    canvisit[1][sx][sy] = true;
    canvisit[2][sx][sy] = true;
    canvisit[3][sx][sy] = true;
    Q.push({0,sx,sy});
    Q.push({1,sx,sy});
    Q.push({2,sx,sy});
    Q.push({3,sx,sy});


    while(!Q.empty()) {
        auto [v,x,y] = Q.front();
        Q.pop();

        rep(u,4) {
            ll nx = x + dx[u];
            ll ny = y + dy[u];
            if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                 if(canvisit[u][nx][ny]==true) continue;
                 if(grit[nx][ny]=='#') continue;

                if(grit[x][y]=='.'||grit[x][y]=='G'||grit[x][y]=='S') {
                 
                    canvisit[u][nx][ny] = true;
                    bfdir[u][nx][ny] = v;
                    Q.push({u,nx,ny});
                }
                if(grit[x][y]=='o') {
                    if(u==v) {
                        canvisit[u][nx][ny]=true;
                        bfdir[u][nx][ny] = v;
                        Q.push({u,nx,ny});
                    }
                }
                 if(grit[x][y]=='x') {
                    if(u!=v) {
                        canvisit[u][nx][ny]=true;
                        bfdir[u][nx][ny] = v;
                        Q.push({u,nx,ny});
                    }
                }



            }
        } 
    }



    vector<ll> ans;
    bool ok = false;
    ll px = gx,py = gy,v;
    rep(u,4) {
        if(canvisit[u][gx][gy]==true) {
            ok = true;
            ans.push_back(u);
            break;
            v = u;
        }
    }
    while(true) {
        ans.push_back(v);
        v = bfdir[v][px][py];
        
    }


    if(ok==false) {
        cout << "No" << "\n";
        return 0;
    }
    else {
        cout << "Yes" << "\n";
        rep(i,ans.size()) {
            if(ans[i]==0) cout << 'D';
            if(ans[i]==1) cout <<'U';
            if(ans[i]==2) cout << 'R';
            if(ans[i]==3) cout << 'L';
        }
    }

    return 0;
}