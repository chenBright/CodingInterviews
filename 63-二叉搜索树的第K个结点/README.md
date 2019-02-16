# 63-二叉搜索树的第K个结点

## 题目

牛客OJ：[63-二叉搜索树的第K个结点](https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路

二叉搜索树的中序遍历是递增的序列，中序遍历的第k个结点就是二叉搜索树的第k小节点。

## 中序遍历 递归实现

```c++
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL) {
            return NULL;
        }

        TreeNode *res = NULL;
        if ((res = KthNode(pRoot->left, k)) != NULL) {
            return res;
        }

        if (count == k) {
            return pRoot;
        }
        ++count;

        if ((res = KthNode(pRoot->right, k)) != NULL) {
            return res;
        }

        return NULL;
    }

private:
    unsigned int count = 1;
};
```

## 中序遍历 非递归实现

```c++
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k <= 0) {
            return NULL;
        }

        stack<TreeNode*> nodeStack;
        nodeStack.push(pRoot);
        unsigned int count = 1;
        TreeNode *node = pRoot;

        while (!nodeStack.empty() || node != NULL) {
            if (node->left != NULL) {
                nodeStack.push(node->left);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                if (count == k) {
                    return node;
                }
                ++count;

                node = node->right;
            }
        }

        return NULL;
    }
};
```

