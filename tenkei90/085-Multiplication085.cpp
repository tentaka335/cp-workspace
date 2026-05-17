#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;

 vector<ll> divisor(ll n) {
    vector<ll> req;
    if(n<=0) return req;
    for(ll i = 1;i*i<=n;i++) {
        if(n%i==0) {
            req.push_back(i);
            if(n/i!=i) req.push_back(n/i);
        }
    }
    sort(req.begin(),req.end());
    return req;
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll k;
    cin >> k;
    auto divk = divisor(k);
    ll len = divk.size();
    ll ans = 0;
    ll temp;
    if(len%2==0) temp = (len-1)/2;
    else temp = len/2;
    for(ll a = 0;a<=temp;a++) {
        for(ll b = a;b<=temp;b++) {
            ll A = divk[a],B = divk[b];
            if(k%(A*B)==0) {
                if(k/(A*B)>=B) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}


                
 



/*
考察

*/

/*
感想
約数全列挙をライブラリを使わずにその場で書いたので
、その部分でミスっていたのが諸悪の根源。
またオーバーフローにも引っ掛かってしまった。
探索範囲を狭めて解決したが、a*bを登場させないように
k/A==0?=>k/B==0?をしてしまえばよかった
*/



