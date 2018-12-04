#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL) {
            return pHead2;
        } 
        if (pHead2 == NULL) {
            return pHead1;
        }

        ListNode *mergeListHead = NULL;
        ListNode *node1 = pHead1;
        ListNode *node2 = pHead2;

        // 找出做小结点做合并链表头结点
        if (node1->val <= node2->val) {
            mergeListHead = node1;
            node1 = node1->next;
        } else {
            mergeListHead = node2;
            node2 = node2->next;
        }
        // 递归合并
        mergeListHead->next = Merge(node1, node2);

        return mergeListHead;
    }
};