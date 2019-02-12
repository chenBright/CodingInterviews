# 57-删除链表中重复的结点

## 题目

牛客OJ：[57-删除链表中重复的结点](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 思路

判断每个结点是否与后面的结点重复：

- 不重复，则加入到新链表。
- 重复，则不处理，即删除。

```c++
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
```

