#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll gcd(ll x, ll y) {
    if(y<x) swap(x,y);
    while(y%x!=0) {
        ll temp = y%x;
        y = x;
        x = temp;
    }
    return x;
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll POW18 = 1000000000000000000LL;
    ll a,b;
    cin >> a >> b;
    ll c = a/gcd(a,b);
    
    if(c>(POW18/b)) cout << "Large" << "\n";
    else cout << b*c << "\n";

}



/*
最小公倍数LCM(a,b)=a*b/gcd(a,b)であることをまず知ろう、
ただしa*bのオーバーフローに注意し、
a/gcd(a,b)*bとすべき。
とにかくコード中にでてくるすべての数字がオーバーフローしないよう、
乗算の順序を変えたり、if文内の条件を同値変形しておくことが重要
*/


/*#.#.
  ....
  #.#.
  が効率よい？
*/
