#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n;
    cin >> n;
    vector<ll> P(n,0);
    vector<ll> A(n-1,0);
    for(ll i = 0;i<n;i++) cin >> P[i];
    for(ll i =0;i<n-1;i++) {
        if(P[i]<P[i+1]) A[i] = 1;
        else A[i] = -1;
    }
    ll semians = 0;
    ll incre = 0;
    ll  phasetype = 1;
    ll lastans = 0;
    for(ll i = 0;i<n-1;i++) {
        if(phasetype == 1) {
        if(A[i] == 1) {
            semians++;
            lastans += incre;
        }
        if(A[i] == -1) {
            phasetype = 2;
            incre = 0;
        }
        }
        else if (phasetype==2) {
            if(A[i] == 1) {
                incre = semians;
                lastans += incre;
                semians = 1;
                phasetype = 1;
            }
            else if(A[i] == -1) {
            }
        }
    }
    cout << lastans << "\n";
}