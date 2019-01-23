#include <vector>
using namespace std;

// 采用阵地攻守的思想
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }

        int count = 0;
        int num = numbers[0];
        // 阵地攻守
        for (int i = 0; i < numbers.size(); ++i) {
            if (num == numbers[i]) {
                ++count;
            } else {
                --count;
            }
            // 所有士兵已经阵亡
            if (count == 0) {
                num = numbers[i]; // 重新设置镇守阵地的士兵
                count = 1;
            }
        }

        return checkMoerThanHalf(numbers, num) ? num : 0;
    }

private:
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> numbers, int number) {
        int count = 0;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > numbers.size() / 2 ? true : false;
    }
};