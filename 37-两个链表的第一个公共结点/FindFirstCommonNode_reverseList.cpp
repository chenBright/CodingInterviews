#include <iostream>
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
        int listLengthOf1 = getListLength(pHead1);
        int listLengthOf2 = getListLength(pHead2);

        ListNode *commonNode = NULL;
        if (listLengthOf1 > listLengthOf2) {
            commonNode = FindFirstCommonNode(pHead1, pHead2, listLengthOf1 - listLengthOf2);
        } else {
            commonNode = FindFirstCommonNode(pHead2, pHead1, listLengthOf2 - listLengthOf1);
        }

		return commonNode;
    }

private:
    // 计算链表长度
    int getListLength(ListNode *pHead) {
        int length = 0;
        while (pHead != NULL) {
            ++length;
            pHead = pHead->next;
        }

        return length;
    }
    // 长链表的结点指针先偏移offset单位，这样两个链表右对齐后，同步遍历比较两个链表的结点
    ListNode *FindFirstCommonNode(ListNode *longListHead, ListNode *shortListHead, int offset) {
        ListNode *node1 = longListHead;
        ListNode *node2 = shortListHead;

        for (int i = 0; i < offset; ++i) {
            node1 = node1->next;
        }

        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }

        return node1;
    }
};