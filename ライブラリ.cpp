#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//a^bのmodm
long long modpow(long long a, long long n, long long MOD) {
    long long res = 1 % MOD;
    a %= MOD;
    if (a < 0) a += MOD;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

ll nCr (ll n,ll r) {

}


ll gcd(ll x, ll y) {
    if(y<x) swap(x,y);
    while(y%x!=0) {
        ll temp = y%x;
        y = x;
        x = temp;
    }
    return x;
}


int prec(char op){
    if(op == '*' || op == '/') return 1;
    return 0; // + or -
}
    // deduplicate
    for(int i = 1; i <= n; ++i){
        auto &v = A[i];
        if(v.empty()) continue;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    // example output: count per value (and optionally list)
    for(int i = 1; i <= n; ++i){
        cout << i << ": " << A[i].size() << '\n';
        // for (auto &s : A[i]) cout << "  " << s << '\n';
    }
    return 0;
}