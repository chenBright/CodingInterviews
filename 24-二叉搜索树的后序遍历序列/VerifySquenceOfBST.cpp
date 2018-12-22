#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if (len == 0) {
            return false;
        }

        return isPostOrder(sequence, 0, len - 1);
    }

private:
    bool isPostOrder(vector<int> sequence, int low, int high) {
        if (low == high) {
            return true;
        }

        int root = sequence[high];
        int mid = low;

        // 找到第一个大于root的元素，并确定前面的元素是二叉搜索树的左子树
        while (mid < high && root > sequence[mid++]); 

        for (int i = mid; i < high; ++i) {
            // 如果右子树中存在小于root的结点，则不是二叉搜索树
            if (sequence[i] < root) { 
                return false;
            }
        }

        bool left = true;
        // 如果左子树存在，则递归检查左子树
        if (mid > low) {
            left = isPostOrder(sequence, low, mid - 1);
        }

        bool right = true;
        // 如果右子树存在，则递归检查右子树
        if (high > mid) {
            right = isPostOrder(sequence, mid, high - 1);
        }

        return left && right;
    }
};