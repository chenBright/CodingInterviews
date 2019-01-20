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

// 后序遍历 递归实现实现
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