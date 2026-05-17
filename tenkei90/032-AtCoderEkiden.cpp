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
    vector<ll> P(n);
    vector<vector<ll>> A(n,vector<ll>(n));

    for(ll i = 0;i<n;i++) {
        P[i] = i;
    }
    ll ans = 10001;
    for(ll i = 0;i<n;i++) {
        for(ll j = 0;j<n;j++) {
            cin >> A[i][j];
        }
    }
    ll m;
    cin >> m;
    set<Pll> dislike;
    for(ll i = 0;i<m;i++) {
        ll x,y;
        cin >> x >> y;
        dislike.insert({x-1,y-1});
    }
    do {
        ll cnt = A[P[0]][0];
        bool hunaka = false;
        for(ll i = 1;i<n;i++) {
            if(dislike.count({P[i],P[i-1]})||dislike.count({P[i-1],P[i]})) {
                hunaka = true;
                break;
            }
            cnt+=A[P[i]][i];
        }
        if (hunaka) continue;

        ans = min(ans,cnt);

    } while(next_permutation(P.begin(),P.end()));
    cout << (ans==10001?-1:ans) << "\n";
}

/*順列全探索を実装できるかの問題。
P={1,2,3,4,5,6,7,8,9,10}のように、最も小さい順列
で初期化しないと全探索は行われないこと、
重複には対応していないことに注意。
不仲の判定は不仲なペア集合dislikeを作って実装すると
よさそうだった。
*/
