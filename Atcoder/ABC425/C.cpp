#include <bits/stdc++.h>
using namespace std;
using ll = long long;


//vectorを引数にするとそのベクターをまるごとコピーしなきゃいけないため、計算量が増える。
   ll changedsum (ll x,ll csum,vector<ll> &sum,ll n) {
    if(csum == 0) return sum[x];
    else {
        if(x+csum<=n-1) return sum[x+csum] - sum[csum-1];
        else return sum[n-1] + sum[x+csum -n]-sum[csum-1];
    }
   }

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll n,q;
   cin >> n >> q;
   vector<ll> A(n),sum(n,0);

   for ( ll i = 0;i<n;i++) {
    cin >> A[i];
    if(i>=1) sum[i] += sum[i-1] + A[i];
    else sum[i] = A[i];
   }
   ll csum = 0;

   for (ll i =0;i<q;i++) {
    ll qus;
    cin >> qus;
    if(qus==1) {
        ll c;
        cin >> c;
        csum = (csum+c)%n;
    }
    else {
        ll l,r,ans;
        cin >> l >> r;
        if (l==1)ans = changedsum(r-1,csum,sum,n);
        else ans = changedsum(r-1,csum,sum,n)-changedsum(l-2,csum,sum,n);
        cout << ans << "\n";
    }
   }
}
