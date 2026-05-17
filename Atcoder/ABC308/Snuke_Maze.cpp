#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;

const ll dx[] = {1,0,-1,0};
const ll dy[] = {0,1,0,-1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    rep(i,h) cin >> S[i];

    vector<vector<bool>> visited(h,vector<bool>(w));

    queue<pair<Pll,char>> Q;

    if(S[0][0]=='s')  {
        Q.push({{0,0},'s'});
        visited[0][0] = true;
    }

    while(!Q.empty()) {
         ll x = Q.front().first.first;
         ll y = Q.front().first.second;
         char c = Q.front().second;
         Q.pop();
         char nc;
         if(c=='s') nc = 'n';
         else if(c=='n') nc = 'u';
         else if(c=='u') nc = 'k';
         else if(c=='k') nc = 'e';
         else if(c=='e') nc = 's';
         else continue;
         

         rep(v,4) {
            ll nx = x + dx[v];
            ll ny = y + dy[v];
            if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                if(S[nx][ny]==nc&&visited[nx][ny]==false) {
                    visited[nx][ny] = true;
                    Q.push({{nx,ny},nc});
                }
            }
         }

    }

    if(visited[h-1][w-1]==true) cout << "Yes";
    else cout << "No";
    
    return 0;
}