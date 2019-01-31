# 36-数组中的逆序对

## 题目

牛客OJ：[36-数组中的逆序对](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P189`

## 暴力破解

该方法的时间复杂度为**O(n^2)**。

```c++
class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        for (int i = 0; i < data.size() - 1; ++i) {
            for (int j =   i + 1; j < data.size(); ++j) {
                if (data[i] > data[j]) {
                    ++count;
                }
            }
        }

        return count;
    }
};
```

## 冒泡排序

逆序是说a[i]>a[j]，i<j。那么在排序的过程中，会把a[i]和a[j]交换过来，这个交换的过程，每交换一次，就是一个逆序对的“正序”过程。

该方法的时间复杂度为**O(n^2)**。

```c++
class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        bool flag = false; // 数组是都有序
        for (int i = 0; i < data.size() && !flag; ++i) {
            flag = true;
            for (int j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    ++count;

                    flag = false;
                    swap(data[j], data[j + 1]);
                }
            }
        }

        return count;
    }
};
```

## 归并排序

该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) {
            return 0;
        }

        vector<int> temp(data.size());
        // 牛客网上的题目要求，结果对1000000007取模
        return mergeSort(data, 0 , data.size() - 1, temp) % 1000000007;
    }

private:
    // 归并排序
    // temp使用引用，因为当测试用例很大的时候，每次递归都创建局部temp，都占用非常多内存
    long long mergeSort(vector<int> &data, int low, int high, vector<int> &temp) {
        long long count = 0; 
        if (low >= high) {
            return count;
        }

        int mid = (low + high) / 2;
        count += mergeSort(data, low, mid, temp);
        count += mergeSort(data, mid + 1, high, temp);

        int left = low;
        int right = mid + 1;
        int tempIndex = low;
        while (left <= mid && right <= high) {
            if (data[left] > data[right]) { // 左半边所有元素都与当前右半边元素构成逆序对
                count += mid - left + 1;
                temp[tempIndex++] = data[right++]; // 将小的那一个放入到临时数组中去
            } else { // 不构成逆序对
                temp[tempIndex++] = data[left++]; // 将小的那一个放入到临时数组中去
            }
        }

        while (left <= mid) {  // 左半边数组中还有元素未放入临时数组
            temp[tempIndex++] = data[left++];
        }
        while (right <= high) { // 右半边数组中还有元素未放入临时数组
            temp[tempIndex++] = data[right++];
        }

        for (int i = low; i <= high; ++i) {
            data[i] = temp[i];
        }

        return count;
    }
};
```

