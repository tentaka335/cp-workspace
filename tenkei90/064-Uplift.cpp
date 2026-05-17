#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,q;
    cin >> n >> q;
    vector<ll> A(n);
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }
    vector<ll> D(n-1);
    ll ans = 0;
    for(ll i = 0;i<n-1;i++) {
        D[i] = A[i]-A[i+1];
        ans +=llabs(D[i]);
    }

    for(ll qi = 0;qi<q;qi++) {
        ll l,r,v;
        cin >> l >> r >> v;
        l--;r--;//0-index化
        if(l>=1) {
            ans-=llabs(D[l-1]);
            D[l-1] -=v;
            ans +=llabs(D[l-1]);
        }
        if(r<n-1) {
            ans -= llabs(D[r]);
            D[r] +=v;
            ans +=llabs(D[r]);
        }
        cout << ans << "\n";
    }
                
}



/*
今回の鍵は階差更新。まずD[i] =A[i]-A[i+1]という階差の配列を保持する。
各クエリごとにA[i]を更新するのではなく、D[i]を更新していけばよい。
A[i]の更新はO(l-r)<=O(n)だが、D[i]の更新はl,r付近のみ見ればよいため、
O(2)であるから十分高速である。クエリ処理を行った後の答えはΣabs(D[i])ゆえ
更新前を引き、更新後のans(D[i])を足せばよい。
*/



