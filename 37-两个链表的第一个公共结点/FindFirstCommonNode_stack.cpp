#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> nodeStack1, nodeStack2;
        convertListToStack(pHead1, nodeStack1);
        convertListToStack(pHead2, nodeStack2);

        ListNode *commonNode = NULL; // 共同结点
        while (!nodeStack1.empty() && !nodeStack2.empty()) {
            if (nodeStack1.top() != nodeStack2.top()) {
                break;
            }

            commonNode = nodeStack1.top();
            nodeStack1.pop();
            nodeStack2.pop();
        }

        return commonNode;
    }

private:
    // 将链表转换成栈
    void convertListToStack(ListNode *pHead, stack<ListNode*> &nodeStack) {
        while (pHead != NULL) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
    }
};