#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 座標を表す構造体
struct Point {
    long long x, y;
};

int main() {
    // 基準点 P_j から見た他の点の相対座標が入っているとする
    vector<Point> vec = { {1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {2, 2} };

    // 領域を判定するラムダ式 (上半平面=0, 下半平面=1)
    auto get_area = [](Point p) {
        if (p.y > 0 || (p.y == 0 && p.x > 0)) return 0;
        return 1;
    };

    // 偏角ソート (ラムダ式を比較関数として渡す)
    sort(vec.begin(), vec.end(), [&](Point a, Point b) {
        int areaA = get_area(a);
        int areaB = get_area(b);

        // 1. 領域が違う場合は、領域番号が小さい方が先
        if (areaA != areaB) {
            return areaA < areaB;
        }

        // 2. 領域が同じ場合は外積で判定 (a.x * b.y - a.y * b.x)
        long long cross = a.x * b.y - a.y * b.x;
        if (cross != 0) {
            return cross > 0; // 外積が正なら a の方が先 (反時計回り)
        }

        // 3. 外積が0 (同一直線上) の場合は、原点からの距離が近い順
        long long distA = a.x * a.x + a.y * a.y;
        long long distB = b.x * b.x + b.y * b.y;
        return distA < distB;
    });
    //tips sortにコンパレータf(a,b)を渡すとf(a,b)==true ならa,falseならbが先にくるよう並べ替える。順位が同じ場合はfalseを返さないといけない(厳密な弱順序)

    // 結果の確認
    for (auto p : vec) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}