#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

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