#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
bool check (float x) {
    if(x*x*x + x >= n) {
        return true;
    }
    return false;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    float left = 0,right = n;
    while(right - left > 0.0001) {
        float mid = (left + right)/2;
        auto ans = check(mid);
        if(check(mid) == true) right = mid +0.00001;
        if(check(mid) == false) left = mid - 0.00001 ;
    }
    cout << left << endl;
}