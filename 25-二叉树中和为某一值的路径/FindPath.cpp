#include <vector>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL || expectNumber == 0) {
            return v;
        }

        vector<int> nodes;
        FindPath(root, expectNumber, nodes);
        return v;
    }

private:
    vector<vector<int> > v;
    void FindPath(TreeNode *node, int expectNumber, vector<int> nodes) {
        // 结点为叶子结点，从根结点到该结点的和等于expectNumber，符合要求
        if (node->val == expectNumber || (node->left == NULL && node->right == NULL)) { 
            nodes.push_back(node->val);
            v.push_back(nodes);
        } else if (node->val < expectNumber) { // 不是叶子结点且和小于expectNumber，继续往下递归遍历
            nodes.push_back(node->val);
            expectNumber -= node->val; // 减
            if (node->left !=  NULL) {
                FindPath(node->left, expectNumber, nodes);
            }
            if (node->right != NULL) {
                FindPath(node->right, expectNumber, nodes);
            }
        }

    }
};