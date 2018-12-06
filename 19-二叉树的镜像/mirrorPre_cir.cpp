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

// 先序遍历 循环实现
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        stack<TreeNode *> nodeStack;   
        TreeNode *node = pRoot;     

        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                // 交换
                TreeNode *tempNode = node->left;
                node->left = node->right;
                node->right = tempNode;

                nodeStack.push(node);
                node= node->left; 
            } else { // 处理跟结点和右子树
                node = nodeStack.top();
                nodeStack.pop();

                node = node->right;
            }
        }
    }
};