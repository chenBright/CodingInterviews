#include <vector>
#include <map>
using namespace std;

// 使用map记录数字出现的个数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> numMap;

        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (numMap.count(*it)) {
                ++numMap[*it];
            } else {
                numMap[*it] = 1;
            }
        }

        for (map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it) {
            if (it->second > numbers.size() / 2) {
                return it->first;
            }
        }

        return 0;
    }
};