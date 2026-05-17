#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;

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


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    if (n == 1) {
        cout << (k % pow9p7) << "\n";
        return 0;
    }
    if (n == 2) {
        cout << (k * (k - 1) % pow9p7) << "\n";
        return 0;
    }
    ll ans = k * (k - 1) % pow9p7;
    ans = (ans * modpow(k - 2, n - 2, pow9p7)) % pow9p7;
    cout << ans << "\n";
}
                




/*
今回の鍵は階差更新。まずD[i] =A[i]-A[i+1]という階差の配列を保持する。
各クエリごとにA[i]を更新するのではなく、D[i]を更新していけばよい。
A[i]の更新はO(l-r)<=O(n)だが、D[i]の更新はl,r付近のみ見ればよいため、
O(2)であるから十分高速である。クエリ処理を行った後の答えはΣabs(D[i])ゆえ
更新前を引き、更新後のans(D[i])を足せばよい。
*/



