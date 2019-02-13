# 59-对称的二叉树

## 题目

牛客OJ：[59-对称的二叉树](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 代码

```c++
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == NULL) {
            return true;
        }

        return isSymmetricalRecursion(pRoot->left, pRoot->right);
    }

private:
    bool isSymmetricalRecursion(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL) { // 两个结点都为NULL
            return true;
        } else if (leftNode == NULL || rightNode == NULL) { // （结合前面的条件）只有一个结点为NULL
            return false;
        } 

        // 两个结点都不为NULL
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return isSymmetricalRecursion(leftNode->left, rightNode->right) 
            && isSymmetricalRecursion(leftNode->right, rightNode->left);
     }

};
```

