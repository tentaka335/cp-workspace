#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,X,Y,A[100009];
ll grundy[100009];

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> X >> Y;
    for (ll i = 1;i<=N;i++) cin >> A[i];

    for (ll i = 0;i<=100000;i++) {
        bool transit[3] ={false,false,false};
        if(i>=X) transit[grundy[i-X]] = true;
        if(i>=Y) transit[grundy[i-Y]] = true;
        if(transit[0] == false) grundy[i] = 0;
        else if (transit[1] == false) grundy[i] = 1;
        else grundy[i] = 2;

    }
ll xor_sum = 0;
          for (ll i = 1;i<=N;i++) xor_sum = (xor_sum^grundy[A[i]]);
          if (xor_sum != 0) cout << "First" << "\n";
          if (xor_sum == 0) cout << "Second" << "\n";
        return 0;
}