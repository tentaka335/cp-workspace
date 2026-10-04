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
 
 ll n,h,w;
 cin >> n >> h >> w;
 vll A(n+1),B(n+1);
 nfor(i,1,n+1) cin >> A[i] >> B[i];

 vvll dp(n+9,vll(h+9,inf));//dp[i][j]:=i体目を倒して、使った体力がiであるときの使った魔力の最小値
 dp[0][0] = 0;
 
 nfor(i,1,n+1) {
    nfor(j,0,h+1) {
        //hpを使ったormpを使った
        if(j>=A[i]) dp[i][j] = min(dp[i-1][j-A[i]],dp[i-1][j] + B[i]);
        else dp[i][j] = dp[i-1][j] + B[i];
    }
 }
 vector<bool> ans(n+9);
 nfor(i,1,n+1) {
    nfor(j,0,h+1) {
        if(dp[i][j]<=w) {
            ans[i] = true;
            break;
        }
    }
 }
 nfor(i,1,n+2) {
    if(ans[i]==false)  {
        cout << i - 1<<"\n";
        return ;
    }
 }
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}