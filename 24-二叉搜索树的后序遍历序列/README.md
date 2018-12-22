# 24-二叉搜索树的后序遍历序列

## 题目

牛客OJ：[24-二叉搜索树的后序遍历序列](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P140`

## 分析

二叉搜索树的合法后序遍历序列：

1. 最后一个元素为二叉搜索树的根结点。
2. 假设去掉最后一个元素x的序列为T，则以根结点（被去掉的元素x）将T划分为两个子序列，前一个序列（左子树）所有元素都小于x，后一个序列（右子树）的所有元素都大于x。
3. 两个子序列都是合法后序遍历序列。

上面的定义是一个递归的定义，用递归的方法很容易解决这道题。

```c++
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
```

