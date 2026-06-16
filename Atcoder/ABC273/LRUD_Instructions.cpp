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
    if(1<=x&&x<=h&&1<=y&&y<=w) return false;
    else return true;
}
 
 
 
 
 
 
 
 
void solve(){
    ll h,w,sx,sy;
    cin >> h >> w >> sx >> sy;
    ll n;
    cin >> n;

    map<ll,set<ll>> xtoy;//x上にあるブロック
    map<ll,set<ll>> ytox;
    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        xtoy[x].insert(y);
        xtoy[x].insert(0);
        xtoy[x].insert(w+1);
        ytox[y].insert(x);
        ytox[y].insert(0);
        ytox[y].insert(h+1);
        
    }
    
    ll q;
    cin >> q;
    rep(qi,q) {
        char d;ll l;
        cin >> d >> l;
        ll nx,ny;
        
        if(d=='L') {
            nx = sx,ny = sy - l;
            if(outgrid(nx,ny,h,w)) ny = 1;

            if(xtoy.count(nx)) {
                auto it = xtoy[nx].lower_bound(sy);
                    it--;
                    if(ny<=*it) {
                        sx = nx;
                        sy = *it+1;
                    }
                    else {
                        sx = nx;
                        sy = ny;
                    }
                }
            
            else {
                sx = nx;
                sy = ny;
            }

        }
        else if(d=='R') {
            nx = sx,ny = sy + l;
            if(outgrid(nx,ny,h,w)) ny = w;

            if(xtoy.count(nx)) {
                auto it = xtoy[nx].lower_bound(sy);

        
                    if(*it<=ny) {
                        sx = nx;
                        sy = *it-1;
                    }
                    else {
                        sx = nx;
                        sy = ny;
                    }
                
            }
            else {
                sx = nx;
                sy = ny;
            }


        }
        else if(d=='U') {

             nx = sx - l,ny = sy ;
            if(outgrid(nx,ny,h,w)) nx = 1;

            if(ytox.count(ny)) {
                auto it = ytox[ny].lower_bound(sx);
             
                
            
                    it--;
                    if(nx<=*it) {
                        sx = *it+1;
                        sy = ny;
                    }
                    else {
                        sx = nx;
                        sy = ny;
                    }
                
            }
            else {
                sx = nx;
                sy = ny;
            }


        }

        else if(d=='D') {
             nx = sx + l,ny = sy;
            if(outgrid(nx,ny,h,w)) nx = h;

            if(ytox.count(ny)) {
                auto it = ytox[ny].lower_bound(sx);
           
                    if(*it<=nx) {
                        sx = *it-1;
                        sy = ny;
                    }
                    else {
                        sx = nx;
                        sy = ny;
                    }
                
            }
            else {
                sx = nx;
                sy = ny;
            }

        }

        cout << sx << " " << sy << "\n";

    }
 
 
 
 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}