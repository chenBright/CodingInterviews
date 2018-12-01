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

        ListNode *pAhead, *pBehind;
        pAhead = pBehind = pListHead;

        for (int i = 0; i < k - 1; ++i) { // 相当p2先取next，在递增i，所以i不需要等于k - 1
            if (pAhead->next != NULL) { 
                pAhead = pAhead->next;
            } else { // 链表长度小于k
                return NULL;
            }
        }

        while (pAhead->next != NULL) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }

        return pBehind;
    }
};