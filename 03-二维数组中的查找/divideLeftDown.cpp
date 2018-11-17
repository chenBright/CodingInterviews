#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int rows = array.size();
        int cols = array[0].size();
        
        /**
         * 从左下角开始查找
         * 如果查找的元素比当前位置的元素小，则向上查找
         * 如果查找的元素比当前位置的元素大，则向右查找
         */
        int curRow = rows - 1;
        int curCol = 0;
        while ((curRow >= 0 && curRow < rows) && (curCol >= 0 && curCol < cols)) {
            if(array[curRow][curCol] == target) {
                isFind = true;
                break;
            } else if (array[curRow][curCol] > target) {
                --curRow;
            } else {
                ++curCol;
            }
        }

        return isFind;
    }
};