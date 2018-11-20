#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //  前序遍历的长度跟中序遍历的长度应该相同
        if(pre.size( ) != vin.size( )) {
            return NULL;
        }

        // 长度不能为0
        int length = pre.size( );
        if(length == 0) {
            return NULL;
        }

        // 前序遍历序列的第一个元素为书的根结点
        int val = pre[0];
        TreeNode* root = new TreeNode(val);

        // 在中序遍历序列中查找根结点
        int rootIndex = 0;
        for (; rootIndex < length; ++rootIndex) {
            if (vin[rootIndex] == val) {
                break;
            }
        }

        // 没有找到根结点
        if (rootIndex >= length) {
            return NULL;
        }

        vector<int> preLeft, preRight, vinLeft, vinRight;
        for (int i = 0; i < length; ++i) {
            if (i < rootIndex) {
                preLeft.push_back(pre[i + 1]);
                vinLeft.push_back(vin[i]);
            } else if (i > rootIndex) {
                preRight.push_back(pre[i]);
                vinRight.push_back(vin[i]);
            }
        }

        root->left = reConstructBinaryTree(preLeft, vinLeft);
        root->right = reConstructBinaryTree(preRight, vinRight);

        return root;
    }
};