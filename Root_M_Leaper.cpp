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
vector<vector<vector<Pll>>> G(n+9,vector<vector<Pll>>(n+9));

nfor(i,1,n+1) {
    nfor(j,1,n+1) {
        nfor(k,1,n+1) {
            ll sq = m - (i - k)*(i-k);
         
            bool issq = true;
            if(sq<0) issq = false;
            else {
                ll ok = 0;
                ll ng = sq+1;
                while(abs(ok - ng)>1) {
                ll mid = ok +(ng - ok)/2;
                if(mid*mid<=sq) ok = mid;
                else ng = mid;
                }
                if(ok*ok!=sq) issq = false;
            }
            
            if(issq) {
                ll upper = j + (ll)(sqrt(sq));
                
                if(1<=upper&&upper<=n) {
                    G[i][j].push_back({k,upper});
                }
                ll lower = j - (ll)(sqrt(sq));
               
                if(1<=lower&&lower<=n) {
                    G[i][j].push_back({k,lower});
                }
            }
            
        }
    }
}
    vvll dist(n+9,vll(n+9,-1));
    dist[1][1] = 0;
    queue<Pll> Q;
    Q.push({1,1});
    while(!Q.empty()) {
        auto[i,j] = Q.front();
        Q.pop();
        for(auto[nx,ny]:G[i][j]) {
            if(dist[nx][ny]==-1) {
                dist[nx][ny] = dist[i][j] + 1;
             
                Q.push({nx,ny});
            }
        }
    }

    nfor(i,1,n+1) {
        nfor(j,1,n+1) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}