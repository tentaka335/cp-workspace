#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> enumerate_prime(ll n) {
    vector<ll> ret;
    vector<bool> mark(n+1);
    mark[1] = true;
    for (ll i = 2; i<n; i++) {
        if (mark[i]) {  
            continue;
        }
        ret.push_back(i);
        for (ll j = 2*i; j <= n; j += i) {
            mark[j] = true;
        }       
        
    }
    return ret;
}

int main() {
    ll n = 0;
    cin >> n ;
    cout << enumerate_prime(n).size() << endl;

    /*for (ll i = 0; i < privec.size(); i++) {
        cout << privec[i]. << "\n";
    }*/
}


