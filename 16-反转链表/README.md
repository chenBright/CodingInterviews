# 16-反转链表

## 题目

牛客OJ：[16-反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P112`

## 头插法

**头插法**，每次插入结点的时候都是插入到链表的“头”，即插入的结点变成头结点，而第一个插入的结点变成了尾结点。

遍历输入链表，每次都将结点“摘下来”，再使用头插法新建一个链表。那么，新链表元素的顺序与输入链表元素的顺序正好相反。

```c++
// 头插法实现链表反转
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *node = pHead->next;
        ListNode *reverseListHead = pHead;
        reverseListHead->next = NULL;
        ListNode *tempNode;
        while (node != NULL) {
            tempNode = node; // 取出结点
            node = node->next; // node向后移动
            // 在链表头结点前插入结点
            tempNode->next = reverseListHead;
            reverseListHead = tempNode;
        }

        return reverseListHead;
    }
};
```

## 三指针滑动 preNode -> node -> nextNode

单指针滑动的问题是，将当前结点反转后，“断链了”，找不到写一个结点了。为了解决这个问题，可以加多两个指针来保存当前结点的前后结点，这样就不会“断链”了。

```c++
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *reverseListHead = NULL; // 反转链表的头结点
        ListNode *node = pHead; // 遍历结点
        ListNode *preNode = NULL; // 遍历结点的前一个结点

        while (node != NULL) {
            ListNode *nextNode = node->next; // 遍历结点的后一个结点

            // 遍历到链表尾结点，即为反转链表的头结点
            if (nextNode == NULL) {
                reverseListHead = node;
            }
            // 反转链表
            node->next = preNode;

            // 移动指针
            preNode = node;
            node = nextNode;
        }

        return reverseListHead;
    }
};
```

