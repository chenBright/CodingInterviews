#include <vector>
using namespace std;

/**
 * 维护两个索引或者指针，一个指向数组的第一个元素，并向后移动，一个指向数组的最后一个元素，并向前移动。
 * 如果第一个指针指向的元素是偶数，而第二个指针指向的元素是奇数，说明偶数在奇数前面，那么就交换这两个数。
 * 直到两个指针相遇为止 
 * 但不能保证相同类型数据的相对位置不变，因此不稳定
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1) {
            return;
        }

        vector<int>::iterator left = array.begin();
        vector<int>::iterator right = array.end() - 1;

        while (left < right) {
            // left向后移动指向第一个偶数
            while (left < right && *left % 2 == 1) {
                ++left;
            }
            // right向前移动指向第一个奇数
            while (left < right && *right % 2 == 0) {
                --right;
            }

            if (left < right) {
                swap(left, right);
            }
        }        
    }

private:
    // 交换数组元素
    void swap(vector<int>::iterator i, vector<int>::iterator j) {
        int temp = *i;
        *i = *j;
        *j = temp;
    }
};