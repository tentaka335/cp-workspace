#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dx = {1,0,-1,0};
vector<ll> dy = {0,1,0,-1};



class UnionFind {
    public:
    ll par[4000009];
    ll siz[4000009];

    //N頂点のUnionFindを作成
    void init(ll N) {
        for(ll i = 1;i<=N;i++) par[i] = -1;
        for(ll i = 1;i<=N;i++) siz[i] = 1;
    }
    //x頂点の根を返す関数
    ll root(ll x) {
        while(true) {
            if(par[x] == -1) break;
            x = par[x];
        }
        return x;
    }
    void unite(ll u,ll v) {
        ll RootU = root(u);
        ll RootV = root(v);
        if(RootU == RootV) return;
        if(siz[RootU] < siz[RootV]) {//Union by size
            par[RootU] = RootV;
            siz[RootV] = siz[RootU] + siz[RootV];
        }
        else {
            par[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
        }
    }
    bool same(ll u,ll v) {
        if(root(u)==root(v)) return true;
        else return false;
    }
};

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    UnionFind UF;
    UF.init(h*w);
    //(x,y)=w*(x-1)+y
    vector<vector<char>> grit(h+9,vector<char>(w+9,'W'));
    
    ll q;
    cin >> q;
    for(ll qi = 0;qi<q;qi++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x,y;
            cin >> x >> y;
            grit[x][y] = 'R';

            for(ll i = 0;i<4;i++) {
                if(grit[x+dx[i]][y+dy[i]]=='R') UF.unite(w*(x-1)+y,w*(x+dx[i]-1)+y+dy[i]);
            }
            
           /* for(ll i = 1;i<=h;i++) {
                for(ll j = 1;j<=w;j++) {
                    cout << grit[i][j];
                }
                cout << "\n";
            }*/
        }
        else {
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            if(grit[a][b]=='R'&&grit[c][d]=='R'&&UF.same(w*(a-1)+b,w*(c-1)+d)) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
}