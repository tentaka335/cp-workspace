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
 ll c,d;
 cin >> c >> d;
 
 ll MAXDIGIT = to_string(c+d).size();
 
 vll pow10(19,1);
 for(ll i = 1;i<=10;i++) {
    pow10[i] = 10*pow10[i-1];
 }
 pow10[0] = 1;

 ll ans = 0;
 
 for(ll digit = 1;digit<=MAXDIGIT;digit++) {

    ll left = max(pow10[digit-1]+c*pow10[digit],c+1+c*pow10[digit]);
    ll right ;
    if(digit==MAXDIGIT) right = c+d+1+c*pow10[digit];
    else right = c*pow10[digit] + pow10[digit];
    //leftは切り上げrightは切り上げ
    ll lok = 2e9;
    ll lng = -1;
    while(llabs(lok - lng)>1) {
        ll mid = lng + (lok - lng)/2;
        if(left<=mid*mid) lok = mid;
        else lng = mid;
    }
    ll rok = -1;
    ll rng = 2e9;
    while(abs(rok-rng)>1) {
        ll mid = rok +(rng - rok)/2;
        if(mid*mid<right) rok = mid;
        else rng = mid;
    }

   if(rok>=lok)  ans +=rok - lok +1;

    
    
 }
 
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