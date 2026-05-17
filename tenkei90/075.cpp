#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pnum = 0;

void prime_factorize(long long N) {
    
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        pnum+=ex;
    }

    if (N != 1) pnum++;

}

ll divide2 (ll k) {
    if(k == 1) return 0;
    else return divide2((k-(ll)1)/(ll)2+(ll)1) + 1;
}





int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    //素因数分解し素数の個数を得る
     prime_factorize(n);
    cout << divide2(pnum) << "\n";
}
                




/*
素因数の個数pnumを素因数分解によって数える。
素因数分解はfor(a = 2;a*a<=n;a++) の範囲で探索し、
aで割れるなら、割り切れなくなるまで割り切り、割れた回数bを記録していく
n = a^b*...と分解できている。
2^x>=pnumを満たす最小のxが答えである。
なお再帰関数によって実装することもできる。
*/



