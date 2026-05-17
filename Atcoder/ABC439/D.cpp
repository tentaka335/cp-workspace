#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n);
    map<ll,ll> rightmap,leftmap;
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        if(!rightmap.count(A[i])) {
            rightmap[A[i]] = 1;
        }
        else {
            rightmap[A[i]]+=1;
        }
    }
    ll ans = 0;
    for(ll j = 0;j<n;j++) {
        if(A[j]%5==0) {
            if(rightmap.count(7*A[j]/5)&&rightmap.count(3*A[j]/5)) {
                ans+=rightmap[7*A[j]/5]*rightmap[3*A[j]/5];
            }
            if(leftmap.count(7*A[j]/5)&&leftmap.count(3*A[j]/5)) {
                ans+=leftmap[7*A[j]/5]*leftmap[3*A[j]/5];
            }
        }
        
        //ここからは交換処理
        rightmap[A[j]]--;
        //0になってもうまくいくはず。
        if(!leftmap.count(A[j])) leftmap[A[j]] = 1;
        else leftmap[A[j]] +=1;
    }
    cout << ans << "\n";
}