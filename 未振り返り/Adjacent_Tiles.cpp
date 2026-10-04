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
 
 
 
 long long isqrt(long long n) {
    if(n<=0) return 0;
    ll m = sqrt(n);
    while((m+1)*(m+1)<=n) m++;
    while(m*m>n)m--;
    return m;
}
 
 ll sqsum(ll sn) {
    if(sn==1) return 0;
    else return (4*(sn-2)*(sn-2)+2*4+3*4*(sn-2))/2;
 }
 
 
 
void solve(){
 
 
 ll n;
 cin >> n;
 
ll sn = isqrt(n);

 ll ans = 0;


 ans+=sqsum(sn);
 
n-=sn*sn;
 if(1<=n) ans+=min(2*(n-1)+1,2*(sn-1)+1); 

 if(sn<n) ans+=min(2*((n - sn)-1)+1,2*(sn-1)+1);
 
 cout << ans << "\n";
}



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
  ll t;
  cin >> t;  
    
 rep(ti,t) solve();
    return 0;
}