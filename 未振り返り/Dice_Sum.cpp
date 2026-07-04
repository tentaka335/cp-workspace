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
 
 
 ll n,m,k;
 cin >> n >> m >> k;
 vector<vector<mint>> dp(n+9,vector<mint>(2509,0));
 //dp[i][j] :=i番目まで決めたときの総和がjである通り数
 dp[0][0] = 1;
 nfor(i,1,n+1) {
    nfor(j,1,k+1) { 
        nfor(a,1,m+1) {
            if(j>=a) dp[i][j]+=dp[i-1][j-a];
        }
    }
 }
 
 mint sum = 0;
 nfor(j,1,k+1) {
    sum+=dp[n][j];
 }

 cout << sum.val() << "\n";
 
}

void naive() {
    ll n ,m,k;
    cin >> n >> m >> k;


    vll A;

    mint ans = 0;

    auto f = [&] (ll a,auto f)->void {
        
        
        rep(i,A.size()) cerr << A[i] << " ";
        cerr << "\n";

        
        if(a > n) {
            ll sum = 0;
         rep(i,n) sum+=A[i];
         if(sum<=k) ans+=1;
         return ;
        }

        nfor(i,1,m+1) {
            A.push_back(i);
            f(a+1,f);
            A.pop_back();
            
        }


        
    };
    

    f(1,f);
   cout << ans.val() << "\n";
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 naive();
    return 0;
}