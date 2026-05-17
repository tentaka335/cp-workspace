#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pll = pair<ll,ll>;


   ll h,w;

   
int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> h >> w;
    vector<vector<char>> S(h+9,vector<char>(w+9));

    queue<Pll> T;

    vector<ll> dx ={1,0,-1,0};
    vector<ll> dy ={0,1,0,-1};
    ll ans = 0;
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cin >> S[i][j];
            if(S[i][j] == '') {
                T.push(make_pair(i,j));
            }
        }
    }
    while(!T.empty()) {
        auto it = T.front();
        ll x = it.first;
        ll y = it.second;
        if(S[x][y]=='#') continue;
        T.pop();
        S[x][y] = '#';
        ans ++;
        for(ll i = 0;i<4;i++) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx<1||h<nx||ny<1||w<ny) continue;
            ll count = 0;
            for(ll k = 0;k<4;k++) {
                ll nnx = nx + dx[k];
                ll nny = ny + dy[k];
                if(nnx <1 || nnx > h || nny < 1 || w < nny) continue; 
                if(S[nnx][nny] == '#') count++;
            }
            if(count == 1) {
            T.push(make_pair(nx,ny));
            }
        }
    }
    cout << ans << "\n";

    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cout << S[i][j] ;
        }
        cout << "\n";
    }
}

