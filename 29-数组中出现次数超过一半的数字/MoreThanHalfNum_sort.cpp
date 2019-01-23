#include <vector>
#include <algorithm>
using namespace std;

// 先排序再统计个数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        } else if (numbers.size() == 1) {
            return numbers[0];
        }

        sort(numbers.begin(), numbers.end());

        int num = numbers[0];
        int count = 1;
        for (vector<int>::iterator it = numbers.begin() + 1; it != numbers.end(); ++it) {
            if (num == *it) {
                ++count;

                if (count > numbers.size() / 2) {
                    return num;
                }
            } else {
                count = 1;
                num = *it;
            }
        }

        return 0;
    }
};