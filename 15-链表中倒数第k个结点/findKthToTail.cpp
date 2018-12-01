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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 空链表或k为0
        if (pListHead == NULL || k == 0) {
            return NULL;
        }

        ListNode *node = pListHead;
        int length = 0;

        while (node != NULL) {
            node = node->next;
            ++length;
        }

        // k大于链表长度
        if (k > length) {
            return NULL;
        }

        node = pListHead; // 第一个结点
        for (int i = 1; i <= length - k; ++i) {
            node = node->next;
        }

        return node;
    }
};