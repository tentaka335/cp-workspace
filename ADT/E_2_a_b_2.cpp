#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

unsigned long long isqrt_aux(int c,unsigned long long n){
    if (c == 0){
        return 1;
    } else {
        int k = (c - 1) / 2;
        unsigned long long a = isqrt_aux(c / 2, n >> (2*k + 2));
        return (a << k) + (n >> (k+2)) / a;
    }
}

unsigned long isqrt(unsigned long long n){
    if (n == 0){
        return 0;
    } else {
        unsigned long long a = isqrt_aux(( 63 - __builtin_clzll(n)) / 2, n);
        return n <= a * a - 1 ? a - 1 : a;
    }
}





int main() {
   cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll ans = 0;
   
    for(ll a = 1;(1LL<<a) <=n;a++) {
        ll k = n/(1LL<<a);
        ll b = isqrt(n/(1LL<<a));
        if(b%2==0) b--;
         b = (b+1LL)/2LL;
        ans+=b;
    }
    cout << ans;

    
    
    return 0;
    
/*
    long long N;
cin >> N;
long long ans = 0;

for (int a = 1; ; ++a) {
    long long p2 = 1LL << a; // 2^a
    if (p2 > N) break;

    long long limit_b2 = N / p2;
    long long b_max = sqrt(limit_b2);
    
    // 浮動小数点の誤差対策（念のため前後を確認）
    while ((__int128_t)(b_max + 1) * (b_max + 1) <= limit_b2) b_max++;
    while ((__int128_t)b_max * b_max > limit_b2) b_max--;

    // 1以上b_max以下の奇数の個数
    ans += (b_max + 1) / 2;
    
    // aが60を超えると1LL << aがオーバーフローするので安全策
    if (a >= 60) break; 
}
cout << ans;
*/
}


