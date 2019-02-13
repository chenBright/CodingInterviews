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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res; // 结果

        if (pRoot == NULL) {
            return res;
        }

        vector<TreeNode*> vNode; // 保存结点
        vector<int> vInt; // 保存结点的值

        vNode.push_back(pRoot);
        vInt.push_back(pRoot->val);
        res.push_back(vInt);

        while (!vNode.empty()) {
            printLine(vNode, vInt);

            if (!vInt.empty()) {
                res.push_back(vInt);
            }
        }

        return res;
    }

private:
    // 从左开始打印
    void printLine(vector<TreeNode*> &vNode, vector<int> &vInt) {
        vInt.clear();

        vector<TreeNode*> temp;
        for (vector<TreeNode*>::iterator it = vNode.begin(); it != vNode.end(); ++it) {
            if ((*it)->left != NULL) {
                temp.push_back((*it)->left);
                vInt.push_back((*it)->left->val);
            }

            if ((*it)->right != NULL) {
                temp.push_back((*it)->right);
                vInt.push_back((*it)->right->val);
            }
        }
        vNode.clear();
        if (!temp.empty()) {
            vNode.assign(temp.begin(), temp.end());
        }
    }
};