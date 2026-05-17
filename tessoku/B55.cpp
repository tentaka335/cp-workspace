#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    set<ll> card;
    for(ll qi = 0;qi<q;qi++) {
        ll qt,x;
        cin >> qt >> x;
        if(qt==1) {
            card.insert(x);
        }
        else {
            if(card.size() == 0) {
                cout << -1 << "\n";
                continue;
            }
           auto it = card.lower_bound(x);
           if(it == card.end()) {
            it--;
            cout << llabs(*it-x) << "\n";
           }
           else if (it == card.begin()) {
            cout << llabs(*it-x) << "\n";
           }
           else {
            auto right = it;
            auto left = --it;
            cout << min(llabs(*left-x),llabs(*right-x)) << "\n";
           }
        }
    }
}