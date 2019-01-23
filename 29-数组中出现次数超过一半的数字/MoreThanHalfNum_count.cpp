#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            if (count(numbers.begin(), numbers.end(), numbers[i]) > numbers.size() / 2) {
                return numbers[i];
            }
        }

        return 0;
    }
};