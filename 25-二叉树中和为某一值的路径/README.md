# 25-二叉树中和为某一值的路径

## 题目


牛客OJ：[25-二叉树中和为某一值的路径](https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P143`

## 分析

该问题可以看成是一个二叉树前序遍历的问题，访问结点时：

1. 结点为叶子结点，从根结点到该结点的和等于expectNumber，符合要求。
2. 结点不是叶子结点且和小于expectNumber，expectNumber减结点的值，将该结点添加到数组中，然后继续往下递归遍历。
3. 其他情况都不符合要求，不再递归遍历。

我这里用的是**减的方法**，最后遍历完叶子结点，看是否为0。当然，也可以用**加的方法**，最后看和是否等于expectNumber。

## 实现

```c++
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        v.clear();
        if (root == NULL || expectNumber == 0) {
            return v;
        }

        vector<int> nodes;
        FindPath(root, expectNumber, nodes);
        return v;
    }

private:
    vector<vector<int> > v;
    void FindPath(TreeNode *node, int expectNumber, vector<int> nodes) {
        // 结点为叶子结点，从根结点到该结点的和等于expectNumber，符合要求
        if (node->val == expectNumber || (node->left == NULL && node->right == NULL)) { 
            nodes.push_back(node->val);
            v.push_back(nodes);
        } else if (node->val < expectNumber) { // 不是叶子结点且和小于expectNumber，继续往下递归遍历
            nodes.push_back(node->val);
            expectNumber -= node->val; // 减
            if (node->left !=  NULL) {
                FindPath(node->left, expectNumber, nodes);
            }
            if (node->right != NULL) {
                FindPath(node->right, expectNumber, nodes);
            }
        }

    }
};
```



