#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S;
    cin >> S;
    sort(S.begin(),S.end());
    if (S[0] == S[1]) {
        cout << S[S.size()-1] << endl;
    } else {
        cout << S[0] << endl;
    }
}