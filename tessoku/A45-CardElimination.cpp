#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    char c;
    cin >> n >> c;
    ll sum = 0;
    vector<ll> C(3);
    for(ll i = 0;i<n;i++) {
        char a;
        cin >> a;
        if(a=='B') sum+=1;
        if(a=='R') sum+=2;
    }
           /*
    //強引に作る
    if((c=='W'&& C[0]>=1)||(c=='B'&& C[1]>=1)||(c=='R'&& C[2]>=1)) {
        if(c=='W') C[0]--;
        if(c=='B') C[1]--;
        if(c=='R') C[2]--;
    }
    else {
        if(c=='W') {
            if(C[1]>=1&&C[2]>=1) {C[1]--;C[2]--;}
            else {cout << "No" << "\n";return 0;}
        }
        if(c=='B') {
            if(C[2]>=2) {C[2]-=2;}
            else {cout << "No" << "\n";return 0;}
        }
         if(c=='R') {
            if(C[1]>=2) {C[1]-=2;}
            else {cout << "No" << "\n";return 0;}
        }
    }
    //目的のカードを取り除いたカード集合をすべてWとすることができるか？
    if(abs(C[1]-C[2]) %3 == 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    */
   if (c=='W' && sum%3 == 0) {cout << "Yes" << "\n";return 0;}
   if (c=='B' && sum%3 == 1) {cout << "Yes" << "\n";return 0;}
   if (c=='R' && sum%3 == 2) {cout << "Yes" << "\n";return 0;}

   cout << "No" << "\n";
   return 0;
} 