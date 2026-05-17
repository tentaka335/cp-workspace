#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> joiner(N,0);
    vector<ll> winner(N);
        for (ll i=0; i<K; i++) {
        ll a,b;
        cin >> a >> b;
        joiner[a-1]+=1;
        for (ll j=0; j<N; j++) {
            if (joiner[j] == M) {
                cout << j+1 << " ";
                joiner[j] =0;
            }
        }
    }
    
    

}