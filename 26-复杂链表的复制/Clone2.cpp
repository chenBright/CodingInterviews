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
        RandomListNode *newHead = NULL, *newNode = NULL, *preNode = NULL;
        RandomListNode *node = pHead;
        map<RandomListNode *, RandomListNode *> nodeMap; // 旧链表结点 - 新链表结点 Map

        //  首先复制原链表的普通指针域, 一次遍历即可完成
        while (node != NULL) {
            newNode = new RandomListNode(node->label);
            if (preNode == NULL) {
                newHead = newNode;
            } else {
                preNode->next = newNode;
            }

            nodeMap[node] = newNode; // <node, newNode>

            // 移动指针
            preNode = newNode;
            node = node->next;
        }

        node = pHead;
        newNode = newHead;
        // 复制特殊指针域
        while (node != NULL && newNode != NULL) {
            if (node->random != NULL) {
                // 从nodeMap中找出random结点
                newNode->random = nodeMap[node->random];
            }

            newNode = newNode->next;
            node = node->next;
        }

        return newHead;
    }
};