
#include <vector>
#include <set>
#include <functional>
using namespace std;

// 构造含有k个元素红黑树，使用剩下的元素更新红黑树
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