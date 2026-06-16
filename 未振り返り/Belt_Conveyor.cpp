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

bool outgrid(ll x,ll y,ll h,ll w) {
    if(0<=x&&x<=h-1&&0<=y&&y<=w-1) return false;
    else return true;
}
void solve(){

    ll h,w;
    cin >> h >> w;
    vector<vector<char>> grit(h+9,vector<char>(w+9));
    vector<vector<bool>> seen(h+9,vector<bool>(w+9));

    rep(i,h) {
        rep(j,w) {
            cin >> grit[i][j];
        }
    }

    ll x = 0,y = 0;
    seen[x][y] = true;
    while(1) {
        ll nx,ny;
        if(grit[x][y] =='D') {
            nx = x+dx[0];
            ny = y +dy[0];
        }
        if(grit[x][y] =='R') {
            nx = x+dx[1];
            ny = y +dy[1];
        }
        if(grit[x][y]=='U') {
            nx = x+dx[2];
            ny = y + dy[2];
        }
        if(grit[x][y]=='L') {
            nx = x +dx[3];
            ny = y+dy[3];
        }
        if(outgrid(nx,ny,h,w)) {
            cout << x+1 << " " << y+1 << "\n";
            return ;
        }

        x = nx,y = ny;
        if(seen[x][y]==true) {
            dame;
            return ;
        }

        seen[x][y] = true;

        

        
    }

}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}