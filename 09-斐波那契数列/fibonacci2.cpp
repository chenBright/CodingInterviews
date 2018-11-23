#include <vector>
using namespace std;

// 自底向上计算，并在计算的过程中缓存已经计算过的值
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> results;
        results.push_back(0);
        results.push_back(1);

        for (int i = 2; i <= n; ++i) {
            int sum = results[i - 1] + results[i - 2];
            results.push_back(sum);
        }

        return results[n];
    }

};