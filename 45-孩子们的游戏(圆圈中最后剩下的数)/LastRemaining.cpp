#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1) {
            return -1;
        }

        vector<int> numbers;

        for (int i = 0; i < n; ++i) {
            numbers.push_back(i);
        }

        int step = 0;
        while (numbers.size() > 1) {
            for (int i = 1; i < m; ++i) {
                ++step;
                step %= numbers.size(); // 模拟循环链表
            }
            numbers.erase(numbers.begin() + step);
        }

        return numbers[0];
    }
};