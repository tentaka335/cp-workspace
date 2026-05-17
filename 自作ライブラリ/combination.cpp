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
