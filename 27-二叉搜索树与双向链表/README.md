# 27-二叉搜索树与双向链表

## 题目

牛客OJ：[27-二叉搜索树与双向链表](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P151`

## 中序遍历

使用中序遍历解决该问题，使用一个**lastNode**变量保存上一个访问到的结点，并与当前访问到的结点链接。

### 递归实现

```c++
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) {
            return NULL;
        }

        TreeNode *lastNode = NULL;
        ConvertRecursion(pRootOfTree, &lastNode);

        TreeNode *linkedList = lastNode;
        while (linkedList != NULL && linkedList->left != NULL) {
            linkedList = linkedList->left;
        }

        return linkedList;
    }

private:
    void ConvertRecursion(TreeNode *root, TreeNode **lastNode) {
        if (root == NULL) {
            return;
        }

        ConvertRecursion(root->left, lastNode);
        
        // 将该结点转换为链表上的结点
        root->left = *lastNode;
        if (*lastNode != NULL) {
            (*lastNode)->right = root;
        }
        // 更新 上一个访问的指针域
        *lastNode = root;

        ConvertRecursion(root->right, lastNode);
    }
};
```

### 循环实现

```c++
#include <stack>
using namespace std;

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        stack<TreeNode *> s;
		TreeNode *node = pRootOfTree;
		TreeNode *linkedList = NULL;
		TreeNode *lastNode = NULL;

		while (!s.empty() || node != NULL) {
			if (node != NULL) {
				s.push(node);
				node = node->left;
			} else {
				node = s.top();
				s.pop();

				// 将该结点转换为链表上的结点
				if (lastNode == NULL) { // 链表头结点
					linkedList = lastNode = node;
					linkedList->left = NULL;
				} else { // 其他结点
					lastNode->right = node;
					node->left = lastNode;
					lastNode = node;
				}

				node = node->right;
			}
		}

		return linkedList;
    }
};
```

## 后序遍历

也可以使用后序遍历解决该问题：

1. 将左子树转换成双向链表；
2. 将右子树转换成双向链表；
3. 链接根结点和左右子树转换的链表。

```c++
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) {
            return NULL;
        }

        TreeNode *linkedList = ConvertRecursion(pRootOfTree);
        while (linkedList != NULL && linkedList->left != NULL) {
            linkedList = linkedList->left;
        }

        return linkedList;
    }

private:
    TreeNode* ConvertRecursion(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode *leftList = ConvertRecursion(root->left);
        TreeNode *rightList = ConvertRecursion(root->right);

        // 找到左子树转换的链表的最后一个结点
        while (leftList != NULL && leftList->right != NULL) {
            leftList = leftList->right;
        }
        // 找到右子树转换的链表的第一个结点
        while (rightList != NULL && rightList->left != NULL) {
            rightList = rightList->left;
        }
        // 链接根结点和左右子树转换的链表
        root->left = leftList;
        root->right = rightList;
        if (leftList != NULL) {
            leftList->right = root;
        }
        if (rightList != NULL) {
            rightList->left = root;
        }

        return root;
    }
};
```

