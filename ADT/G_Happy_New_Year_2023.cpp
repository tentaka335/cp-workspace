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
    
    ll t;
    cin >> t;
    rep(ti,t) {

        

        
        ll n;
                cin >> n;
        for(ll i = 2;i<=3*1000000;i++) {
            if(n%i==0) {
                if((n%(i*i)==0))  {
                    cout << i << " " << n/(i*i) << "\n";
                   
                }
                else {
                    cout << isqrt(n/i) << " " << i << "\n";
                    
                }
                break;
            }
        }

    }
    
    return 0;
}