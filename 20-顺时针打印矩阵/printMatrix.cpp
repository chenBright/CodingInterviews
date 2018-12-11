#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom) {
            // 从左到右打印
            for (int i = left; i <= right; ++i) {
                print2Vector(result, matrix[top][i]);
            }

            // 从上到下打印（这里的第一个元素已打印，则不需要打印了，从第二个开始）
            for (int i = top + 1; i <= bottom; ++i) {
                print2Vector(result, matrix[i][right]);
            }

            // top = bottom时，表示只剩一行，则不需要打印，因为第一步已打印
            if (top < bottom) {
                // 从右到左打印
                for (int i = right - 1; i >= left; --i) {
                    print2Vector(result, matrix[bottom][i]);
                }
            }

            // 同上
            if (left < right) {
                // 从上到上打印
                for (int i = bottom - 1; i >= top + 1; --i) {
                    print2Vector(result, matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }

        return result;
    }

private:
    void print2Vector(vector<int> &v, int item) {
        v.push_back(item);
    }
};