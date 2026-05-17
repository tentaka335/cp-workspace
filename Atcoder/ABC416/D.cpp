#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for (ll k = 0;k<t;k++) {
         ll n,m;
    cin >> n>> m;
    map<ll,ll> A,B;
    for (ll i = 0;i<n;i++) {
        ll a;
        cin >> a;
        if(!A.count(a)) A[a] = 1;
        else A[a] += 1;
    }
     for (ll i = 0;i<n;i++) {
        ll b;
        cin >> b;
        if(!B.count(b)) B[b] = 1;
        else B[b] += 1;
    }
    ll modsum = 0;
    for (ll i = 0;i<m;i++) {
        for(auto &b:B) {
            auto key = b.first;
            auto value = b.second;
            if (value == -1) continue;
            if (key>i) {
                if (A.count(m+i-key)) {//Aを使い切った
                    if (value >= A[m+i-key]) {
                        modsum+=i*A[m+i-key];
                          B[key] -=A[m+i-key];
                        if(value == A[m+i-key]) B[key] = -1;
                        A.erase(m+i-key);
                    }
                else {//Bを使い切った
                    modsum+=i*value;
                          A[m+i-key]-=value;
                          B[key] = -1;
                    
                }
            }
        }
        else  { if (A.count(i-key)) {//Aを使い切った
                    if (value >= A[i-key]) {
                        modsum+=i*A[i-key];
                          B[key] -=A[i-key];
                        if(value == A[i-key])  B[key] = -1;
                        A.erase(i-key);
                }
                else {//Bを使い切った
                    modsum+=i*value;
                          A[i-key]-=value;
                           B[key] = -1;
                   
                }
            }
        }
    }
    }
    cout << modsum << "\n";
}
}
