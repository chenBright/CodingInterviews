# 18-树的子结构

## 题目

牛客OJ：[18-树的子结构](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P117`

## 思路

要查找树A中是否存在和树B结构一样的子树，可以分成两步：

1. 在A树种找到与B树根结点值相等的结点R。这一步只要递归查找A树即可，如果找到，则转到**步骤2**。步骤2的结果为true，则直接返回true；如果为false，则继续**步骤1**，直到查找完遍历完A树。如果还没找到，则直接返回false。
2. 判断树A中以R为根结点的子树是不是包含和树B一样的结构。制一部只要递归判断两棵树对应的节点数据是否相同即可。递归的终结是如果之前的节点均相同，最后子树为空时，而父树如果也是NULL，则说明两颗树完全一样，如果父树不是NULL，则子树是父树的一部分。

## 实现

```c++

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL) {
            return false;
        }

        bool result = false;
        // 两棵树的根结点的值相等，则开始比对两棵树的子树
        if (pRoot1->val == pRoot2->val) {
            result = DoesParentHaveChild(pRoot1, pRoot2);
        } 
        if (result) {
            return true;
        } else {
            // 递归查找左右子树
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }


    }

private:
    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child) {
        if (child == NULL) { // 子树为NULL，则必然是子结构
            return true;
        }
        if (parent == NULL) { // 子树不是NULL, 但是父亲树是NULL，则不是子结构
            return false;
        }

        if (parent->val != child->val) {
            return false;
        }

        return DoesParentHaveChild(parent->left, child->left) && DoesParentHaveChild(parent->right, child->right);
    }
};
```

