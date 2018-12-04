# 17-合并两个排序的链表

## 题目

牛客OJ：[17-合并两个排序的链表](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P115`

## 思路

用两个指针同时遍历两个链表，取出最小的结点，插入到新链表中，而被取出结点的链表的指针指向下一个结点。

## 循环实现

```c++
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL) {
            return pHead2;
        } 
        if (pHead2 == NULL) {
            return pHead1;
        }

        ListNode *mergeListHead = NULL;
        ListNode *node1 = pHead1;
        ListNode *node2 = pHead2;

        // 找出做小结点做合并链表头结点
        if (node1->val <= node2->val) {
            mergeListHead = node1;
            node1 = node1->next;
        } else {
            mergeListHead = node2;
            node2 = node2->next;
        }

        ListNode *currentNode = mergeListHead;
        while (node1 != NULL && node2 != NULL) {
            if (node1->val <= node2->val) {
                currentNode->next = node1;
                currentNode = currentNode->next;
                node1 = node1->next;
            } else {
                currentNode->next = node2;
                currentNode = currentNode->next;
                node2 = node2->next;
            }
        }

        // 将没有遍历完的链表直接“接到”合并链表后面
        if (node1 != NULL) {
            currentNode->next = node1;
        } else {
            currentNode->next = node2;
        }

        return mergeListHead;
    }
};
```

## 递归实现

```c++
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL) {
            return pHead2;
        } 
        if (pHead2 == NULL) {
            return pHead1;
        }

        ListNode *mergeListHead = NULL;
        ListNode *node1 = pHead1;
        ListNode *node2 = pHead2;

        // 找出做小结点做合并链表头结点
        if (node1->val <= node2->val) {
            mergeListHead = node1;
            node1 = node1->next;
        } else {
            mergeListHead = node2;
            node2 = node2->next;
        }
        // 递归合并
        mergeListHead->next = Merge(node1, node2);

        return mergeListHead;
    }
};
```

