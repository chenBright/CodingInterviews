#include <iostream>

#define SET_SYMBOL_BIT(num)  ((num) |= (1 << 31))		// 设置符号位为1
#define GET_ORIGIN_NUM(num)  ((num) & (~(1 << 31)))		// 获取到源数据
#define GET_SYMBOL_BIT(num)  (((num) >> 31) & 1)		// 获取符号位(标识)

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
            // 当前数字numbers[i]的标识即是numbers[numbers[i]]的符号位
            // 检查numbers[i]
            if (GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) == 1) {
                *duplication = GET_ORIGIN_NUM(numbers[i]);
                return true;
            } else {
                SET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]);
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