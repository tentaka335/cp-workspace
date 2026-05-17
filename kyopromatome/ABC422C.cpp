#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans (ll A, ll B, ll C) {
   
    ll ans = 0;
    if (min(min(A,B),C) == A || min (min(A,B),C) == C) {
        ans += min(min(A,B),C);
        return ans;
    }

    if (min ((A,B),C) == B) {
        ans += B;
        A -= B;
        C -= B;
        if (max(A,C)>=2*min(A,C)) {
            ans+= min(A, C);
            return ans;
        } else { 
            ans += max(A,C)-min(A,C);
             A =2*min(A,C)-max(A,C); //小さい方引く差
             C = A;
             if (A%3 == 0) {
                ans += A/3*2;
             }
             if (A%3 == 1) {
                ans += A/3*2;
             }
             if (A%3 == 2) {
                ans += A/3*2+1;
             }
            
        }
    }
    return ans;
}

int main() {
    ll T;
    cin >> T;
    vector<vector<ll>> input(T,vector<ll>(3));
    
    for (ll i = 0; i<T; i++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    for (ll i = 0; i<T; i++) {
        cout << ans(input[i][0],input[i][1],input[i][2]) << endl;
    }

}