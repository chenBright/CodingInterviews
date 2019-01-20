#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 中序遍历 递归实现
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