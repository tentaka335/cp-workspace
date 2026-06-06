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
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
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


ll f (ll a,ll b) {
    return a+b;
}
ll e() {
    return 0;
}



void solve(){
    dsu uf(100009);


    ll n ,q;
    cin >> n >> q;

        segtree<ll,f,e> eseg(n+9);
        segtree<ll,f,e> oseg(n+9);



    rep(qi,q) {
        ll qt,x,y,v;
        cin >> qt >> x >> y >> v;

        if(qt==0) {
            
            uf.merge(x,y);
            
            if(x%2==0) {
                eseg.set(x,v);
            }
            else {
                oseg.set(x,v);
            }
        }
        else {

            if(!uf.same(x,y)) {
                cout << "Ambiguous" << "\n";
                continue;
            }
            bool swaped = false;
            if(x>y) {
                swaped = true;
                swap(x,y);
            }
            
            ll ans = 0;
            
            if((y-x)%2==0) {
               
                if(x%2==0) {
                    ans-=eseg.prod(x,y);
                    ans+=oseg.prod(x,y);
                }
                else {
                    ans+=eseg.prod(x,y);
                    ans-=oseg.prod(x,y);
                }
            }
            else {
                //Vxは正になる。
                if(x%2==0) {
                    ans+=eseg.prod(x,y);
                    ans-=oseg.prod(x,y);
                }
                else {
                    ans+=oseg.prod(x,y);
                    ans-=eseg.prod(x,y);
                }
            }

            if(swaped==false) {
                if((y - x)%2==0) {
                    ans+=v;
                }
                else {
                    ans-=v;
                }
                cout << ans << "\n";
            }
            else {
                   if((y - x)%2==0) {
                    ans*=-1;
                    ans+=v;
                }
                else {
                    ans-=v;
                }

                cout << ans << "\n";

            }


            
            
            


        }

    }


}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}