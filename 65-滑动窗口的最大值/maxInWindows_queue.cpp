#include <vector>
#include <queue>
using namespace std;

/** 单调队列，O(n)
 *  deque s中存储的是num的下标
 *
 *  题目：滑动窗口的最大值
 *
 *  思路：滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
 *
 *  原则：
 *  对新来的元素k，将其从队尾开始与双端队列中的元素相比较
 *  1.  比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
 *  2.  比k大的X，比较两者下标，判断X是否已不在窗口之内，不在的话，直接移出队列
 *  这样保证队列从队头到队尾单调递减，第一个元素是滑动窗口中的最大值
 * 
 *  同时，从队头开始，判断元素是否在滑动窗口内，不在的话，直接移出队列
 *  这样，队列的第一个元素是滑动窗口中的最大值
 */
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