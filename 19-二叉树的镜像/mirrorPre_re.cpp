#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 先序遍历 递归实现
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