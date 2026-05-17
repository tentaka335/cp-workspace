#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<ll> A(3);
    cin >> A[0] >> A[1] >> A[2];
    if(A[0]*A[1]==A[2]||A[1]*A[2]==A[0]||A[2]*A[0]==A[1]) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}


