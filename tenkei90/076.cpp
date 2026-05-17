#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;






int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(2*n);
    ll sum = 0;
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        sum +=A[i];
        A[i+n] = A[i];
    }
    if(sum%10!=0) {
        cout << "No" << "\n";
        return 0;
    }
    sum/=10;

    ll left = 0,right = 0,subsum = A[0];
    while(left<=n-1&&right<=(2*n-2)) {
        if(subsum==sum) {
            cout << "Yes" << "\n";
            return 0;
        }
        else if(subsum<sum) {
            right++;
            subsum +=A[right];
        }else if(subsum>sum) {
            subsum -=A[left];
            left++;
        }
    }
    cout << "No" <<"\n";
}
                




/*
素因数の個数pnumを素因数分解によって数える。
素因数分解はfor(a = 2;a*a<=n;a++) の範囲で探索し、
aで割れるなら、割り切れなくなるまで割り切り、割れた回数bを記録していく
n = a^b*...と分解できている。
2^x>=pnumを満たす最小のxが答えである。
なお再帰関数によって実装することもできる。
*/



