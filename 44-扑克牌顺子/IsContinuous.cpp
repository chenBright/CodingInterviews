#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) {
            return false;
        }

        sort(numbers.begin(), numbers.end());

        // 统计0的个数
        int numberOfZero = 0;
        while (numbers[numberOfZero] == 0) {
            ++numberOfZero;
        }

        // 看0能不能填补两个数之间的空缺
        for (int i = numberOfZero + 1; i < numbers.size(); ++i) {
            if (numbers[i] == numbers[i - 1]) { // 如果数组中的非0数字重复出现，则该数组不是连续的
                return false;
            } else { // 否则填补空缺, 无空缺的情况不用单独判断(空缺为0)
                numberOfZero -= numbers[i] - numbers[i - 1] - 1;
            }
        }

        return numberOfZero >= 0 ? true : false;
    }
};