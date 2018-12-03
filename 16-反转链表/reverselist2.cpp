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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *reverseListHead = NULL; // 反转链表的头结点
        ListNode *node = pHead; // 遍历结点
        ListNode *preNode = NULL; // 遍历结点的前一个结点

        while (node != NULL) {
            ListNode *nextNode = node->next; // 遍历结点的后一个结点

            // 遍历到链表尾结点，即为反转链表的头结点
            if (nextNode == NULL) {
                reverseListHead = node;
            }
            // 反转链表
            node->next = preNode;

            // 移动指针
            preNode = node;
            node = nextNode;
        }

        return reverseListHead;
    }
};