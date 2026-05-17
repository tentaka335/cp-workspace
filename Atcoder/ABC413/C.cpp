//vectorだとq(rep i 0 q)*q(要素にアクセスする回数）が最悪計算量で無理だった。
//テストケースはあっているのだから、他の要素を疑うべきだった。
//vector ->　queueにしたらうまくいった！
//erase は O(n)だったからO(q*q)になってしまった。










#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    queue<pair<ll,ll>> A;
    for (ll i = 0; i < q;i++) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll c,x;
            cin >> c >> x;
            A.push(make_pair(x,c));
        }
        else {
            ll k,ans = 0;
            cin >> k;
            while(k>0) {
                if (k-A.front().second<0) {
                    ans += A.front().first*k;
                    A.front().second = A.front().second-k;
                    break;
                }
                else {
                    ans+= A.front().first*A.front().second;
                    k -=A.front().second;
                    A.pop();
                }
            }
            cout << ans << "\n";
        }
    }
}
