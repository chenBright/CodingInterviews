# 39-二叉树的深度

## 题目

牛客OJ：[39-二叉树的深度](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2)


《剑指offer》：`P207`

## 递归

```c++
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == NULL) {
            return 0;
        }

        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};
```