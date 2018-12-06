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

// 后序遍历 循环实现
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }

        stack<TreeNode *> nodeStack;   
        TreeNode *node = pRoot;   
        TreeNode *lastNode = NULL; // 上一个处理过的结点

        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                nodeStack.push(node);
                node= node->left; 
            } else { // 处理右子树
                node = nodeStack.top();
                if (node->right != NULL && node->right != lastNode) { // 右子树不为空且没有处理
                    node = node->right;
                } else { // 处理根结点
                    TreeNode *tempNode = node->left;
                    node->left = node->right;
                    node->right = tempNode;


                    lastNode = node; // 标记
                    node = NULL; // 该树已处理完，将node设为NULL，则下一循环会处理栈中的结点
                    nodeStack.pop();
                }
            }
        }
    }
};