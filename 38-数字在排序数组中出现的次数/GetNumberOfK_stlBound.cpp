#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        if (!data.empty()) {
            auto first = lower_bound(data.begin(), data.end(), k); // 返回一个非递减序列[first, last]中的第一个大于等于值val的指针
            auto upper = upper_bound(data.begin(),data.end(),k); // 返回一个非递减序列[first, last]中第一个大于val的指针

            count = upper - first;
        }

        return count;
    }
};