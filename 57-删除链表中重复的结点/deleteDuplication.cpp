#include <vector>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *newList = new ListNode(-1); // 新链表头结点，使后面所有结点的处理一致
        ListNode *newNode = newList;
        ListNode *node = pHead;
        ListNode *duplicatedNode = NULL;

        while (node != NULL && node->next != NULL) {
            duplicatedNode = node->next;
            // 遍历到值不相等的结点为止
            while (duplicatedNode != NULL && duplicatedNode->val == node->val) {
                duplicatedNode = duplicatedNode->next;
            }
            
            // duplicatedNode为node的下一个结点，表示相邻的结点的值不相等
            if (duplicatedNode == node->next) {
                newNode->next = node;
                newNode = newNode->next;
            }
            node = duplicatedNode;
        }
        newNode->next = NULL;

        return newList->next;
    }
};