#include <stack>
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