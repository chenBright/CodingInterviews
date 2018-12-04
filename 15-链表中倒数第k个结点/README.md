# 15-链表中倒数第k个结点

## 题目

牛客OJ：[15-链表中倒数第k个结点](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P108`

## 遍历两次链表

1. 第一次遍历链表，计算链表长度n。
2. 第二次找到倒数第k个结点，即第**n-k+1**个结点。

还有需要注意的问题：

- 链表为空。
- k为0。
- k大于链表长度。

这些都是异常情况，返回**NULL**。

```c++

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 空链表或k为0
        if (pListHead == NULL || k == 0) {
            return NULL;
        }

        ListNode *node = pListHead;
        int length = 0;

        while (node != NULL) {
            node = node->next;
            ++length;
        }

        // k大于链表长度
        if (k > length) {
            return NULL;
        }

        node = pListHead; // 第一个结点
        for (int i = 1; i <= length - k; ++i) {
            node = node->next;
        }

        return node;
    }
```

## 遍历一次链表

通过观察，可以发现，倒数第k个结点跟链表的最后一个结点的距离为**k-1**。所以，可以用两个指针，只需要便利一次就可以找到倒数第k个结点。

1. 第一个指针先走k-1步，这样第一个指针和第二个指针的距离就是k-1了。
2. 然后两个指针一起走，知道第一个指针位于链表的最后一个结点的位置。这时候，第二个指针指向的就是倒数第k个结点了。

```c++
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 空链表或k为0
        if (pListHead == NULL || k == 0) {
            return NULL;
        }

        ListNode *pAhead, *pBehind;
        pAhead = pBehind = pListHead;

        for (int i = 0; i < k - 1; ++i) { // 相当p2先取next，在递增i，所以i不需要等于k - 1
            if (pAhead->next != NULL) { 
                pAhead = pAhead->next;
            } else { // 链表长度小于k
                return NULL;
            }
        }

        while (pAhead->next != NULL) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }

        return pBehind;
    }
};
```

两种方法的时间复杂度都是**O(n)**。