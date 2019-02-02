#include <algorithm>
using namespace std;

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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int treeDepth = 0;
        return isBalanced(pRoot, &treeDepth);
    }

private:
    bool isBalanced(TreeNode *pRoot, int *treeDepth) {
        if (pRoot == NULL) {
            *treeDepth = 0;
            return true;
        }

        int leftTreeDepth, rightTreeDepth;
        if (isBalanced(pRoot->left, &leftTreeDepth) && isBalanced(pRoot->right, &rightTreeDepth)) {
            int diff = abs(leftTreeDepth - rightTreeDepth); // 计算左右子树深度差
            if (diff <= 1) {
                *treeDepth = max(leftTreeDepth, rightTreeDepth) + 1;
                return true;
            }
        }

        return false;
    }
};