#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




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
     ll maxA = A[n-1];

         vector<ll> ans;
    
    if(A[0] == maxA) {
        ans.push_back(A[0]);
    }
   
    //最大値の次との和をゴールとする場合
    auto it = lower_bound(A.begin(),A.end(),maxA);//絶対ある。
    it--;
    ll pos = it - A.begin();
    if(pos%2==1) {
    if(A[0]+A[pos]==maxA) {
        bool ok = true;
        for(ll i = 1;(i<=pos/2);i++) {
            if(A[i]+A[pos-i]!=maxA) {
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(maxA);
    }
}


      //最大値との和をゴールとする場合
    
      pos = n - 1;
     ll goal =  A[0] + A[n-1];
     if(pos%2==1) {
        bool ok = true;
        for(ll i = 1;(i<=pos/2);i++) {
            
            if(A[i]+A[pos-i]!=goal) {
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(goal);
    }
     for(ll i = 0;i<ans.size();i++) cout << ans[i] << " ";
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



