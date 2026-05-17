
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
    ll m,a,b;
    cin >> m >> a >> b;
    vector<vector<bool>> used(m,vector<bool>(m));
    vector<vector<ll>> can(m,vector<ll>(m,inf));
    queue<pair<ll,ll>> Q;

    for (ll i = 0;i<m;i++) {
                used[0][i] = true;
                used[i][0] = true;
                can[0][i] = 0;
                can[i][0] = 0;
            }
    for(ll X = 1;X<m;X++) {

        for(ll Y = 1;Y < m;Y++) {
            ll x = X;
            ll y = Y;
            if(used[x][y] == true) continue;
            while(true) {
                used[x][y] = true;
                Q.push({x,y});
                ll temp1 = x%m;
                ll temp2 = y%m;
                 x = y%m;
                y = (a*temp2 + b*temp1) % m;
                y = (y + m) %m;
                if(used[x][y] == true) {
                    while(!Q.empty()) {
                        auto [nx,ny] = Q.front();
                        Q.pop();
                        if(can[x][y]==0) {
                            can[nx][ny] = 0;
                        }
                        else {
                            can[nx][ny] = 1;
                        }
                    }
                    break;
                }

            }
        }
    }
    ll ans = 0;
    for(ll x = 0;x<m;x++) {
        for(ll y = 0;y<m;y++) {
            if(can[x][y] == 1) ans++; 
        }
    }
    cout << ans << "\n";
    return 0;
}