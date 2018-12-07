# 19-二叉树的镜像

## 题目

牛客OJ：[19-二叉树的镜像](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P125`

## 思路

该问题本质上就是二叉树遍历问题。二叉树遍历有递归实现和非递归实现（循环）。但中序遍历中，有一点需要注意的问题，不然得不到正确的答案。

## 先序遍历

### 递归

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        TreeNode *tempNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tempNode;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```

### 循环

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        stack<TreeNode *> nodeStack;   
        TreeNode *node = pRoot;     

        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                // 交换
                TreeNode *tempNode = node->left;
                node->left = node->right;
                node->right = tempNode;

                nodeStack.push(node);
                node= node->left; 
            } else { // 处理跟结点和右子树
                node = nodeStack.top();
                nodeStack.pop();

                node = node->right;
            }
        }
    }
};
```

## 中序遍历

中序遍历的过程是，遍历的顺序为：左子树 -> 根结点 -> 右子树。**但在这个问题中，处理完根结点之后，左子树和右子树调换了位置，所以我们要处理现在的左子树，即原来的右子树。**

### 递归

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        Mirror(pRoot->left);

        TreeNode *tempNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tempNode;

        // 中序遍历处理根后，遍历右子树
        // 此时由于左右子树交换，原来的右子树是现在的左子树，所以遍历现在的左子树（）原右子树
        Mirror(pRoot->left);
    }
};
```

## 循环

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        stack<TreeNode *> nodeStack;   
        TreeNode *node = pRoot;     

        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                nodeStack.push(node);
                node= node->left; 
            } else { // 处理跟结点和右子树
                node = nodeStack.top();
                // 交换
                TreeNode *tempNode = node->left;
                node->left = node->right;
                node->right = tempNode;
                
                nodeStack.pop();

                // 中序遍历处理根后，向右转向 node = node->right
                // 此时由于左右子树交换，原来的右子树是现在的左子树，所以向左转向
                node = node->left;
            }
        }
    }
};
```

## 后序遍历

### 递归

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        TreeNode *tempNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tempNode;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```

### 循环

```c++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        stack<TreeNode *> nodeStack;   
        TreeNode *node = pRoot;   
        TreeNode *lastNode = NULL; // 上一个处理过的结点

        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                nodeStack.push(node);
                node= node->left; 
            } else { // 处理右子树
                node = nodeStack.top();
                if (node->right != NULL && node->right != lastNode) { // 右子树不为空且没有处理
                    node = node->right;
                } else { // 处理根结点
                    TreeNode *tempNode = node->left;
                    node->left = node->right;
                    node->right = tempNode;


                    lastNode = node; // 标记
                    node = NULL; // 该树已处理完，将node设为NULL，则下一循环会处理栈中的结点
                    nodeStack.pop();
                }
            }
        }
    }
};
```

