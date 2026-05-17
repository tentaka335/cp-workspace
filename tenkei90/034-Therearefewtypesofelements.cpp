#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll n,k;
   cin >> n >> k;
   vector<ll> A(n);
   for(ll i = 0;i<n;i++) cin >> A[i];
   ll left = 0,right = 0,ans = 1,kind = 1;
   map<ll,ll> S;
   S[A[0]]++;
   while(true) {
    if(kind>k){
    S[A[left]]--;
    if(S[A[left]]==0) {
        S.erase(A[left]);
        kind--;
    }
    left++;
    }
    else {
        right++;
        if(!S.count(A[right])) {
            kind++;
        }
        S[A[right]]++;
        if(kind<=k) ans = max(ans,right - left + 1);
    }
    if(right>=n-1||left>=n-1) break;
   }
   cout << ans << "\n";
}

/*#.#.
  ....
  #.#.
  が効率よい？
*/
