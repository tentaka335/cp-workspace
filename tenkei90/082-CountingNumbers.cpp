#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;






int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll l,r;
    cin >> l >> r;

    

    auto y = [](ll x) {
        string z = to_string(x);
        ll len = z.size();
        ll res = 0;
        x %=pow9p7;
        vector<ll> pow10(20);
    pow10[0] = 1;
    for(ll i = 1;i<=18;i++) {
        pow10[i] = (pow10[i-1]*10)%pow9p7;
    }
        for(ll i = 1;i<=len-1;i++) {

            res = (res + (((pow10[i]-pow10[i-1])*((pow10[i]-1+pow10[i-1]))/2)%pow9p7)*i)%pow9p7;
        }
        res = (res+(((x-pow10[len-1]+1)*((x+pow10[len-1]))/2)%pow9p7)*len)%pow9p7;
        return (res + pow9p7)%pow9p7;
    };

    cout << (y(r)-y(l-1) + pow9p7)%pow9p7 << "\n";
}
                
 



/*
考察
1~xまでの黒板に書かれる回数を求める関数f(x)を作ると
答えはf(r)-f(l-1)とすることができる。
f(x) はxの桁数lenを取得し、
i = 1~len-1までi*(10^(i-1)から10^i-1までの和)を足し、
さらに len*(10^(len-1)からxまでの和)を足すと求められる。
今回の場合、pow10[a]>=pow[b] (a>=b) がmodにより成り立たないことがあるため、
f(x)を求める途中の計算で値が負になることがある。最後に強引に+pow9p7)%pow9p7するか
unsigned long long を利用する。なお逆元を用いてうまくいく別の方法もあるらしい。

「1000000007で割ったあまりの求め方の総特集」という記事があるらしい。
*/

/*
感想

総和の求め方、/2により答えが合わなくなることなどに戸惑った。
また、もはやあまりを求める際は絶対に+pow9p7)pow9p7した方がいいかも。
*/



