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
 
 
 ll h,w,k;
 cin >> h >> w >> k;
 
 vector<string> S(h+1);
 nfor(i,1,h+1) {
    string s;
    cin >> s;
    s = '0' + s;
    S[i] = s;
 }
 vvll sum(h+9,vll(w+9));
 nfor(i,1,h+1) {
    nfor(j,1,w+1) {
        sum[i][j] += sum[i][j-1] + (S[i][j] - '0');
    }
 }

  nfor(i,1,h+1) {
    nfor(j,1,w+1) {
        sum[i][j] += sum[i-1][j];
    }
 }
nfor(i,1,h+1) {
   sum[i][w+1] = (ll)1e9;
}


 
 auto ressum= [&](ll a,ll b,ll c, ll d) {
    return sum[c][d] - sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
 };
 ll ans = 0;
 nfor(a,1,h+1) {
    nfor(c,a,h+1) {
        nfor(l,1,w+1) {
            //kを満たすr1を探す
            ll ok1 = w+1;
            ll ng1 = l - 1;
            while(abs(ok1 - ng1)>1) {
               ll mid = ng1+(ok1 - ng1)/2;
               if(ressum(a,l,c,mid)>=k) ok1 = mid;
               else ng1 = mid;
            }
            

            //k+1
            ll ok2 = w+1;
            ll ng2 = l - 1;
            while(abs(ok2 - ng2)>1) {
               ll mid = ng2+(ok2 - ng2)/2;
               if(ressum(a,l,c,mid)>=k+1) ok2 = mid;
               else ng2 = mid;
            }
            ans+=ok2 - ok1;
        }
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