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
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == NULL) {
            return true;
        }

        return isSymmetricalRecursion(pRoot->left, pRoot->right);
    }

private:
    bool isSymmetricalRecursion(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL) { // 两个结点都为NULL
            return true;
        } else if (leftNode == NULL || rightNode == NULL) { // （结合前面的条件）只有一个结点为NULL
            return false;
        } 

        // 两个结点都不为NULL
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return isSymmetricalRecursion(leftNode->left, rightNode->right) 
            && isSymmetricalRecursion(leftNode->right, rightNode->left);
     }

};