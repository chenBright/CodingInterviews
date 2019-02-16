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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL) {
            return NULL;
        }

        TreeNode *res = NULL;
        if ((res = KthNode(pRoot->left, k)) != NULL) {
            return res;
        }

        if (count == k) {
            return pRoot;
        }
        ++count;

        if ((res = KthNode(pRoot->right, k)) != NULL) {
            return res;
        }

        return NULL;
    }

private:
    unsigned int count = 1;
};