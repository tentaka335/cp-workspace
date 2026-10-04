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
 
 
 ll n;
 cin >> n;
 map<ll,ll> A;//頻度
 map<ll,vector<Pll>> aite;//そこにいけるウサギindex;
set<Pll> task;//そこにいけるウサギの出現頻度低い順
 vll p(n),m(n);
 rep(i,n) {
    ll x,r;
    cin >> x >> r;
    p[i] = x+r;
    m[i] = x - r;
    A[p[i]]++;
    A[m[i]]++;
    aite[p[i]].push_back({i,m[i]});
    aite[m[i]].push_back({i,p[i]});
 }
 for(auto [key,v] : A) {
    task.insert({v,key});
 }
 set<ll> used;
 vector<bool> ur(n);
 ll ans = 0;

 while(!task.empty()) {
    auto [v,key] = *task.begin(); 
    task.erase({v,key});
    if(v<=0) continue;
    
    ans++;
    ll hindo = 0;
    ll i = -1;
   
    for(auto [idx,pos]: aite[key]) {
        if(ur[idx]) continue;
        if(hindo<A[pos]) {
            hindo = A[pos];
            i = idx;
        }
        if(used.count(pos)) {
            hindo = A[pos];
            i = idx;
            break;
        } 
    }
    //iを使うことにしたよ
    
    used.insert(key);
    if(key!=p[i]) task.erase({A[p[i]],p[i]});
    if(key!=m[i]) task.erase({A[m[i]],m[i]});
    A[p[i]]--;
    A[m[i]]--;
    if(key!=p[i]&&!used.count(p[i])) task.insert({A[p[i]],p[i]});
    if(key!=m[i]&&!used.count(m[i])) task.insert({A[m[i]],m[i]});
    ur[i] = true;
    
    
    

 }


 cout << ans <<"\n";
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}