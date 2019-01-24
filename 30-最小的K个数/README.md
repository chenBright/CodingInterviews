# 30-最小的K个数

## 题目

牛客OJ：[30-最小的K个数](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P167`

## 排序

### 对所有元素排序

先排序，然后找出前k小的数字即可。

该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        sort(input.begin(), input.end()); // 排序
        res.assign(input.begin(), input.begin() + k); // 复制

        return res;
    }
};
```

题目只需要前k小的数字，所以不需要对所有元素进行排序。有一些排序算法每一次循环可以确定一个”最值“，可以让排序算法的外循环运行k次即可。

### 选择排序

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        for (int i = 0; i < k; ++i) {
            int min = i;
            for (int j = i + 1; j < input.size(); ++j) {
                if (input[j] < input[min]) {
                    min = j;
                }
            }
            if (min != i) {
                swap(&input[i], &input[min]);
            }
            res.push_back(input[i]);
        }

        return res;
    }

private:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};
```

### 冒泡排序

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = input.size() - 1; j > i; --j) {
                if (input[j] < input[j - 1]) {
                    swap(&input[j], &input[j - 1]);
                }
            }
            res.push_back(input[i]);
        }

        return res;
    }

private:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};
```

以上两个排序算法的实现的时间复杂度为**O(nk)**。

## 基于Partition函数的查找第K小的数

使用快排中的Partition函数修改数组，使得第k个数字左边的数字都比第k个数字小，右边的数字都比第k个数字小，则第k个数字机器左边的数字即为所求。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k >= input.size()) {
            return input;
        }

        findKth(input, 0, input.size() - 1, k - 1);
        res.assign(input.begin(), input.begin() + k);

        return res;
    }

private:
    // 在数组中找索引为k的元素
    void findKth(vector<int> &input, int low, int high, int k) {
        int index = Partition(input, low, high);

        if (index == k) {
            return;
        } else if (index < k) {
            findKth(input, index + 1, high, k);
        } else {
            findKth(input, low, index - 1, k);
        }
    }
    int Partition(vector<int> &input, int low, int high) {
        int i = low, j = high;
        int pivotNum = input[low]; // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不大于基准元素的元素
            while (i < j && input[j] > pivotNum) {
                --j;
            }
            input[i] = input[j];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (i < j && input[i] <= pivotNum) {
                ++i;
            }
            input[j] = input[i];
        }
        input[i] = pivotNum;
        return i; // 最后的位置 i == j 就是基准元素的最终位置
    }
};
```

## 小堆

利用所有元素构建一个小堆，然后取堆中的前k个数。

该方法的时间复杂度为***O(n+k*logn)**。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        make_heap(input.begin(), input.end(), greater<int>()); // 构造最小堆

        for (int i = 0; i < k; ++i) {
            res.push_back(input[0]);

            pop_heap(input.begin(), input.end(), greater<int>());
            input.pop_back();
        }

        return res;
    }
};
```

## 优先队列

在c++中优先队列是用堆现实的，所以**小堆**的思路一样。当然，时间复杂度也是***O(n+k*logn)**。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        priority_queue<int, vector<int>, greater<int> > pq(input.begin(), input.end()); // 构造最小值优先队列


        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
```

## 红黑树

对于前面**小堆**的方法，没有必要构建容量为n的堆，只需要构建一个容量为k的大堆。使用剩下的n-k个元素与堆顶元素比较：

- 如果元素比堆顶元素小，则删除堆顶元素，然后插入该元素。
- 否则，不更新大堆。

该方法的时间复杂度为**O(k+(n-k)*logk) = O(nlogk)**。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        } else if (k == input.size()) {
            return input;
        }

        multiset<int, greater<int> > leastSet;
        multiset<int, greater<int> >::iterator leastIter;

        for (vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
            if (leastSet.size() < k) { // 构造含有k个元素红黑树
                leastSet.insert(*it);
            } else {
                leastIter = leastSet.begin();
                // 如果元素比堆顶元素小，则删除堆顶元素，然后插入该元素
                if (*it < *leastIter) {
                    leastSet.erase(leastIter);
                    leastSet.insert(*it);
                }
            }
        }

        res.assign(leastSet.begin(), leastSet.end());

        return res;
    }
};
```

