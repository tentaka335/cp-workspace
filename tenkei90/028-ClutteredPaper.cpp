#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> grit(1009,vector<ll>(1009));
    vector<ll> A(n+1);
    for(ll i = 0;i<n;i++) {
        ll lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        lx++;ly++;rx++;ry++;
        grit[lx][ly]++;grit[lx][ry]--;grit[rx][ly]--;grit[rx][ry]++;
    }
    for(ll i = 1;i<=1001;i++) {
        for(ll j = 1;j<=1001;j++) {
            grit[i][j] = grit[i][j-1] + grit[i][j];
        }
    }
       for(ll i = 1;i<=1001;i++) {
        for(ll j = 1;j<=1001;j++) {
            grit[i][j] = grit[i-1][j] + grit[i][j];
        }
    }
    for(ll i = 1;i<=1001;i++) {
        for(ll j = 1;j<=1001;j++) {
            A[grit[i][j]]++;
        }
    }
    for(ll i = 1;i<=n;i++) cout << A[i] << "\n";
}

/*二次元imos法二次元配列全体にアクセスするのではなく、
端っこに+1,-1して累積和を取ることによって
ある範囲にかけて何かがあることを表現できる。
今回は紙の端の点を与えられているので、
グリットの中心に座標が対応している考え方と
グリットの交点に座標が対応している考え方の
の違いに注意。
*/
