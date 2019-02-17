# 65-滑动窗口的最大值

## 题目

牛客OJ：[65-滑动窗口的最大值](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路
参看[github](https://github.com/gatieme/CodingInterviews/blob/6dbdd4339abc8a1283654f6449b59e945cebc346/065-%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/README.md)。

## 暴力破解

```c++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;

        if (num.empty() || size == 0) {
            return res;
        }

        int length = num.size();

        for (int i = 0; i <= (int) (length - size); ++i) {
            int max = num[i]; // i + 0
            for (int j = 1; j < size && i + j < length; ++j) {
                int index = i + j;
                if (num[index] > max) {
                    max = num[index];
                }
            }
            res.push_back(max);
        }

        return res;
    }
};
```

## 最大堆

```c++
class Solution {
    typedef pair<int, int> Pair;

public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        priority_queue<Pair> Q;

        if (num.empty() || size == 0) {
            return res;
        }

        int length = num.size();

        for (int i = 0; i < size - 1; ++i) {
            Q.push(Pair(num[i], i));
        }

        for (int j = size - 1; j < length; ++j) {
            Q.push(Pair(num[j], j));
            Pair p = Q.top();
            // 如果最大堆的堆顶元素不在窗口内，将其弹出，重新去堆顶元素
            while (p.second < j - (size - 1)) {
                Q.pop();
                p = Q.top();
            }
            res.push_back(p.first);
        }

        return res;
    }
};
```

## 单调队列

```c++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int>     res;
        deque<int>      index;
        for(unsigned int i = 0; i < num.size( ); i++) {

            /** 从后面依次弹出队列中比当前num值小的元素，
             *  同时也能保证队列首元素为当前窗口最大值下标  
             */
            while(index.size( ) != 0 && num[index.back( )] <= num[i])
            {
                index.pop_back( );
            }
            /** 当前窗口移出队首元素所在的位置
             *  即队首元素坐标对应的num不在窗口中，需要弹出  
             */
            while(index.size() && i - index.front( ) + 1 > size){
                index.pop_front( );
            }

            // 把每次滑动的num下标加入队列
            index.push_back(i);

            // 当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            if(size != 0 && i + 1 >= size) {
                res.push_back(num[index.front()]);
            }
        }

        return res;
    }
};
```

