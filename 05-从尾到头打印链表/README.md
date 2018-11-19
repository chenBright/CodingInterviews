# 05-从尾到头打印链表

## 题目

牛客OJ：[05-从尾到头打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

《剑指offer》：`P51`

## 利用栈的后进先出特性

```c++
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> s;
        ListNode *node = head;
        while (node != NULL) {
            s.push(node->val);
            node = node->next;
        }

        while (!s.empty()) {
            int temp = s.top();
            result.push_back(temp);
            s.pop();
        }

        return result;
    }
};
```

## 递归实现

先往后递归，再打印该结点的值，即可模拟逆序打印链表了，这是树遍历的递归实现的技巧。

```c++
class Solution {
private:
    void visit(vector<int> &result, ListNode* node) {
        if (node == NULL) {
            return;
        }
        
        visit(result, node->next);
        result.push_back(node->val);
    } 

public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        visit(result, head);
        return result;
    }
};
```