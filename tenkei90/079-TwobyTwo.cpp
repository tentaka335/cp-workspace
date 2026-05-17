#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;



const ll dx[] = {1,0,1};
const ll dy[] = {0,1,1};


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    vector<vector<ll>> A(h+1,vector<ll>(w+1));
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cin >> A[i][j];

        }
    }
      vector<vector<ll>> B(h+1,vector<ll>(w+1));
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cin >> B[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 1;i<=h-1;i++) {
        for(ll j = 1;j<=w-1;j++) {
            ans+=llabs(B[i][j]-A[i][j]);
            for(ll v = 0;v<3;v++) {
                A[i+dx[v]][j+dy[v]] += B[i][j]-A[i][j];
            }
            A[i][j] = B[i][j];
        }
    }
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            if(A[i][j]!=B[i][j]) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
    cout << ans << "\n";
    return 0;
}
                
 



/*
素因数の個数pnumを素因数分解によって数える。
素因数分解はfor(a = 2;a*a<=n;a++) の範囲で探索し、
aで割れるなら、割り切れなくなるまで割り切り、割れた回数bを記録していく
n = a^b*...と分解できている。
2^x>=pnumを満たす最小のxが答えである。
なお再帰関数によって実装することもできる。
*/



