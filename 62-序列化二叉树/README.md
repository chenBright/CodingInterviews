# 62-序列化二叉树

## 题目

牛客OJ：[62-序列化二叉树](https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 代码

```c++
class Solution {
public:
    vector<int> buf;
    void dfs1(TreeNode *root) {
        if(!root) buf.push_back(0xFFFFFFFF);
        else {
            buf.push_back(root->val);
            dfs1(root->left);
            dfs1(root->right);
        }
    }
    TreeNode* dfs2(int* &p) {
        if(*p==0xFFFFFFFF) {
            p++;
            return NULL;
        }
        TreeNode* res=new TreeNode(*p);
        p++;
        res->left=dfs2(p);
        res->right=dfs2(p);
        return res;
    }
    char* Serialize(TreeNode *root) {
        buf.clear();
        dfs1(root);
        int bufSize=buf.size();
        int *res=new int[bufSize];
        for(int i = 0; i < bufSize; ++i) {
            res[i]=buf[i];
        }
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p=(int*)str;
        return dfs2(p);
    }
};
```

