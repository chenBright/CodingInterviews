# 64-数据流之中的中位数

## 题目

牛客OJ：[64-数据流之中的中位数](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路

对于排好序的数组，很容易找到中位数，直接是最中间的一个数（奇数个元素时）或者两个数的平均数（偶数个元素时）。

将所有数平均分成两部分，前半部分用最大堆维护，后半部分用最小堆维护。因为数据是动态增长的，还需要维护两个堆的元素个数最大相差1（假设相差1时，最大堆比最小堆多1个元素）。

- 当元素个数为奇数时，中位数为最大堆的堆顶元素。

- 当元素个数为偶数时，中位数为最大堆和最小堆的堆顶元素的平均数。

## 堆排序

```c++
class Solution {
private:
    vector<int> m_min; // 数组中的后一半元素组成一个最小化堆
    vector<int> m_max; // 数组中的前一半元素组成一个最大化堆

public:
    /** 将元素插入的堆中，　
     *  为了保证数据平均的分配到两个堆中, 两个堆的数据数目之差不能超过１
     *  插入的元素会两个堆元素的平衡, 因此两个堆都必须调整
     *
     *  比如将元素插在后半段(最小堆)中,
     *  则最小堆调整后的堆顶(最小值)需要弹出并压入到前半段中才能保证平衡
     *　也就是说,　在最小堆中插入元素, 最后完成调整后将导致最大堆中元素+1
     *
     *  因此我们可以假定, 0 <= m_min.size( ) - m_max.size( ) <= 1
     *  那么
     *
     * 1. 插入前如果整个数组的元素个数为偶数, 说明两个堆中元素个数相等
     *    则最终元素应该插入m_min中,即先把元素插入到m_max中，再调整到m_min中
     *
     * 2. 插入前如果整个数组的元素个数为奇数, 说明m_min元素多了1个
     *    则最终元素应该插入m_max中,
     *    即先把元素插入到m_min中，再调整到m_max中
     */
    void Insert(int num) {
        if ((m_max.size() + m_min.size()) % 2 == 0) {
            /*  偶数数据的情况下
             *  直接将新的数据插入到数组的前半段
             *  即在最大堆中插入元素
             *
             *  此时最大堆中多出一个元素,
             *  即最大元素, 将其弹出后, 压入后半段(即最小堆中)
             */
            if (!m_max.empty() && num < m_max[0]) {
                m_max.push_back(num);
                push_heap(m_max.begin(), m_max.end(), less<int>());

                num = m_max[0];
                pop_heap(m_max.begin(), m_max.end(), less<int>());
                m_max.pop_back();
            }
            m_min.push_back(num);
            push_heap(m_min.begin(), m_min.end(), greater<int>());
        } else {
            /*  否则数组中元素是奇数
             *  直接将新的数据插入到数组的后半段
             *  即在最小堆中插入元素
             *
             *  此时最小堆中多出两个元素,
             *  将最小元素弹出后, 压入前半段(即最大堆中)
             * */
            if (!m_min.empty() && num > m_min[0]) {
                m_min.push_back(num);
                push_heap(m_min.begin(), m_min.end(), greater<int>());

                num = m_min[0];
                pop_heap(m_min.begin(), m_min.end(), greater<int>());
                m_min.pop_back();
            }
            m_max.push_back(num);
            push_heap(m_max.begin(), m_max.end(), less<int>());
        }
    }

    double GetMedian() { 
        int length = m_max.size() + m_min.size();
        if (length == 0) {
            return -1;
        }

        double median = 0;
        if (length % 2 == 0) { // 总元素个数为偶数
            median = (double) (m_max[0] + m_min[0]) / 2;
        } else { // 总元素个数为奇数
            median = (double) m_min[0];
        }

        return median;
    }
};
```

## 哈希multiset

类似的策略，也可以采用multiset来实现, set和multiset会根据特定的排序准则，自动将元素进行排序。不同的是后者允许元素重复而前者不允许。

```c++
class Solution {
private:
    multiset<int> left; // 数组中的前一半元素
    multiset<int> right; // 数组中的后一半元素

public:
    void Insert(int num) {
        int temp = num;
        if ((left.size() + right.size()) % 2 == 0) {
            if (!right.empty() && num > *right.begin()) {
                right.insert(num);
                temp = *right.begin();
                right.erase(right.find(temp));
            }
            left.insert(temp);
        } else {
            if (!left.empty() && num < *left.rbegin()) {
                left.insert(num);
                temp = *left.rbegin();
                left.erase(left.find(temp));
            }
            right.insert(temp);
        }
    }

    double GetMedian() {
        int length = left.size() + right.size();
        if (length == 0) {
            return -1;
        }

        double median = 0;
        if (length % 2 == 0) { // 总元素个数为偶数
            median = (double) (*left.rbegin() + *right.begin()) / 2;
        } else { // 总元素个数为奇数
            median = (double) *left.rbegin();
        }

        return median;
    }
};
```

