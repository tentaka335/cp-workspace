#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> masu(H+2);
    string s(W+2,'.');
    masu[0] = s;
    masu[H+1] = s;
    for (ll i = 1; i<=H; i++) {
    string ss;
    cin >> ss;
    masu[i] = "."+ss+".";
    }

   // cout << s << endl;
    for (ll i = 0; i<=H+1; i++) {
        cout << masu[i] << endl;
    }

    for (ll i=1; i<= H;i++) {
        for (ll j = 1; j <=W; j++) {
            ll count =0;
            if (masu[i][j] == '#') {
                if (masu[i-1][j] == '#') count ++;
                if (masu[i+1][j] == '#') count ++;
                if (masu[i][j-1] == '#') count ++;
                if (masu[i][j+1] == '#') count ++;
                if (count !=2 && count != 4) {
                    cout << "No" << endl;
                    return 0;
                }

            }
        }
    }


    cout << "Yes" << endl;
}