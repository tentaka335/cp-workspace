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
    vector<ll> A(n);
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<ll> ans;
    ll digit = 1;
    ll sum = 0;
    while (true) {
        //>=digitを求める
        auto it = lower_bound(A.begin(),A.end(),digit);
        if(it==A.end()) {
              if(sum==0) break;
            ans.push_back(sum%10);
            sum = sum/10;
        } else {//寄与するやつがいる場合
            ll pos = it - A.begin();
            ll upnum = n - pos;
            ll ansdi = sum + upnum;
            ans.push_back(ansdi%10);
            sum = ansdi/10;
        }
        digit++;
    }
    for(ll i = ans.size()-1;i>=0;i--) cout << ans[i];
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



