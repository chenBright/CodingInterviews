# 41-和为S的两个数字

## 题目

牛客OJ：[41-和为S的两个数字](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2)


《剑指offer》：`P214`

## 暴力破解
暴力破解方法的时间复杂度为**O(n^2)**。

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        int arrayLength = array.size();
        for (int i = 0; i < arrayLength - 1; ++i) {
            bool isExit = false;
            for (int j = i + 1; j < arrayLength; ++j) {
                if (array[i] + array[j] == sum) {
                    numbers.push_back(array[i]);
                    numbers.push_back(array[j]);
                    isExit = true;
                    break;
                }
            }
            if (isExit) {
                break;
            }
        }

        return numbers;
    }
};
```

## 二分查找

1. 确定一个数字a。
2. b = sum - a，使用二分查找在剩下的数字中查找b。

该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        for (int i = 0; i < array.size() - 1; ++i) {
            int another = sum - array[i];
            bool isExit = binary_search(array.begin(), array.end(), another);
            if (isExit) {
                numbers.push_back(array[i]);
                numbers.push_back(another);
                break;
            }
        }

        return numbers;
    }
};
```

## 两个指针双向遍历

使用两个指针small、big，small指向数组头，big指向数组尾。因为数组是递增的，所以根据两指针指向指向的元素的和与sum比较结果，决定两指针的移动：

1. 如果*small + *big大于sum，则向前移动big指针。
2. 如果*small + *big小于sum，则向后移动small指针。
3. 如果*small + *big等于sum，则结束遍历。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> numbers;
        int arrayLength = array.size();
        for (int i = 0, j = arrayLength - 1; i < j;) {
            int small = array[i];
            int big = array[j];
            if (small + big == sum) {
                numbers.push_back(small);
                numbers.push_back(big);
                break;
            } else if (small + big < sum) {
                ++i;
            } else {
                --j;
            }
        }

        return numbers;
    }
};
```

