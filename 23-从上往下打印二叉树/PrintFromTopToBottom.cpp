#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> nodesVal;

        if (root == NULL) {
            return nodesVal;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            nodesVal.push_back(node->val);

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        return nodesVal;
    }
};