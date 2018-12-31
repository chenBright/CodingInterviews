#include <vector>
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
        RandomListNode *newHead = NULL, *newNode = NULL, *preNode = NULL;
        RandomListNode *node = pHead;

        //  首先复制原链表的普通指针域, 一次遍历即可完成
        while (node != NULL) {
            newNode = new RandomListNode(node->label);
            if (preNode == NULL) {
                newHead = newNode;
            } else {
                preNode->next = newNode;
            }
            // 移动指针
            preNode = newNode;
            node = node->next;
        }

        node = pHead;
        newNode = newHead;
        // 复制特殊指针域
        while (node != NULL && newNode != NULL) {
            if (node->random != NULL) {
                newNode->random = findInNewList(newHead, pHead, node->random);
            }

            // 移动指针
            newNode = newNode->next;
            node = node->next;
        }

        return newHead;
    }

private:
    // 找出新链表中对应的特殊指针域
    RandomListNode *findInNewList(RandomListNode *newHead, RandomListNode *oldHead, RandomListNode *randNode) {
        RandomListNode *newNode = newHead;
        RandomListNode *oldNode = oldHead;
        while (newNode != NULL && oldHead != NULL) {
            if (oldNode == randNode) {
                return newNode;
            }
            // 移动指针
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        return NULL;
    }
};