# 58-二叉树的下一个结点

## 题目

牛客OJ：[58-二叉树的下一个结点](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 思路
1. 当结点有右子树时，结点的下一个结点是其右子树的最左边的结点。
2. 当结点没有右子树时：
   - 该结点为其父结点的左结点，该结点的下一个结点为其父结点。
   - 该结点为其父结点的右结点，该结点的下一个结点为所在结点所在的左子树的根结点，即该结点为a，下一个结点为b，a位于b的左子树。

```c++
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == NULL) {
            return NULL;
        }

        TreeLinkNode *nextNode = NULL;
        // 如果当前结点有右子树, 那么其中序遍历的下一个结点就是其右子树的最左结点
        if (pNode->right != NULL) {
            // 找到右子树的最左孩子
            nextNode = pNode->right;
            while (nextNode->left != NULL) {
                nextNode = nextNode->left;
            }
        } else if (pNode->right == NULL && pNode->next != NULL) {
            TreeLinkNode *currentNode = pNode;
            TreeLinkNode *parentNode = pNode->next;

            /**
             * 如果当前结点是其父结点的左子结点那么其中序遍历的下一个结点就是他的父亲结点
             * 如果当前结点是其父结点的右子结点，
             * 这种情况下其下一个结点应该是当前结点所在的左子树的根
             * 因此我们可以顺着其父节点一直向上遍历,
             * 直到找到一个是它父结点的左子结点的结点
             */ 
            while (parentNode != NULL && parentNode->right == currentNode) {
                currentNode = parentNode;
                parentNode = parentNode->next;
            }
            nextNode = parentNode;
        }

        return nextNode;
    }
};
```

