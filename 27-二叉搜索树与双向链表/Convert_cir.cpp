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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        stack<TreeNode *> s;
		TreeNode *node = pRootOfTree;
		TreeNode *linkedList = NULL;
		TreeNode *lastNode = NULL;

		while (!s.empty() || node != NULL) {
			if (node != NULL) {
				s.push(node);
				node = node->left;
			} else {
				node = s.top();
				s.pop();

				// 将该结点转换为链表上的结点
				if (lastNode == NULL) { // 链表头结点
					linkedList = lastNode = node;
					linkedList->left = NULL;
				} else { // 其他结点
					lastNode->right = node;
					node->left = lastNode;
					lastNode = node;
				}

				node = node->right;
			}
		}

		return linkedList;
    }
};