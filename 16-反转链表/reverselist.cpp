#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 头插法实现链表反转
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *node = pHead->next;
        ListNode *reverseListHead = pHead;
        reverseListHead->next = NULL;
        ListNode *tempNode;
        while (node != NULL) {
            tempNode = node; // 取出结点
            node = node->next; // node向后移动
            // 在链表头结点前插入结点
            tempNode->next = reverseListHead;
            reverseListHead = tempNode;
        }

        return reverseListHead;
    }
};