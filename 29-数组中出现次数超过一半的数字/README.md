# 29-数组中出现次数超过一半的数字

## 题目

牛客OJ：[29-数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P163`

## 排序后统计个数

将数组排好序，则统计就会很好完成。排序的时间复杂度为**O(nlogn)**，统计的时间复杂度为**O(n)**，所以该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        } else if (numbers.size() == 1) {
            return numbers[0];
        }

        sort(numbers.begin(), numbers.end());

        int num = numbers[0];
        int count = 1;
        for (vector<int>::iterator it = numbers.begin() + 1; it != numbers.end(); ++it) {
            if (num == *it) {
                ++count;

                if (count > numbers.size() / 2) {
                    return num;
                }
            } else {
                count = 1;
                num = *it;
            }
        }

        return 0;
    }
};
```

## 使用map统计个数

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> numMap;

        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (numMap.count(*it)) {
                ++numMap[*it];
            } else {
                numMap[*it] = 1;
            }
        }

        for (map<int, int>::iterator it = numMap.begin(); it != numMap.end(); ++it) {
            if (it->second > numbers.size() / 2) {
                return it->first;
            }
        }

        return 0;
    }
};
```

## 基于Partition函数的O(n)的查找第K大的数

数组中有一个数字出现的次数超过了数组长度的一半，那么**如果我们把这个数组排序，那么排序之后位于数组中间的那个数字一定就是那个出现次数超过数组长度一半的数字**。即这个数是中位数，则现在问题变成查找第k大的元素。**快速排序算法**的Partition函数每次都可以确定基准元素的最终位置，则我们可以用快排的思想来找中位数。

最后，还要检查这个中位数的个数是否超过数组元素个数的一半。

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return numbers[0];
        }

        int n = findKth(numbers, 0, len - 1, len / 2);
        if (checkMoerThanHalf(numbers, n)) {
            return n;
        }

        return 0;
    }

private:
    // 在数组中找索引为k的元素
    int findKth(vector<int> &numbers, int low, int high, int k) {
        int index = Partition(numbers, low, high);

        if (index == k) {
            return numbers[k];
        } else if (index < k) {
            return findKth(numbers, index + 1, high, k);
        } else {
            return findKth(numbers, low, index - 1, k);
        }
    }
    int Partition(vector<int> &numbers, int low, int high) {
        int i = low, j = high;
        int pivotNum = numbers[low]; // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不大于基准元素的元素
            while (i < j && numbers[j--] > pivotNum);
            numbers[i] = numbers[j];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (i < j && numbers[i++] <= pivotNum);
            numbers[j] = numbers[i];
        }
        numbers[i] = pivotNum;
        return i; // 最后的位置 i == j 就是基准元素的最终位置
    }
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> numbers, int number) {
        int count = 0;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > numbers.size() / 2 ? true : false;
    }
};
```

## 基于分治的两两比较方法

该方法来自于屈婉玲老师的[《算法设计与分析》](https://book.douban.com/subject/6434299/)。先假设存在一个数字**n**出现次数多余一半：

1. 将数组数字两两分成一组。如果两者相等，则只舍去其中一个数字；如果不等，两者都舍去。（如果数组元素个数为奇数，则最后一个元素在下一轮才比较）
2. 由第一步得到新的数组（新数组中，数字**n**出现次数也超过一半），重复执行第一步，直到数组元素个数不大于3位置。
3. 由前两步得到一个数字，还需要验证该数字出现次数是否超过一半。

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        } else if (numbers.size() == 1) {
            return numbers[0];
        }

        int num = compare(numbers);
        return checkMoerThanHalf(numbers, num) ? num : 0;
    }

private:
    // 将数组数字两两分成一组。如果两者相等，则只舍去其中一个数字；如果不等，两者都舍去。
    // 得到新的数组后，循环执行上述步骤，直到数组元素个数不大于3位置
    int compare(vector<int> numbers) {
        int len = numbers.size();
        vector<int> temp;
        while (len > 3) {
            for (int i = 0; i <= len / 2 - 1; ++i) {
                if (numbers[i] == numbers[len / 2]) {
                    temp.push_back(numbers[i]);
                }
            }
            if (len % 2 == 1) {
                temp.push_back(numbers[len - 1]);
            }

            numbers.clear();
            numbers.swap(temp);
            len = numbers.size();
        }
        
        if (len == 1) {
            return numbers[0];
        } else if (len == 2) {
            if (numbers[0] == numbers[1]) {
                return numbers[0];
            } else {
                return 0;
            }
        } else if (len == 3) {
            if (numbers[0] == numbers[1] || numbers[0] == numbers[2]) {
                return numbers[0];
            } else if (numbers[1] == numbers[2]) {
                return numbers[1];
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> numbers, int number) {
        int count = 0;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > numbers.size() / 2 ? true : false;
    }
};
```



## 使用STL的count函数统计某个值出现的次数

```c++
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            if (count(numbers.begin(), numbers.end(), numbers[i]) > numbers.size() / 2) {
                return numbers[i];
            }
        }

        return 0;
    }
};
```

