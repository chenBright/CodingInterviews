#include <set>
#include <algorithm>
#include <functional>
using namespace std;

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