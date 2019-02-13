#include <iostream>


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

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