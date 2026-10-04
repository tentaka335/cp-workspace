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
 
 
 ll h,w,nn;
 cin >> h >> w >> nn;
 vvll grid(h+9,vll(w+9));
 vvll sum(h+9,vll(w+9));
 rep(i,nn) {
    ll a,b;
    cin >> a >> b;
    grid[a][b] = 1;
 }
 nfor(i,1,h+2) {
    grid[i][w+1] = 1;
 }
 nfor(j,1,w+2) {
    grid[h+1][j] = 1;
 }
 nfor(i,1,h+2) {
    nfor(j,1,w+2) {
        sum[i][j] += sum[i-1][j] + grid[i][j];
    }
 } 
  nfor(i,1,h+2) {
    nfor(j,1,w+2) {
        sum[i][j] += sum[i][j-1];
    }
 }
 ll ans = 0;

 auto ressum = [&](ll i,ll j,ll n) {
    return sum[i+n-1][j+n-1] - sum[i+n-1][j-1] - sum[i-1][j + n - 1] +sum[i-1][j-1];
 };

 nfor(i,1,h+1) {
    nfor(j,1,w+1) {
        if(grid[i][j]>=1) continue;
       
        ll ok = 1;
        ll ng = min(h - i +2,w - j + 2);
        while(abs(ok - ng)>1) {
            ll mid = (ok +ng)/2;
            if(ressum(i,j,mid)==0) ok = mid;
            else ng = mid;
        }
        
        ans+=ok;
    }
 }
 

 cout << ans << "\n";
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}