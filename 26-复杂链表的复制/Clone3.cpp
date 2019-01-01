#include <vector>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        cloneNodes(pHead);
        connectRandomNodes(pHead);
        return reconectNodes(pHead);
    }

private:
    void cloneNodes(RandomListNode *pHead) {
        RandomListNode *node = pHead, *newNode = NULL;
        while (node != NULL) {
            newNode = new RandomListNode(node->label);

            // 将newNode插入到node后面
            newNode->next = node->next;
            node->next = newNode;

            node = newNode->next;
        }
    }

    void connectRandomNodes(RandomListNode *pHead) {
        RandomListNode *node = pHead, *newNode = NULL;
        while (node != NULL) {
            newNode = node->next;
            if (node->random != NULL) {
                newNode->random = node->random->next;
            }

            node = newNode->next;
        } 
    }

    RandomListNode *reconectNodes(RandomListNode *pHead) {
        RandomListNode *oldNode = pHead;
        RandomListNode *newHead = NULL, *newNode = NULL;

        // 如果pHead、oldNode为NULL，则pHead->next会报错
        if (pHead != NULL) {
            newHead = newNode = pHead->next;
        }

        while (oldNode != NULL) {
            oldNode->next = oldNode->next->next;
            if (newNode->next != NULL) {
                newNode->next = newNode->next->next;
            }

            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }
};