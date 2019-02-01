#include <unordered_map>
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
        unordered_map<ListNode*, int> nodeMap;

        while (pHead1 != NULL) {
            nodeMap.insert(make_pair(pHead1, 1));
            pHead1 = pHead1->next;
        }

        while (pHead2 != NULL) {
            if (nodeMap.count(pHead2)) {
                return pHead2;
            }
            pHead2 = pHead2->next;
        }

        return NULL;
    }
};