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
const ll ddx[8] = {1,0,-1,0,1,1,-1,-1};
const ll ddy[8] = {0,1,0,-1,1,-1,-1,1};
void solve(){

    ll n,k;
    cin >> n >> k;
    vvll grit(5009,vll(5009));
    vvll sum(5009,vll(5009));
    
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        grit[a][b]++;
    }
    
    for(ll x = 1;x<=5000;x++) {
        for(ll y = 1;y<=5000;y++) {
            sum[x][y] = sum[x][y-1] + grit[x][y];
        }
    }
    
    for(ll x = 1;x<=5000;x++) {
        for(ll y = 1;y<=5000;y++) {
            sum[x][y] += sum[x-1][y];
        }
    }
    ll ans = 0;

    for(ll x = 1;x<=5000;x++) {
        for(ll y = 1;y<=5000;y++) {
            if(x+k<=5000&&y+k<=5000) {
                ll dx = x+k;
                ll dy = y + k;
                ll temp = 0;
                temp+=sum[dx][dy];
                temp-=sum[dx][y-1];
                temp-=sum[x-1][dy];
                temp+=sum[x-1][y-1];
                chmax(ans,temp);
               
              
                

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