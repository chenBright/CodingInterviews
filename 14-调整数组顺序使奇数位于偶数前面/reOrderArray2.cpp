#include <vector>
using namespace std;

// 冒泡解法：每次循环前偶后奇就交换
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int length = array.size();

        if (length <= 1) {
            return;
        }
        
        bool isSwap = false;
        for (int i = 0; i < length; ++i) {
            isSwap = false;
            for (int j = length - 1; j > i; --j) {
                // 前偶后奇交换
                if (!isEven(array[j]) && isEven(array[j - 1])) {
                    swap(array, j, j - 1);
                    isSwap = true;
                }
            }
            // 没有交换过，则表示数组以满足前奇后偶的条件
            if (!isSwap) {
                break;
            }
        }
    }

private:
    // number是否是偶数
    bool isEven(int number) {
        return number % 2 == 0;
    }
    
    // 交换数组元素
    void swap(vector<int> &array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
};