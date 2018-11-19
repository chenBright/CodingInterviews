#include <vector>
#include <stack>
using namespace std;

// 结点数据结构
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> s;
        ListNode *node = head;
        while (node != NULL) {
            s.push(node->val);
            node = node->next;
        }

        while (!s.empty()) {
            int temp = s.top();
            result.push_back(temp);
            s.pop();
        }

        return result;
    }
};