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
        ListNode *nodeOfCycle = findCycleNode(pHead);
        if (nodeOfCycle == NULL) {
            return NULL;
        }

        int length = getCycleLength(nodeOfCycle);
        ListNode *frontNode = pHead;
        ListNode *endNode = pHead;

        endNode = nextNode(endNode, length);
        while (frontNode != endNode) {
            frontNode = nextNode(frontNode, 1);
            endNode = nextNode(endNode, 1);
        }

        return frontNode;
    }

private:
    // 查找环内结点
    ListNode* findCycleNode(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *pSlow = pHead->next;
        ListNode *pFast = pSlow->next;

        while (pSlow != NULL && pFast != NULL) {
            if (pSlow == pFast) {
                return pSlow;
            }

            pSlow = nextNode(pSlow, 1);
            pFast = nextNode(pFast, 2);
        }

        return NULL;
    }
    // 下一结点
    ListNode* nextNode(ListNode* node, int step) {
        for (int i = 0; i < step && node != NULL; ++i) {
            node = node->next;
        }

        return node;
    }
    // 获取环结点数量
    int getCycleLength(ListNode* node) {
        int length = 0;
        if (node == NULL) {
            return length;
        }

        ListNode *moveNode = node->next;
        length = 1;
        while (moveNode != node) {
            moveNode = nextNode(moveNode, 1);
            ++length;
        }

        return length;
    }
};