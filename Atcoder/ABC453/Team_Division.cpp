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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
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



vector<ll> fac,finv,inv;

//二項係数の前計算
//n:=二項係数xCyを求める時の最大のx
void COMinit(ll n) {
    fac.resize(n+1);
    finv.resize(n+1);
    inv.resize(n+1);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(ll i = 2;i<=n;i++) {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

// 二項係数の演算
ll COM(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


void solve(){

    ll n;
    cin >> n;
    
    vector<ll> L(n+1),R(n+1),onlyA(n+9),onlyB(n+9),both(n+9);//Aがi人であるときの、Aにしか、Bにしか、bothにいける人数

    nfor(i,1,n+1) {
        cin >> L[i] >> R[i];
        ll bothl = max(L[i],n - R[i]);
        ll bothr = min(R[i],n - L[i]);

        if(bothl<=bothr) {//共通部分が存在 bothがある imos法

                both[bothl]++;
                both[bothr+1]--;

            if(L[i]+R[i]==n) {

           
            }
            else if(L[i]<n - R[i]) {//A区間のが右
                onlyA[L[i]]++;
                onlyA[bothl]--;
                onlyB[bothr+1]++;
                onlyB[n - L[i]+1]--;
                
            }
            else {//A
                onlyA[bothr+1]++;
                onlyA[R[i]+1]--;
                onlyB[n - R[i]]++;
                onlyB[bothl]--;//バグらせ
            }


        }
        else {
            onlyA[L[i]]++;
            onlyA[R[i]+1]--;
            onlyB[n-R[i]]++;
            onlyB[n-L[i]+1]--;//バグらせ
        }


    }
    for(ll i = 1;i<=n;i++) {
        onlyA[i] += onlyA[i-1];
        onlyB[i] += onlyB[i-1];
        both[i] += both[i-1];
    }

    mint ans = 0;
    for(ll i = 1;i<=n-1;i++) {
        if(i<onlyA[i]||n-i<onlyB[i]) continue;

        
        
        else if(onlyA[i]+both[i]+onlyB[i]==n) {
            ans +=COM(both[i],i - onlyA[i]);
        }
    }


    cout << ans.val() << "\n";



}

void solve2 () {
    ll n;
    cin >> n;
    vector<ll> d(n+2),d2(n+2);

    rep(i,n) {
        ll l,r;
        cin >> l >> r;
        d[l]++;d[r+1]--;

        l = max(l,n-r);
        r = min(r,n-l);
        if(l<=r) {
            d2[l]++;d2[r+1]--;
        }
    }
    for(ll i = 1;i<n;i++) {
        d[i] +=d[i-1];
        d2[i]+=d2[i-1];
    }

    mint  ans = 0;
    nfor(x,1,n) {
        ll  y = n - x;
        ll a = d[x] - d2[x], b = d[y] - d2[x];
        if(x<a||y<b) continue;

        if(a + d2[x] + b == n) {
            ans+=COM(d2[x],x - a);
        }

    }

    cout << ans.val() << "\n";


}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    COMinit(200009);
    
    
    
 solve2();
    return 0;
}