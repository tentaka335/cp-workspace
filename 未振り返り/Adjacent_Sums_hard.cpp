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
 
 
 ll n,m;
 cin >> n >> m;
 vll A(n),B(n-1);
 rep(i,n) cin >> A[i];
 rep(i,n-1) cin >> B[i];
    
 auto a = A;

 ll sum = 0;
 ll ans = inf;
 map<ll,ll> inc;
 map<ll,ll> dec;
 set<ll> change;
 vll C(n);//初期で必要な操作回数;
 for(ll i = n-2;i>=0;i--) {
     C[i] = ((B[i] - a[i] - a[i+1])+ 10*m)%m;
     a[i] = (B[i] - a[i+1] + 10*m) %m;
     sum+=C[i];
     if(A.size()%2==0) {
        if(i%2==1) {//inc
            change.insert(m-C[i]);
            inc[m - C[i]]++;
        }
        else {//dec;
            change.insert(C[i] + 1);
            dec[C[i]+1]++;
        }
     }
     else {
        if(i%2==1) {
            change.insert(C[i] + 1);
            dec[C[i]+1]++;
        } 
        else {
            change.insert(m-C[i]);
            inc[m - C[i]]++;
        }
     }
 }
 if(change.count(0)) change.erase(0);
 rep(i,n) cerr << C[i] << " ";
 chmin(ans,sum);
 auto it = change.begin();
 ll t = 0;
while(1) {
    //連続の最後に行く
    if(A.size()%2==1) {
        sum+=*it - t;
    }
    t = *it;
    it++;
    sum+= (-m)*inc[t]+m*dec[t];
    chmin(ans,sum);
    if(it==change.end()) {
        break;
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