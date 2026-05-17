#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<string> room(N);
    for (ll i = 0; i<N; i++) {
        cin >> room[i];
    }
    ll X ;
    string Y;
    cin >> X >> Y;
    if(Y == room[X-1]) {
        cout << "Yes" << endl; 
    } else cout << "No" << endl;
}