# 42-左旋转字符串

## 题目

牛客OJ：[42-左旋转字符串](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)


《剑指offer》：`P220`

## 直接找到旋转后的对应关系

我们可以很明显的发现，将一个字符串循环左移，那么新串和原来串位的对应关系就如下

- 新串i位置的元素，其实是原来串i+n位置的元素。
- 当然i+n如果超过了字符串的长度，就会被循环移位到左侧，即***(i+n) % str.size()***。
- 另外，如果移位n超过了字符串长度，那么只需要移动***n%str.size()***位即可。

```c++
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }

        string res(str);
        int strLength = str.size();
        if (n > strLength) {
            n %= strLength;
        }

        for (int i = 0; i < strLength; ++i) {
            res[i] = str[(n + i) % strLength];
        }

        return res;
    }
};
```

## 新字符串是str+str串第n位到底n+str.size()的字串

例如str为***abcdefg***，n为***3***，则str+str为***abcdefgabcdefg***，新字符串是第***3***位到***3+字符串长度***的子串。

```c++
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }
        int strLength = str.size();
        n = n % strLength;
        str += str;

        return str.substr(n, strLength);
    }
};
```

## 使用翻转实现

通过三次翻转实现：

1. reverse(0, n);
2. reverse(i, str.size() - 1);
3. reverse(1, str.size() - 1);

例如str为***abcdefg***，n为***3***：

1. abc defg -=> cba defg
2. cba defg -=> cba gfed
3. `cba gfed -=> defg abc`

```c++
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }
        int strLength = str.size();
        n = n % strLength;
        
        Reverse(str, 0, n - 1);
        Reverse(str, n, strLength - 1);
        Reverse(str, 0, strLength - 1);

        return str;
    }

private:
    void Reverse(string &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
};
```

