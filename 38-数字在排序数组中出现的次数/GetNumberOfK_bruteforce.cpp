#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int dataLength = data.size();
        if (dataLength == 0) {
            return 0;
        }

        int i;
        for (i = 0; i < dataLength && data[i] != k; ++i); // 找到第一个等于k的元素

        int j;
        for (j = i; j < dataLength && data[j] == k; ++j); // 找到第一个右边第一个不等于k的元素

        return j - i;
    }
};