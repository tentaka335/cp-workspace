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
const ll dx[8] = {1,0,-1,0,1,1,-1,-1};
const ll dy[8] = {0,1,0,-1,1,-1,-1,1};
 
 
 
 
 
 
 
 
void solve(){
 
 
 ll n,m,y;
 cin >> n >> m >> y;
 vector<vector<Pll>> G(n+9);
 vll X(n+1);
 rep(i,m) {
    ll u,v,t;
    cin >> u >> v >> t;
    G[u].push_back({v,t});
    G[v].push_back({u,t});
 }
 G[n+1].push_back({n+2,y});
 nfor(i,1,n+1) {
    cin >> X[i];
    G[i].push_back({n+1,X[i]});
    G[n+2].push_back({i,X[i]});
 }

 priority_queue<Pll,vector<Pll>,greater<Pll>> Q;
 vll dist(n+9,inf);
 dist[1] = 0;
 Q.push({0,1});
 while(!Q.empty()) {
    auto [dis,pos] = Q.top();
    Q.pop();
    if(dis>dist[pos]) continue;
    for(auto[nex,cost]:G[pos]) {
        if(dist[nex]>cost+dis) {
            dist[nex] = cost + dis;
            Q.push({dist[nex],nex});
        }
    }
 }
 
 nfor(i,2,n+1) cout << dist[i] << " ";

 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}