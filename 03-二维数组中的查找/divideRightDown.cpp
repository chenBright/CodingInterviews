#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool isFind = false;
        int rows = array.size();
        int cols = array[0].size();
        
        /**
         * 从右上角开始查找
         * 如果查找的元素比当前位置的元素小，则向左查找
         * 如果查找的元素比当前位置的元素大，则向下查找
         */
        int curRow = 0;
        int curCol = cols - 1;
        while ((curRow >= 0 && curRow < rows) && (curCol >= 0 && curCol < cols)) {
            if(target == array[curRow][curCol]) {
                isFind = true;
                break;
            } else if (target < array[curRow][curCol]) {
                --curCol;
            } else {
                ++curRow;
            }
        }

        return isFind;
    }
};