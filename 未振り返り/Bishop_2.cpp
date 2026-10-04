#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif


#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor 半開区間 
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 998244353;
const ll MOD2 = 1e9 + 7;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
#define YES cout<<"Yes"<<"\n";
#define NO cout<<"No"<<"\n";
#define YN {cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}// if(a==b)YN;
#define dame cout<<-1<<endl
//mint::set_mod(m);//main関数下で扱う用
const ll dx[4] = {1,1,-1,-1};
const ll dy[4] = {1,-1,-1,1};
 
 
 
 
 
 
 
 
void solve(){
 
 
 ll n;
 cin >> n;
 ll sx,sy;
 cin >> sx >> sy;
sx--;sy--;
 ll gx,gy;
 cin >> gx >> gy;
 gx--;gy--;
 vector<string> s(n);
 rep(i,n) cin >> s[i];

 if((sx+sy)%2!=(gx+gy)%2) {
    cout << -1 << "\n";
    return ;
 }

 vvll dist(n+4,vll(n+4,inf));
vector<vector<bool>> seen(n+9,vector<bool>(n+9));
 queue<Pll> Q;
 dist[sx][sy] = 0;
 Q.push({sx,sy});

 while(!Q.empty()) {
   auto [x,y] = Q.front();
  
   Q.pop();
   rep(v,4) {
      nfor(i,1,n+1) {
         ll nx = x + dx[v]*i;
         ll ny = y + dy[v]*i;
        
         if(!(0<=nx&&nx<=n-1&&0<=ny&&ny<=n-1)) break;
         // 修正イメージ
if(dist[nx][ny] < dist[x][y] + 1) break;    // 自分より少ない手数で到達しているマスなら、その先も探索済みなのでbreak
if(dist[nx][ny] == dist[x][y] + 1) continue; // 同じ手数のマスなら、通り抜けるだけで探索は止めない(continue)
         if(s[nx][ny]=='#') break;
         dist[nx][ny] = dist[x][y] + 1;
         seen[nx][ny] = true;
         Q.push({nx,ny}); 
      }
   }
 }
 
 if(dist[gx][gy]==inf) cout << -1 << "\n";
 else cout << dist[gx][gy] << "\n";
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}