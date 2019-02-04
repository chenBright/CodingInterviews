#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        int arrayLength = array.size();
        for (int i = 0; i < arrayLength - 1; ++i) {
            bool isExit = false;
            for (int j = i + 1; j < arrayLength; ++j) {
                if (array[i] + array[j] == sum) {
                    numbers.push_back(array[i]);
                    numbers.push_back(array[j]);
                    isExit = true;
                    break;
                }
            }
            if (isExit) {
                break;
            }
        }

        return numbers;
    }
};