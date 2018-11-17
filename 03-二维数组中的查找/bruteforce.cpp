#include <vector>

using namespace std;

// 暴力解法，遍历每个元素
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        for (int i = 0; i < array.size(); ++i) {
            for (int j = 0; j < array[i].size(); ++j) {
                if (array[i][j] == target) {
                    isFind = true;
                }
            }
        }
        return isFind;
    }
};