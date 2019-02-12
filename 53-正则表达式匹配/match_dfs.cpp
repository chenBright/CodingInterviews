#include <string>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern) {
        // 正则pattern到底末尾时，如果串str也到达末尾，则匹配成功
        if (*pattern == '\0') {
            return !(*str);
        }

        int strLength = strlen(str);
        int patternLength = strlen(pattern);
        if (patternLength == 1 || *(pattern + 1) != '*') {
            return strLength && (pattern[0] == '.' || *str == *pattern) && match(str + 1, pattern + 1);
        } else {
            while (*str != '\0' && (*pattern == '.' || *str == *pattern)) {
                if (match(str++, pattern + 2)) {
                    return true;
                }
            }
        }

        return match(str, pattern + 2);
    }
};