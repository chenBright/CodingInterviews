#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

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