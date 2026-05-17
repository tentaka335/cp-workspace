#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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

int main () {
    ll n;
    cin >> n;
    ll ans = 0;
    
    for(ll a = 1;(ll)((ll)1<<a)<=n;a++) {
        ll b = isqrt(n/(ll)((ll)1<<a));//この平方根を超えない最大の整数を取る
        if (b%2==0) b--;//無理やり奇数にする
        ans+= (b+1)/2;
    }
    cout << ans << "\n";
}

/*・今日起きた事実 シフト演算においてうまくいかない。c++は平方根を超えない整数を返す関数はない。
・事実から気づいたこと　型キャストを行わないと、intになってオーバーフローすることがある。n3のisqrtをもらうか二分探索する。
・気づきから得られた教訓　その計算がintで行われているか、llで行われているか注意する。
・自分がありたい姿を宣言する　上の教訓を体得したプレイヤーになる。
*/

