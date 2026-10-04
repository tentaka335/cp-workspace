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
 
 long long INF=(1LL<<60);
vector<long long> LIS(vector<long long> A) {
  long long N = A.size();
  long long INF=(1LL<<60);
  vector<long long> DP(N, INF);

  rep(i,N){
    auto itr = lower_bound(DP.begin(),DP.end(), A[i]); // A[i]以上のDPの要素へのイテレータを取得
    *itr = A[i]; // イテレータが指す要素をA[i]に更新
  }

  return DP;
}
 
 
 
 
 
 
 
void solve(){
 
 
 ll n;
 cin >> n;
 ll maxe = 0;
 ll ans = 0;
 vll A(n),B;
 rep(i,n) {
    cin >> A[i];
    if(maxe<A[i]) {
        ans++;
        maxe = A[i];
    } else {
        B.push_back(A[i]);
    }
 }
 
auto dp = LIS(B);
ll maxele = 0;
 rep(i,dp.size()) {
    if(dp[i]!=INF) {
        maxele = i + 1;
    } 
    else break;
 }
 ans+=maxele;

 cout << ans << "\n";
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}