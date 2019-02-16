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

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k <= 0) {
            return NULL;
        }

        stack<TreeNode*> nodeStack;
        nodeStack.push(pRoot);
        unsigned int count = 1;
        TreeNode *node = pRoot;

        while (!nodeStack.empty() || node != NULL) {
            if (node->left != NULL) {
                nodeStack.push(node->left);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                if (count == k) {
                    return node;
                }
                ++count;

                node = node->right;
            }
        }

        return NULL;
    }
};