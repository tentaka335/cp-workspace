#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

struct RandomGenerator {
    std::mt19937_64 rng;

    // デフォルトコンストラクタ: 実行ごとに異なる乱数シードを使用
    RandomGenerator() {
        std::random_device rd;
        rng.seed(rd());
    }

    // シード指定コンストラクタ: テストの再現性（デバッグ）のために固定シードを使用
    explicit RandomGenerator(uint64_t seed) {
        rng.seed(seed);
    }

    // 指定範囲 [min, max] の整数を生成 (閉区間)
    long long nextInt(long long min, long long max) {
        std::uniform_int_distribution<long long> dist(min, max);
        return dist(rng);
    }

    // 指定範囲 [min, max) の実数を生成 (半開区間)
    double nextDouble(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }

    // 指定した確率で true を返す真偽値を生成 (デフォルトは50%)
    bool nextBool(double true_probability = 0.5) {
        std::bernoulli_distribution dist(true_probability);
        return dist(rng);
    }

    // ランダムな文字列を生成 (デフォルトは英数字)
    std::string nextString(size_t length, const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
        std::string result;
        result.reserve(length);
        std::uniform_int_distribution<int> dist(0, charset.length() - 1);
        for (size_t i = 0; i < length; ++i) {
            result += charset[dist(rng)];
        }
        return result;
    }

    // ランダムな整数の配列(vector)を生成
    std::vector<long long> nextIntVector(size_t size, long long min, long long max) {
        std::vector<long long> res(size);
        for (size_t i = 0; i < size; ++i) {
            res[i] = nextInt(min, max);
        }
        return res;
    }
};



int main() {
    // 1. 完全なランダム（通常使用）
    RandomGenerator random_gen;
    
    // 2. シード固定（バグを再現したいテスト用）
    // RandomGenerator random_gen(42); 

    std::cout << "--- Random Testing Data ---" << std::endl;

    // 整数の生成 (例: 1〜100)
    std::cout << "Random Int (1-100): " << random_gen.nextInt(1, 100) << std::endl;

    // 浮動小数点数の生成 (例: 0.0〜1.0)
    std::cout << "Random Double (0.0-1.0): " << random_gen.nextDouble(0.0, 1.0) << std::endl;

    // 真偽値の生成 (例: 80%の確率でtrue)
    std::cout << "Random Bool (80% true): " << (random_gen.nextBool(0.8) ? "true" : "false") << std::endl;

    // 文字列の生成 (例: 長さ10のランダム文字列)
    std::cout << "Random String (length 10): " << random_gen.nextString(10) << std::endl;

    // カスタム文字セットでの文字列生成 (例: DNA配列)
    std::cout << "Random DNA (length 15): " << random_gen.nextString(15, "ACGT") << std::endl;

    // 配列の生成 (例: 0〜9の範囲で5要素の配列)
    std::vector<long long> vec = random_gen.nextIntVector(5, 0, 9);
    std::cout << "Random Vector: [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}