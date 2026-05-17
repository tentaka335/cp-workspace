#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A;
    for(ll i = 0;i<n;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        while(true) {
            ll len = A.size();
            if(len<=1) break;
            
            if(A[len-1]!=A[len-2]) break;
            else {
                ll temp = A[len-1] + 1;
                A.pop_back();
                A.pop_back();
                A.push_back(temp);
            }
        }
    }
    cout << A.size() << "\n";
}
/*すなおに実装するだけvectorのpush/pop_back()を利用しならがら追加削除を行う
最後尾から見て1,2番目の要素にアクセス
ぷよぷよのやつ
良い文字列のやつに似てる。
*/


