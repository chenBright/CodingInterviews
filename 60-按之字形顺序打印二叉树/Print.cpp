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

        bool isLeft = true; // 从左开始打印
        vector<TreeNode*> vNode; // 保存结点
        vector<int> vInt; // 保存结点的值

        vNode.push_back(pRoot);
        vInt.push_back(pRoot->val);
        res.push_back(vInt);
        isLeft = !isLeft; // 从右开始打印

        while (!vNode.empty()) {
            if (isLeft) {
                printFromLeft(vNode, vInt);
            } else {
                printFromRight(vNode, vInt);
            }
            isLeft = !isLeft;

            if (!vInt.empty()) {
                res.push_back(vInt);
            }
        }

        return res;
    }

private:
    // 从左开始打印
    void printFromLeft(vector<TreeNode*> &vNode, vector<int> &vInt) {
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

    // 从右开始打印
    void printFromRight(vector<TreeNode*> &vNode, vector<int> &vInt) {
        vInt.clear();

        vector<TreeNode*> temp;
        for (vector<TreeNode*>::reverse_iterator it = vNode.rbegin(); it != vNode.rend(); ++it) {
            if ((*it)->right != NULL) {
                temp.push_back((*it)->right);
                vInt.push_back((*it)->right->val);
            }

            if ((*it)->left != NULL) {
                temp.push_back((*it)->left);
                vInt.push_back((*it)->left->val);
            }
        }
        vNode.clear();
        if (!temp.empty()) {
            vNode.assign(temp.rbegin(), temp.rend()); // 前面遍历将结点变成逆序，现在将结点顺序变回原来的顺序
        }
    }
};