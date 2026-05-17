#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll q;
    cin >> q;
    vector<pair<ll,ll>> snake;
    ll snakesum = 0,lensum = 0,lastsnake = 0;
    for(ll qi = 0;qi<q;qi++) {
        ll qt;
        cin >> qt;
    if(qt==1) {
        ll l;
        cin >> l;
        
        snake.push_back({lastsnake,l});
        lastsnake += l;
    }
    if(qt==2) {
        lensum+=snake[snakesum].second;
        snakesum++;
    }
    if(qt==3) {
        ll k;
        cin >> k;
        cout << snake[k-1+snakesum].first - lensum << "\n";
    }
    }
}


