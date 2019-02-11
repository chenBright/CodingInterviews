#include <algorithm>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if (!CheckValidity(numbers, length)) {
            return false;
        }

        for (int i = 0; i < length; ++i) {
            // 极端情况按顺序排序, 第i个位置上的数numbers[i]应该等于其下标i
            while (numbers[i] != i) {
                // 第numbers[i]位置上的数据numbers[numbers[i]应该是numbers[i]
                // 即数numbers[i]应该是数组第numbers[i]个数numbers[numbers[i]
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                } else {
                    swap(numbers[i], numbers[numbers[i]]);
                }
            }
        }

        return false;
    }

private:
    // 检查数据的合法性
    bool CheckValidity(int *number, int length) {
        if (number == NULL && length <= 0) {
            return false;
        }

        for (int i = 0; i < length; ++i) {
            if (*number < 0 || *number > length - 1) {
                return false;
            }
        }

        return true;
    }
};