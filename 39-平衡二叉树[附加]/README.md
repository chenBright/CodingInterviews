# 39-平衡二叉树[附加]

## 题目

牛客OJ：[39-平衡二叉树[附加]](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2)


《剑指offer》：`P209`

## 思路

判断每个结点的左右子树是不是平衡二叉树，这是一个递归的过程。

```c++
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int treeDepth = 0;
        return isBalanced(pRoot, &treeDepth);
    }

private:
    bool isBalanced(TreeNode *pRoot, int *treeDepth) {
        if (pRoot == NULL) {
            *treeDepth = 0;
            return true;
        }

        int leftTreeDepth, rightTreeDepth;
        if (isBalanced(pRoot->left, &leftTreeDepth) && isBalanced(pRoot->right, &rightTreeDepth)) {
            int diff = abs(leftTreeDepth - rightTreeDepth); // 计算左右子树深度差
            if (diff <= 1) {
                *treeDepth = max(leftTreeDepth, rightTreeDepth) + 1;
                return true;
            }
        }

        return false;
    }
};
```

