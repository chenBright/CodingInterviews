#include <vector>
using namespace std;

// 自底向上计算，并在计算的过程中缓存已经计算过的值
class Solution {
public:
    int Fibonacci(int n) {
        int fibonacci_1 = 0, fibonacci_2 = 1, fibonacciResult;
        if (n == 0) {
            return fibonacci_1;
        }
        if (n == 1) {
            return fibonacci_2;
        }

        for (int i = 2; i <= n; ++i) {
            fibonacciResult = fibonacci_1 + fibonacci_2;
            fibonacci_1 = fibonacci_2;
            fibonacci_2 = fibonacciResult;
        }

        return fibonacciResult;
    }

};