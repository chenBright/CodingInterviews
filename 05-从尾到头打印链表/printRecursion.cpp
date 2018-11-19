#include <vector>
using namespace std;

// 结点数据结构
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {}
};

class Solution {
private:
    void visit(vector<int> &result, ListNode* node) {
        if (node == NULL) {
            return;
        }
        
        visit(result, node->next);
        result.push_back(node->val);
    } 

public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        visit(result, head);
        return result;
    }
};