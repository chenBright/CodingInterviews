#include <vector>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return NULL;
        }

        ListNode *previous = pHead;
        ListNode *current = pHead->next;
        while (current != NULL) {
            previous->next = NULL;
            previous = current;
            current = current->next;
        }

        return previous;
    }
};