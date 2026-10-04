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
 
 
 
 bool outgrid(ll i,ll j,ll h,ll w) {
    if(0<=i&&i<=h-1&&0<=j&&j<=w-1) return false;
    else return true;
 }
 
 
 
 
void solve(){
 
 
 ll h,w,k;
 cin >> h >> w >> k;
 vector<string> s(h);
 rep(i,h) cin >> s[i];
 vector<bool> safeh(h+1,true),safew(w+1,true);
 rep(i,h) {
    rep(j,w) {
        if(s[i][j]=='#') {
            safeh[i] = false;
            safew[j] = false;
        }
    }
 }

 queue<Pll> Q;

 vvll dist(h+1,vll(w+1,inf));
 vvll seen(h+1,vll(w+1,false));
 rep(i,h) {
    rep(j,w) {
        if(safeh[i]==true&&safew[j]==true) {
            Q.push({i,j});
            dist[i][j] = 0;
            seen[i][j] = true;
        }
     }
 }
 
 while(!Q.empty()) {
    auto [i,j] = Q.front();
    Q.pop();
    rep(v,4) {
        ll ni = i + dx[v];
        ll nj = j + dy[v];
        if(outgrid(ni,nj,h,w)) continue;
        if(s[ni][nj]!='#'&&seen[ni][nj]==false) {
            dist[ni][nj] = dist[i][j] + 1;
            seen[ni][nj] = true;
            Q.push({ni,nj});
        }
    }
 }
 ll ans = 0;
 rep(i,h) {
    rep(j,w) {
        if(dist[i][j]<=k) ans++;
    }
 }

 cout << ans <<"\n";
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}