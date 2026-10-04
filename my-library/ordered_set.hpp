#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//上が最低限のおまじない、下が例
 #include<iostream>
 int main() {
    ordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(8);
    s.insert(16);

    // find_by_order : 0-indexed で k 番目に小さい値を指すイテレータを取得する
    // O(log(n))
    std::cout << *s.find_by_order(1) << std::endl; // 2
    std::cout << *s.find_by_order(2) << std::endl; // 4
    std::cout << *s.find_by_order(4) << std::endl; // 16
    std::cout << (s.end() == s.find_by_order(6)) << std::endl; // true

    // おまけ
    // order_of_key : x 未満である要素数を取得する
    // O(log(n))
    std::cout << s.order_of_key(-5) << std::endl;  // 0
    std::cout << s.order_of_key(1) << std::endl;   // 0
    std::cout << s.order_of_key(3) << std::endl;   // 2
    std::cout << s.order_of_key(4) << std::endl;   // 2
    std::cout << s.order_of_key(400) << std::endl; // 5
}