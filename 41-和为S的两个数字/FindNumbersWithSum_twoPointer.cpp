#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        int arrayLength = array.size();
        for (int i = 0, j = arrayLength - 1; i < j;) {
            int small = array[i];
            int big = array[j];
            if (small + big == sum) {
                numbers.push_back(small);
                numbers.push_back(big);
                break;
            } else if (small + big < sum) {
                ++i;
            } else {
                --j;
            }
        }

        return numbers;
    }
};