#include <vector>

using namespace std;

// 使用二分查找的思想查找
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int cols = array.size();
        int rows = array[0].size();
        isFind = Find(target, array, 0, rows - 1, 0, cols - 1);

        return isFind;
    }
private:
    bool Find(int target, vector<vector<int> > array, int lowRow, int highRow, int lowCol, int highCol) {
        if (lowCol > highCol || lowRow > highRow) {
            return false;
        }

        int i = lowRow + (highRow - lowRow) / 2;
        int j = lowCol + (highCol - lowCol) / 2;
        if (array[i][j] == target) {
            return true;
        } else if (array[i][j] > target) {
            return Find(target, array, lowRow, highRow, lowCol, j - 1) || Find(target, array, lowRow, i - 1, j, highCol);
        } else {
            return Find(target, array, lowRow, highRow, j + 1, highRow) || Find(target, array, i + 1, highRow, lowCol, j);
        }
    }
};