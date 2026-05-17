#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
ll n;
cin >> n;
string s;
cin >> s;
ll ans = 90000000000000000;
vector<ll> left(n),right(n);

ll leftone = 0;
ll rightone = 0;
for(ll i = 0;i<n;i++) {//ここまで1の塊の右端を持ってくるとき、左側をどれだけ動かすか？
    if(s[i]=='1') {
        leftone++;
       if(i>=1)left[i] = left[i-1];
    }
    else {
        if(i>=1)left[i]=left[i-1] + leftone;
    }
}
for(ll i =n-1;i>=0;i--) {
    if(s[i]=='1') {
        rightone++;
        if(i<n-1) right[i]=right[i+1];
    }
    else {
        if(i<n-1) right[i]=right[i+1] + rightone;
    }
}
for(ll i =0;i<=n-2;i++) {
    ans =min(ans,left[i]+right[i+1]);
}
cout << ans << "\n";
}


