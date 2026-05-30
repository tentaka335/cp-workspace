#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isOK(ll index, ll key) {
    if (true/*条件式*/) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = -1; //絶対にisOKを満たさない初期値
    ll ok = 9e18; //絶対にisOKを満たす初期値
    
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid =  ng + (ok - ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}
