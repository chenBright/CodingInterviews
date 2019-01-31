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
        for (ListNode *node1 = pHead1; node1 != NULL; node1 = node1->next) {
			for (ListNode *node2 = pHead2; node2 != NULL; node2 = node2->next) {
				if (node1 == node2) {
					return node1;
				}
			}
		}

		return NULL;
    }
};