# 51-数组中重复的数字

## 题目

牛客OJ：[51-数组中重复的数字](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 先排序再判断重复

排序的时间复杂度为***O(nlogn)***，遍历判断重复的时间复杂度为***O(n)***，所以该方法的时间复杂度为***O(nlogn)***。

```c++
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication) {
        *duplication = -1;
        if (!CheckValidity(numbers, length)) {
            return false;
        }

        sort(numbers, numbers + length);
        
        for (int i = 0; i < length - 1; ++i) {
            if (numbers[i] == numbers[i + 1]) {
                *duplication = numbers[i];
                return true;
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
```

## 使用哈希表记录数字的出现

使用哈希表记录数字的出现：

1. 如果数字已记录在哈希表中，则该数字为重复出现的数字。
2. 如果哈希表没有该数字，则插入该数字。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(n)***。

```c++
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

        unordered_map<int, int> hashmap;
        for (int i = 0; i < length; ++i) {
            if (hashmap.count(numbers[i])) {
                *duplication = numbers[i];
                return true;
            } else {
                hashmap.insert(make_pair(numbers[i], 1));
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
```

## 标识数组

可以使用数组代替哈希表。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(n)***。

```c++
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

        int flags[length];
        memset(flags, 0, sizeof(flags));
        for (int i = 0; i < length; ++i) {
            int number = numbers[i];
            if (flags[number] != 0) {
                *duplication = number;
                return true;
            } else {
                ++flags[number];
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
```

## 符号位标识

参考[github](https://github.com/gatieme/CodingInterviews/blob/6dbdd4339abc8a1283654f6449b59e945cebc346/051-%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97/README.md#%E7%AC%A6%E5%8F%B7%E4%BD%8D%E6%A0%87%E8%AF%86%E6%B3%95)。

该方法的时间复杂度为***O(n)***。

```c++
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
```

## 将元素放在自己该在的位置

如果每个数字都置出现一次，每一个下标i对应元素numbers[i]，也就是说对于数组中的每个元素numbers[i]都把它放在自己应该在的位置上numbers[numbers[i]]上, 如果我们发现有两个元素想往同一个位置上放的时候，说明此元素必然重复。

即如下的过程：

1. 如果numbers[i] == i, 那么可以认为number[i]这个元素已在自己的位置上。
2. 否则, numbers[i]这个元素就应该在numbers[numbers[i]]这个位置上, 于是交换numbers[i]和numbers[numbers[i]]的位置。
3. 重复操作1, 直到number[i]== i, 则继续操作下一个位置的元素, 或者numbers[i] == numbers[numbers[i]，元素重复。

该方法的时间复杂度为***O(n)***。

```c++
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
```



