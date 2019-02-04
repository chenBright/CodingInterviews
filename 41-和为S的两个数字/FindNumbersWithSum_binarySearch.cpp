#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        for (int i = 0; i < array.size() - 1; ++i) {
            int another = sum - array[i];
            bool isExit = binary_search(array.begin(), array.end(), another);
            if (isExit) {
                numbers.push_back(array[i]);
                numbers.push_back(another);
                break;
            }
        }

        return numbers;
    }
};