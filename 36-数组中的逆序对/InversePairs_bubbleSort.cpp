#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        bool flag = false; // 数组是都有序
        for (int i = 0; i < data.size() && !flag; ++i) {
            flag = true;
            for (int j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    ++count;

                    flag = false;
                    swap(data[j], data[j + 1]);
                }
            }
        }

        return count;
    }
};