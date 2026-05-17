#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll n,q;
   cin >> n >> q;
   vector<ll> A(n+1);
   vector<ll> B;
   vector<ll> invB;
   vector<ll> invA;

   for(ll i = 1;i<=n;i++) {
     cin >> A[i];
   }
   sort(A.begin(),A.end());
for(ll i = 0;i<=n;i++) {
    if(i==n) {
        B.push_back(A[i]+1);
        invB.push_back(A[i]-i+1);
    }
    else if(A[i+1]!=A[i]+1) {
        B.push_back(A[i]+1);
        invB.push_back(A[i]-i+1);
    }

}

for(ll qi = 0;qi<q;qi++) {
    ll x,y;
    cin >> x >> y;
    auto it = lower_bound(B.begin(),B.end(),x);
    ll ans = 0;
    ll pos;
    if(it==B.end()) {
        pos = B.size()-1;
        ans--;
    }
    else {
        pos = it - B.begin();
    }
    ll z = invB[pos] + x - B[pos];
    if(x<=B[0]) z = 0;    //x未満でリストに含まれないものの個数。
//ここからz+y番目が何かを求める。
ll k = z + y;
auto it2 = lower_bound(invB.begin(),invB.end(),k);
ll index;
if(it==B.end()) {
    index = invB.size() - 1;
}
else {
    index = it2 - invB.begin();
}


    ans += (z + y - invB[index]) + B[index];
cout << ans << "\n";

}

}