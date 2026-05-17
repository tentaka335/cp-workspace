#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
ll n,q;
cin >> n >> q;
vector<bool> A(n+2,false);
ll ans = 0;
for (ll i = 0;i<q;i++) {
    ll a;
    cin >> a;
    if(A[a-1]!=A[a+1]){
        if(A[a]==true) A[a] = false;
        else A[a] = true;
    }
    else if(A[a-1]==true && A[a+1]== true) {
        if(A[a] == false) {//白ー黒
            A[a] = true;
            ans --;
        }
        else {
            A[a] = false;
            ans ++;
        }
    }
    else if (A[a-1]==false && A[a+1]== false) {
         if(A[a] == false) {//白ー黒
            A[a] = true;
            ans ++;
        }
        else {
            A[a] = false;
            ans --;
        }
    }
    cout << ans << "\n";
}
}