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

// 中序遍历 循环实现
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
                nodeStack.push(node);
                node= node->left; 
            } else { // 处理跟结点和右子树
                node = nodeStack.top();
                // 交换
                TreeNode *tempNode = node->left;
                node->left = node->right;
                node->right = tempNode;
                
                nodeStack.pop();

                // 中序遍历处理根后，向右转向 node = node->right
                // 此时由于左右子树交换，原来的右子树是现在的左子树，所以向左转向
                node = node->left;
            }
        }
    }
};