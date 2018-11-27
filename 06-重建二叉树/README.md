# 06-重建二叉树

## 题目

牛客OJ：[06-重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P55`

## 分析

给定二叉树前序遍历序列和中序遍历序列，可以唯一确定一颗二叉树。其中的规律为，**前序遍历序列的第一个元素为二叉树的根结点，在中序遍历序列中，根结点左边的元素为左子树的结点，右边的元素为右子树上的结点**。

算法流程：

1. 根据前序遍历序列的第一个元素确定根结点；
2. 在中序遍历序列中找到根结点元素，该元素左边的元素为左子树的中序遍历序列，右边的元素为右子树结点的中序遍历序列；
3. 假设步骤2中，左子树结点数为n，右子树结点数为m，则在前序遍历序列中，根结点元素之后n个元素为左子树的前序遍历序列，最后m个元素为右子树的前序遍历序列。
4. 构建根结点；
5. 根据得到左子树的前序遍历序列和中序遍历序列，递归构建左子树；
6. 根据右子树的的前序遍历序列和中序遍历序列，递归构建右子树。

```c++
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //  前序遍历的长度跟中序遍历的长度应该相同
        if(pre.size( ) != vin.size( )) {
            return NULL;
        }

        // 长度不能为0
        int length = pre.size( );
        if(length == 0) {
            return NULL;
        }

        // 前序遍历序列的第一个元素为书的根结点
        int val = pre[0];
        TreeNode* root = new TreeNode(val);

        // 在中序遍历序列中查找根结点
        int rootIndex = 0;
        for (; rootIndex < length; ++rootIndex) {
            if (vin[rootIndex] == val) {
                break;
            }
        }

        // 没有找到根结点
        if (rootIndex >= length) {
            return NULL;
        }

        vector<int> preLeft, preRight, vinLeft, vinRight;
        for (int i = 0; i < length; ++i) {
            if (i < rootIndex) {
                preLeft.push_back(pre[i + 1]);
                vinLeft.push_back(vin[i]);
            } else if (i > rootIndex) {
                preRight.push_back(pre[i]);
                vinRight.push_back(vin[i]);
            }
        }

        root->left = reConstructBinaryTree(preLeft, vinLeft);
        root->right = reConstructBinaryTree(preRight, vinRight);

        return root;
    }
};
```