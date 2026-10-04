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
 
 
 ll n,k;
 cin >> n >> k;
 ll asum = 0;
 vll A(n+9),B(n+9);
 nfor(i,1,n+1) {
    cin >> A[i] >> B[i];
    asum+=A[i];
 }

 vector<vvll> dp(2,vvll(k+9,vll(n+9,-inf)));
 //dp[j][k][i]:=iの表裏がj,今までに使った回数がk,のときiを決定したときの最大値

 dp[0][0][0] = asum;
 dp[1][0][0] = asum;
nfor(i,1,n+1) dp[0][0][i] = asum;
 nfor(i,1,n+1) {
    nfor(K,1,k+1) {
        nfor(j,0,2) {
            if(j==0) {//裏にしない
                dp[j][K][i] = max(dp[0][K][i-1],dp[1][K][i-1]);
            } 
            else {//裏にする
                //前にひっくり返すのを引き継ぐか、
                
               if(K>=1) dp[j][K][i] = max({dp[1][K][i-1]+B[i]-A[i],dp[0][K-1][i-1]+B[i]-A[i]});
               else dp[j][K][i] = dp[0][K][i-1]+B[i] - A[i];
               
            }

        }
    }
 }

 ll ans = 0;

 rep(j,2) {
    rep(a,k+1) {
        chmax(ans,dp[j][a][n]);
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