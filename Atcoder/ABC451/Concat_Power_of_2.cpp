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
void solve(){


    ll n;
    cin >> n;

  
    vector<ll> ans;
    vector<unordered_set<ll>> S(10);
    for(ll i = 1; ;i*=2) {
        string  s = to_string(i);
        ll len  =s.size();
        if(len>=10) break;

        S[len].insert(i);
        ans.push_back(i);
    }

    for(ll i = 2;i<=9;i++) {//i桁の良い数をすべて探す

        for(ll j = 1;j<=i-1;j++) {
            for(auto &p : S[j]) {
                for(auto &q : S[i - j]) {
                    string s = to_string(p) + to_string(q);
                    
                    if(!S[i].count(stoi(s))) {
                        S[i].insert(stol(s));
                        ans.push_back(stol(s));
                    }

                    
                }
            }
        }
    }

    sort(all(ans));
    cout << ans[n-1] << "\n";


}

void solve2() {
    
    ll n;
    cin >> n;

    vector<string> bs;
    for(ll i = 1;i<(ll)1e9;i*=2) {
        bs.push_back(to_string(i));
    }

    vll good;
    auto f = [&] (auto f ,string s)->void {
    
        for(string b  : bs) {
            string ns = s + b;
            if(ns.size()>9) break;
            good.push_back(stol(ns));
            f(f,ns);
     
        }

   

        
    };

    f(f,"");
    sort(all(good));
    good.erase(unique(good.begin(),good.end()),good.end());
    
    cout << good[n-1] <<"\n";

}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve2();
    return 0;

    //58分もかかってしまった。
}