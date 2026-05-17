#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll k;
    cin >> k;
    ll POW9p7 = 1000000007;
    vector<ll> DP(k+1);
    for(ll i = 1;i<10;i++) {
        DP[i] = (1<<(i-1));
    }
    for(ll i = 10;i<=k;i++) {
        for(ll j = 1;j<=9;j++) {
            DP[i] = (DP[i] + DP[i-j])%1000000007;
        }
    }
    cout << (k%9==0?DP[k]:0) << "\n";
}




/*
桁数の和はn>=10において
f(n) = f(n-1) + f(n-2) + f(n-3) +...f(n-9);
であるこれは簡単で前に1~9の数字をつけるという考えから成り立つ。
これをDPに落とし込めば、桁和がxになるような数字の個数
は求めることができる。
*/



