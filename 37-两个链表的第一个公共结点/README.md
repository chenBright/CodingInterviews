# 37-两个链表的第一个公共结点

## 题目

牛客OJ：[37-两个链表的第一个公共结点](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)


《剑指offer》：`P193`

## 暴力破解

该方法的时间复杂度为**O(nm)**。

```c++
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        for (ListNode *node1 = pHead1; node1 != NULL; node1 = node1->next) {
			for (ListNode *node2 = pHead2; node2 != NULL; node2 = node2->next) {
				if (node1 == node2) {
					return node1;
				}
			}
		}

		return NULL;
    }
};
```

## 右对齐两个链表

如果两个链表的长度相等，则我们可以同步遍历这两个链表，找到公共节点。

现在**有两个链表，我们可以先计算两个链表的长度差n，然后长链表的结点指针先偏移offset单位，这样两个链表右对齐后，同步遍历计较两个链表的结点**。

该方法的时间复杂度为**O(n+m)**。

```c++
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int listLengthOf1 = getListLength(pHead1);
        int listLengthOf2 = getListLength(pHead2);

        ListNode *commonNode = NULL;
        if (listLengthOf1 > listLengthOf2) {
            commonNode = FindFirstCommonNode(pHead1, pHead2, listLengthOf1 - listLengthOf2);
        } else {
            commonNode = FindFirstCommonNode(pHead2, pHead1, listLengthOf2 - listLengthOf1);
        }

		return commonNode;
    }

private:
    // 计算链表长度
    int getListLength(ListNode *pHead) {
        int length = 0;
        while (pHead != NULL) {
            ++length;
            pHead = pHead->next;
        }

        return length;
    }
    // 长链表的结点指针先偏移offset单位，这样两个链表右对齐后，同步遍历比较两个链表的结点
    ListNode *FindFirstCommonNode(ListNode *longListHead, ListNode *shortListHead, int offset) {
        ListNode *node1 = longListHead;
        ListNode *node2 = shortListHead;

        for (int i = 0; i < offset; ++i) {
            node1 = node1->next;
        }

        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }

        return node1;
    }
};
```

## 使用栈实现右对齐两个链表

使用栈实现右对齐两个链表后，从链表尾开始遍历比较两个链表的结点，找到“最后一个共同结点”，即原链表的第一个共同结点。

该方法的时间复杂度为**O(n+m)**。

```c++
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> nodeStack1, nodeStack2;
        convertListToStack(pHead1, nodeStack1);
        convertListToStack(pHead2, nodeStack2);

        ListNode *commonNode = NULL; // 共同结点
        while (!nodeStack1.empty() && !nodeStack2.empty()) {
            if (nodeStack1.top() != nodeStack2.top()) {
                break;
            }

            commonNode = nodeStack1.top();
            nodeStack1.pop();
            nodeStack2.pop();
        }

        return commonNode;
    }

private:
    // 将链表转换成栈
    void convertListToStack(ListNode *pHead, stack<ListNode*> &nodeStack) {
        while (pHead != NULL) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
    }
};
```

## 使用unordered_map记录一个链表的结点

使用unordered_map记录一个链表的结点，然后遍历另一个链表，查找该链表的结点是否在unordered_map中，第一个在unordered_map中的结点即为第一个共同结点。

该方法的时间复杂度为**O(n+m)**，但查找操作的时间复杂度为**O(1)**。

```c++
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_map<ListNode*, int> nodeMap;

        while (pHead1 != NULL) {
            nodeMap.insert(make_pair(pHead1, 1));
            pHead1 = pHead1->next;
        }

        while (pHead2 != NULL) {
            if (nodeMap.count(pHead2)) {
                return pHead2;
            }
            pHead2 = pHead2->next;
        }

        return NULL;
    }
};
```

