#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll D,N;
    cin >> D >> N;
    vector<ll> zenzituhi(D+1,0),join(D+1,0);
    for (ll i=1; i<=N; i++) {
        ll L,R;
        cin >> L >> R;
        zenzituhi[L] +=1;
        zenzituhi[R+1] -=1;
    }
    
    for (ll i=1; i<=D;i++) {
        join[i] = zenzituhi[i] + join[i-1];
        cout << join[i] << endl;
    }

}